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
#include "symbols.hpp"

namespace dromozoa {
  void initialize_easy(lua_State* L);
  void initialize_httppost(lua_State* L);
  void initialize_main(lua_State* L);
  void initialize_multi(lua_State* L);

  void initialize(lua_State* L) {
    initialize_easy(L);
    initialize_httppost(L);
    initialize_main(L);
    initialize_multi(L);
    initialize_symbols(L);
  }
}

extern "C" int luaopen_dromozoa_curl(lua_State* L) {
  lua_newtable(L);
  dromozoa::initialize(L);
  return 1;
}
