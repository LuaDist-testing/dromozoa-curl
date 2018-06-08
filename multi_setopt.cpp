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

#include "common.hpp"
#include "symbols.hpp"

namespace dromozoa {
  namespace {
    int socket_callback(CURL* easy, curl_socket_t s, int what, void* userdata, void*) {
      luaX_reference<>* ref = static_cast<luaX_reference<>*>(userdata);
      lua_State* L = ref->state();
      luaX_top_saver save_top(L);
      {
        ref->get_field(L);
        new_easy_ref(L, easy);
        luaX_push(L, s, what);
        if (lua_pcall(L, 3, 0, 0) == 0) {
          return 0;
        } else {
          DROMOZOA_UNEXPECTED(lua_tostring(L, -1));
        }
      }
      // libcurl ignore callback result
      return -1;
    }

    int timer_callback(CURLM* multi, long timeout_ms, void* userdata) {
      luaX_reference<>* ref = static_cast<luaX_reference<>*>(userdata);
      lua_State* L = ref->state();
      luaX_top_saver save_top(L);
      {
        ref->get_field(L);
        new_multi_ref(L, multi);
        luaX_push(L, timeout_ms);
        if (lua_pcall(L, 2, 0, 0) == 0) {
          return 0;
        } else {
          DROMOZOA_UNEXPECTED(lua_tostring(L, -1));
        }
      }
      // libcurl ignore callback result
      return -1;
    }
  }

  class multi_handle_impl {
  public:
    template <class T>
    static CURLMcode setopt_integer(multi_handle* self, lua_State* L, CURLMoption option) {
      return curl_multi_setopt(self->get(), option, luaX_check_integer<T>(L, 3));
    }

    template <class T>
    static CURLMcode setopt_function_ref(multi_handle* self, lua_State* L, CURLMoption option, CURLMoption option_data, const T& callback) {
      if (lua_isnoneornil(L, 3)) {
        CURLMcode result = curl_multi_setopt(self->get(), option, 0);
        if (result == CURLM_OK) {
          result = curl_multi_setopt(self->get(), option_data, 0);
          if (result == CURLM_OK) {
            self->delete_reference(option);
          }
        }
        return result;
      } else {
        CURLMcode result = curl_multi_setopt(self->get(), option, &callback);
        if (result == CURLM_OK) {
          luaX_reference<>* ref = self->new_reference(option, L, 3);
          result = curl_multi_setopt(self->get(), option_data, ref);
        }
        return result;
      }
    }
  };

  namespace {
    void impl_setopt(lua_State* L) {
      multi_handle* self = check_multi_handle(L, 1);
      CURLMoption option = luaX_check_enum<CURLMoption>(L, 2);
      CURLMcode result = CURLM_UNKNOWN_OPTION;

      switch (multi_setopt_param(option)) {
        case multi_setopt_param_long:
          result = multi_handle_impl::setopt_integer<long>(self, L, option);
          break;

        case multi_setopt_param_callback:
          switch (option) {
            case CURLMOPT_SOCKETFUNCTION:
              result = multi_handle_impl::setopt_function_ref(self, L, option, CURLMOPT_SOCKETDATA, socket_callback);
              break;
            case CURLMOPT_TIMERFUNCTION:
              result = multi_handle_impl::setopt_function_ref(self, L, option, CURLMOPT_TIMERDATA, timer_callback);
              break;
            default:
              result = CURLM_UNKNOWN_OPTION;
          }
          break;

        default:
          result = CURLM_UNKNOWN_OPTION;
      }

      if (result == CURLM_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }
  }

  void initialize_multi_setopt(lua_State* L) {
    luaX_set_field(L, -1, "setopt", impl_setopt);
  }
}
