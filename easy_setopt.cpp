// Copyright (C) 2017 Tomoyuki Fujimori <moyu@dromozoa.com>
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

#include <string.h>

#include "common.hpp"
#include "symbols.hpp"

namespace dromozoa {
  namespace {
    size_t read_callback(char* buffer, size_t size, size_t nmemb, void* userdata) {
      size_t n = size * nmemb;
      luaX_reference* ref = static_cast<luaX_reference*>(userdata);
      lua_State* L = ref->state();
      int top = lua_gettop(L);
      ref->get_field();
      luaX_push(L, n);
      size_t result = CURLE_ABORTED_BY_CALLBACK;
      int r = lua_pcall(L, 1, 1, 0);
      if (r == 0) {
        if (const char* data = lua_tolstring(L, -1, &result)) {
          if (result <= n) {
            memcpy(buffer, data, result);
          } else {
            result = CURLE_ABORTED_BY_CALLBACK;
          }
        } else {
          result = 0;
        }
      } else {
        DROMOZOA_UNEXPECTED(lua_tostring(L, -1));
      }
      lua_settop(L, top);
      return result;
    }

    size_t write_callback(char* ptr, size_t size, size_t nmemb, void* userdata) {
      size_t n = size * nmemb;
      luaX_reference* ref = static_cast<luaX_reference*>(userdata);
      lua_State* L = ref->state();
      int top = lua_gettop(L);
      ref->get_field();
      lua_pushlstring(L, ptr, n);
      size_t result = 0;
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
      return result;
    }

    void setopt_string(lua_State* L, CURLoption option) {
      CURLcode result = curl_easy_setopt(check_easy(L, 1), option, luaL_checkstring(L, 3));
      if (result == CURLE_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }

    template <class T>
    void setopt_integer(lua_State* L, CURLoption option) {
      CURLcode result = curl_easy_setopt(check_easy(L, 1), option, luaX_check_integer<T>(L, 3));
      if (result == CURLE_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }

    void setopt_httppost(lua_State* L, CURLoption option) {
      easy_handle* self = check_easy_handle(L, 1);
      lua_pushvalue(L, 3);
      self->new_reference(option, L);
      httppost_handle* that = check_httppost_handle(L, 3);
      CURLcode result = curl_easy_setopt(self->get(), option, that->get());
      if (result == CURLE_OK) {
        if (that->have_stream()) {
          result = curl_easy_setopt(self->get(), CURLOPT_READFUNCTION, read_callback);
          if (result == CURLE_OK) {
            luaX_push_success(L);
          } else {
            push_error(L, result);
          }
        } else {
          luaX_push_success(L);
        }
      } else {
        push_error(L, result);
      }
    }

    void setopt_slist(lua_State* L, CURLoption option) {
      string_list list(L, 3);
      if (list.get()) {
        easy_handle* self = check_easy_handle(L, 1);
        self->save_slist(option, list.get());
        CURLcode result = curl_easy_setopt(self->get(), option, list.release());
        if (result == CURLE_OK) {
          luaX_push_success(L);
        } else {
          push_error(L, result);
        }
      } else {
        push_error(L, CURLE_UNKNOWN_OPTION);
      }
    }

    template <class T>
    void setopt_function(lua_State* L, CURLoption option, CURLoption option_data, const T& callback) {
      easy_handle* self = check_easy_handle(L, 1);
      lua_pushvalue(L, 3);
      luaX_reference* ref = self->new_reference(option, L);
      CURLcode result = curl_easy_setopt(self->get(), option, callback);
      if (result == CURLE_OK) {
        result = curl_easy_setopt(self->get(), option_data, ref);
        if (result == CURLE_OK) {
          luaX_push_success(L);
        } else {
          push_error(L, result);
        }
      } else {
        push_error(L, result);
      }
    }

    void impl_setopt(lua_State* L) {
      CURLoption option = luaX_check_enum<CURLoption>(L, 2);
      switch (easy_setopt_param(option)) {
        case easy_setopt_param_char_p:
          switch (option) {
            case CURLOPT_POSTFIELDS:
              push_error(L, CURLE_UNKNOWN_OPTION);
              return;
            default:
              setopt_string(L, option);
              return;
          }
          return;
        case easy_setopt_param_long:
          setopt_integer<long>(L, option);
          return;
        case easy_setopt_param_curl_off_t:
          setopt_integer<curl_off_t>(L, option);
          return;
        case easy_setopt_param_struct_curl_httppost_p:
          setopt_httppost(L, option);
          return;
        case easy_setopt_param_struct_curl_slist_p:
          setopt_slist(L, option);
          return;
        case easy_setopt_param_callback:
          switch (option) {
            case CURLOPT_READFUNCTION:
              setopt_function(L, option, CURLOPT_READDATA, read_callback);
              return;
            case CURLOPT_HEADERFUNCTION:
              setopt_function(L, option, CURLOPT_HEADERDATA, write_callback);
              return;
            case CURLOPT_WRITEFUNCTION:
              setopt_function(L, option, CURLOPT_WRITEDATA, write_callback);
              return;
            default:
              push_error(L, CURLE_UNKNOWN_OPTION);
              return;
          }
          return;
        default:
          push_error(L, CURLE_UNKNOWN_OPTION);
          return;
      }
    }
  }

  void initialize_easy_setopt(lua_State* L) {
    luaX_set_field(L, -1, "setopt", impl_setopt);
  }
}
