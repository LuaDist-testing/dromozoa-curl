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
    class global_handle {
    public:
      global_handle() : initialized_(true) {}

      ~global_handle() {
        if (initialized_) {
          curl_global_cleanup();
        }
      }

      void cleanup() {
        curl_global_cleanup();
        initialized_ = false;
      }

    private:
      bool initialized_;
      global_handle(const global_handle&);
      global_handle& operator=(const global_handle&);
    };

    void impl_gc(lua_State* L) {
      luaX_check_udata<global_handle>(L, 1, "dromozoa.curl.global_handle")->~global_handle();
    }

    void impl_global_init(lua_State* L) {
      luaX_get_field(L, LUA_REGISTRYINDEX, "dromozoa.curl.global");
      bool is_nil = lua_isnil(L, -1);
      lua_pop(L, 1);
      if (is_nil) {
        CURLcode result = curl_global_init(CURL_GLOBAL_ALL);
        if (result == 0) {
          luaX_new<global_handle>(L);
          luaX_set_metatable(L, "dromozoa.curl.global_handle");
          luaX_set_field(L, LUA_REGISTRYINDEX, "dromozoa.curl.global");
          luaX_push_success(L);
        } else {
          push_error(L, result);
        }
      } else {
        luaX_push_success(L);
      }
    }

    void impl_global_cleanup(lua_State* L) {
      luaX_get_field(L, LUA_REGISTRYINDEX, "dromozoa.curl.global");
      if (global_handle* self = luaX_to_udata<global_handle>(L, -1, "dromozoa.curl.global_handle")) {
        self->cleanup();
      }
      lua_pop(L, 1);
      luaX_set_field(L, LUA_REGISTRYINDEX, "dromozoa.curl.global", luaX_nil);
      luaX_push_success(L);
    }

    void impl_version(lua_State* L) {
      luaX_push(L, curl_version());
    }
  }

  void initialize_main(lua_State* L) {
    luaL_newmetatable(L, "dromozoa.curl.global_handle");
    luaX_set_field(L, -1, "__gc", impl_gc);
    lua_pop(L, 1);

    luaX_set_field(L, -1, "global_init", impl_global_init);
    luaX_set_field(L, -1, "global_cleanup", impl_global_cleanup);
    luaX_set_field(L, -1, "version", impl_version);
  }
}
