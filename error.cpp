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
  void push_error(lua_State* L, CURLcode code) {
    luaX_push(L, luaX_nil, curl_easy_strerror(code), static_cast<lua_Integer>(code));
  }

  void push_error(lua_State* L, CURLMcode code) {
    luaX_push(L, luaX_nil, curl_multi_strerror(code), static_cast<lua_Integer>(code));
  }

  void push_error(lua_State* L, CURLFORMcode code) {
    luaX_push(L, luaX_nil, error_to_string(code), static_cast<lua_Integer>(code));
  }
}
