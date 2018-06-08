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

namespace dromozoa {
  namespace {
    void impl_gc(lua_State* L) {
      check_httppost_handle(L, 1)->~httppost_handle();
    }

    void impl_call(lua_State* L) {
      luaX_new<httppost_handle>(L);
      luaX_set_metatable(L, "dromozoa.curl.httppost");
    }

    void impl_free(lua_State* L) {
      check_httppost_handle(L, 1)->free();
      luaX_push_success(L);
    }

    void impl_add(lua_State* L) {
      CURLFORMcode result = check_httppost_handle(L, 1)->add(L);
      if (result == CURL_FORMADD_OK) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }
  }

  httppost_handle* check_httppost_handle(lua_State* L, int arg) {
    return luaX_check_udata<httppost_handle>(L, arg, "dromozoa.curl.httppost");
  }

  void initialize_httppost(lua_State* L) {
    lua_newtable(L);
    {
      luaL_newmetatable(L, "dromozoa.curl.httppost");
      lua_pushvalue(L, -2);
      luaX_set_field(L, -2, "__index");
      luaX_set_field(L, -1, "__gc", impl_gc);
      lua_pop(L, 1);

      luaX_set_metafield(L, -1, "__call", impl_call);
      luaX_set_field(L, -1, "free", impl_free);
      luaX_set_field(L, -1, "add", impl_add);
    }
    luaX_set_field(L, -2, "httppost");
  }
}
