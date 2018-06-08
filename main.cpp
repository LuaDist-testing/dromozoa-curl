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
    void impl_global_init(lua_State* L) {
      long flags = luaX_opt_integer(L, 1, CURL_GLOBAL_ALL);
      CURLcode result = curl_global_init(flags);
      if (result == 0) {
        luaX_push_success(L);
      } else {
        push_error(L, result);
      }
    }

    void impl_global_cleanup(lua_State* L) {
      curl_global_cleanup();
      luaX_push_success(L);
    }
  }

  void initialize_main(lua_State* L) {
    luaX_set_field(L, -1, "global_init", impl_global_init);
    luaX_set_field(L, -1, "global_cleanup", impl_global_cleanup);
  }
}
