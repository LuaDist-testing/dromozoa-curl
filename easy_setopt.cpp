// Copyright (C) 2017,2018 Tomoyuki Fujimori <moyu@dromozoa.com>
//
// This file is part of dromozoa-curl.
//
// dromozoa-curl is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// dromozoa-curl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dromozoa-curl.  If not, see <http://www.gnu.org/licenses/>.

#include <stddef.h>
#include <stdio.h>
#include <string.h>

#include "common.hpp"
#include "symbols.hpp"

namespace dromozoa {
  namespace {
    size_t read_callback(char* buffer, size_t size, size_t nmemb, void* userdata) {
      size_t n = size * nmemb;
      luaX_reference<>* ref = static_cast<luaX_reference<>*>(userdata);
      lua_State* L = ref->state();
      size_t result = CURL_READFUNC_ABORT;
      int top = lua_gettop(L);
      {
        ref->get_field(L);
        luaX_push(L, n);
        int r = lua_pcall(L, 1, 1, 0);
        if (r == 0) {
          if (luaX_is_integer(L, -1)) {
            result = lua_tointeger(L, -1);
          } else if (const char* ptr = lua_tolstring(L, -1, &result)) {
            if (result <= n) {
              memcpy(buffer, ptr, result);
            } else {
              result = CURL_READFUNC_ABORT;
            }
          } else {
            result = 0;
          }
        } else {
          DROMOZOA_UNEXPECTED(lua_tostring(L, -1));
        }
      }
      lua_settop(L, top);
      return result;
    }

    size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
      size_t n = size * nmemb;
      luaX_reference<>* ref = static_cast<luaX_reference<>*>(userdata);
      lua_State* L = ref->state();
      size_t result = 0;
      int top = lua_gettop(L);
      {
        ref->get_field(L);
        lua_pushlstring(L, ptr, n);
        int r = lua_pcall(L, 1, 1, 0);
        if (r == 0) {
          if (luaX_is_integer(L, -1)) {
            result = lua_tointeger(L, -1);
          } else {
            result = n;
          }
        } else {
          DROMOZOA_UNEXPECTED(lua_tostring(L, -1));
        }
        lua_settop(L, top);
      }
      return result;
    }
  }

  class easy_handle_impl {
  public:
    static CURLcode setopt_string(easy_handle* self, lua_State* L, CURLoption option) {
      if (lua_isnoneornil(L, 3)) {
        return curl_easy_setopt(self->get(), option, 0);
      } else {
        return curl_easy_setopt(self->get(), option, luaL_checkstring(L, 3));
      }
    }

    static CURLcode setopt_string(easy_handle* self, lua_State* L, CURLoption option, CURLoption option_length) {
      if (lua_isnoneornil(L, 3)) {
        return curl_easy_setopt(self->get(), option, 0);
      } else {
        size_t length = 0;
        CURLcode result = curl_easy_setopt(self->get(), option, luaL_checklstring(L, 3, &length));
        if (result == CURLE_OK) {
          result = curl_easy_setopt(self->get(), option_length, static_cast<curl_off_t>(length));
        }
        return result;
      }
    }

    static CURLcode setopt_string_ref(easy_handle* self, lua_State* L, CURLoption option, CURLoption option_length) {
      if (lua_isnoneornil(L, 3)) {
        CURLcode result = curl_easy_setopt(self->get(), option, 0);
        if (result == CURLE_OK) {
          self->delete_reference(option);
        }
        return result;
      } else {
        size_t length = 0;
        const char* ptr = luaL_checklstring(L, 3, &length);
        self->new_reference(option, L, 3);
        CURLcode result = curl_easy_setopt(self->get(), option, ptr);
        if (result == CURLE_OK) {
          result = curl_easy_setopt(self->get(), option_length, static_cast<curl_off_t>(length));
        }
        return result;
      }
    }

    template <class T>
    static CURLcode setopt_integer(easy_handle* self, lua_State* L, CURLoption option) {
      return curl_easy_setopt(self->get(), option, luaX_check_integer<T>(L, 3));
    }

    template <class T>
    static CURLcode setopt_function_ref(easy_handle* self, lua_State* L, CURLoption option, CURLoption option_data, const T& callback, void* default_data) {
      if (lua_isnoneornil(L, 3)) {
        CURLcode result = curl_easy_setopt(self->get(), option, 0);
        if (result == CURLE_OK) {
          result = curl_easy_setopt(self->get(), option_data, default_data);
          if (result == CURLE_OK) {
            self->delete_reference(option);
          }
        }
        return result;
      } else {
        CURLcode result = curl_easy_setopt(self->get(), option, callback);
        if (result == CURLE_OK) {
          luaX_reference<>* ref = self->new_reference(option, L, 3);
          result = curl_easy_setopt(self->get(), option_data, ref);
        }
        return result;
      }
    }

    static CURLcode setopt_slist(easy_handle* self, lua_State* L, CURLoption option) {
      if (!lua_isnoneornil(L, 3)) {
        luaL_checktype(L, 3, LUA_TTABLE);
        string_list list(L, 3);
        if (struct curl_slist* slist = list.get()) {
          self->save_slist(option, slist);
          list.release();
          return curl_easy_setopt(self->get(), option, slist);
        }
      }
      CURLcode result = curl_easy_setopt(self->get(), option, 0);
      if (result == CURLE_OK) {
        self->free_slist(option);
      }
      return result;
    }

    static CURLcode setopt_httppost_ref(easy_handle* self, lua_State* L, CURLoption option) {
      if (lua_isnoneornil(L, 3)) {
        CURLcode result = curl_easy_setopt(self->get(), option, 0);
        if (result == CURLE_OK) {
          self->delete_reference(option);
          result = curl_easy_setopt(self->get(), CURLOPT_READFUNCTION, 0);
        }
        return result;
      } else {
        httppost_handle* form = check_httppost_handle(L, 3);
        self->new_reference(option, L, 3);
        CURLcode result = curl_easy_setopt(self->get(), option, form->get());
        if (result == CURLE_OK && form->stream() > 0) {
          result = curl_easy_setopt(self->get(), CURLOPT_READFUNCTION, read_callback);
        }
        return result;
      }
    }
  };

  namespace {
    void impl_setopt(lua_State* L) {
      easy_handle* self = check_easy_handle(L, 1);
      CURLoption option = luaX_check_enum<CURLoption>(L, 2);
      CURLcode result = CURLE_UNKNOWN_OPTION;

      switch (easy_setopt_param(option)) {
        case easy_setopt_param_char_p:
          switch (option) {
            case CURLOPT_COPYPOSTFIELDS:
              result = easy_handle_impl::setopt_string(self, L, option, CURLOPT_POSTFIELDSIZE_LARGE);
              break;
            case CURLOPT_POSTFIELDS:
              result = easy_handle_impl::setopt_string_ref(self, L, option, CURLOPT_POSTFIELDSIZE_LARGE);
              break;
            default:
              result = easy_handle_impl::setopt_string(self, L, option);
          }
          break;

        case easy_setopt_param_long:
          result = easy_handle_impl::setopt_integer<long>(self, L, option);
          break;
        case easy_setopt_param_curl_off_t:
          result = easy_handle_impl::setopt_integer<curl_off_t>(self, L, option);
          break;

        case easy_setopt_param_callback:
          switch (option) {
            case CURLOPT_READFUNCTION:
              result = easy_handle_impl::setopt_function_ref(self, L, option, CURLOPT_READDATA, read_callback, stdin);
              break;
            case CURLOPT_HEADERFUNCTION:
              result = easy_handle_impl::setopt_function_ref(self, L, option, CURLOPT_HEADERDATA, write_callback, 0);
              break;
            case CURLOPT_WRITEFUNCTION:
              result = easy_handle_impl::setopt_function_ref(self, L, option, CURLOPT_WRITEDATA, write_callback, stdout);
              break;
            default:
              result = CURLE_UNKNOWN_OPTION;
          }
          break;

        case easy_setopt_param_struct_curl_slist_p:
          result = easy_handle_impl::setopt_slist(self, L, option);
          break;

        case easy_setopt_param_struct_curl_httppost_p:
          result = easy_handle_impl::setopt_httppost_ref(self, L, option);
          break;

        default:
          result = CURLE_UNKNOWN_OPTION;
      }

      if (result == CURLE_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }
  }

  void initialize_easy_setopt(lua_State* L) {
    luaX_set_field(L, -1, "setopt", impl_setopt);
  }
}
