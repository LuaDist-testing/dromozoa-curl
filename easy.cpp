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

#include "common.hpp"

namespace dromozoa {
  namespace {
    void impl_gc(lua_State* L) {
      check_easy_handle(L, 1)->~easy_handle();
    }

    void impl_call(lua_State* L) {
      if (CURL* handle = curl_easy_init()) {
        luaX_new<easy_handle>(L, handle);
        luaX_set_metatable(L, "dromozoa.curl.easy");
      } else {
        push_error(L, CURLE_FAILED_INIT);
      }
    }

    void impl_cleanup(lua_State* L) {
      check_easy_handle(L, 1)->cleanup();
      luaX_push_success(L);
    }

    void impl_reset(lua_State* L) {
      check_easy_handle(L, 1)->reset();
      luaX_push_success(L);
    }

    void impl_perform(lua_State* L) {
      CURLcode result = curl_easy_perform(check_easy(L, 1));
      if (result == CURLE_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }

    void impl_get_address(lua_State* L) {
      lua_pushlightuserdata(L, check_easy(L, 1));
    }
  }

  easy_handle* check_easy_handle(lua_State* L, int arg) {
    return luaX_check_udata<easy_handle>(L, arg, "dromozoa.curl.easy_ref", "dromozoa.curl.easy");
  }

  CURL* check_easy(lua_State* L, int arg) {
    return check_easy_handle(L, arg)->get();
  }

  void new_easy_ref(lua_State* L, CURL* handle) {
    luaX_new<easy_handle>(L, handle);
    luaX_set_metatable(L, "dromozoa.curl.easy_ref");
  }

  void initialize_easy_setopt(lua_State* L);
  void initialize_easy_getinfo(lua_State* L);

  void initialize_easy(lua_State* L) {
    lua_newtable(L);
    {
      luaL_newmetatable(L, "dromozoa.curl.easy_ref");
      lua_pushvalue(L, -2);
      luaX_set_field(L, -2, "__index");
      lua_pop(L, 1);

      luaL_newmetatable(L, "dromozoa.curl.easy");
      lua_pushvalue(L, -2);
      luaX_set_field(L, -2, "__index");
      luaX_set_field(L, -1, "__gc", impl_gc);
      lua_pop(L, 1);

      luaX_set_metafield(L, -1, "__call", impl_call);
      luaX_set_field(L, -1, "cleanup", impl_cleanup);
      luaX_set_field(L, -1, "reset", impl_reset);
      luaX_set_field(L, -1, "perform", impl_perform);
      luaX_set_field(L, -1, "get_address", impl_get_address);

      initialize_easy_setopt(L);
      initialize_easy_getinfo(L);
    }
    luaX_set_field(L, -2, "easy");
  }
}
