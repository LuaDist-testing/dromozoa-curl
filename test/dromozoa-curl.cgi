#! /usr/bin/env lua

-- Copyright (C) 2018 Tomoyuki Fujimori <moyu@dromozoa.com>
--
-- This file is part of dromozoa-curl.
--
-- dromozoa-curl is free software: you can redistribute it and/or modify
-- it under the terms of the GNU General Public License as published by
-- the Free Software Foundation, either version 3 of the License, or
-- (at your option) any later version.
--
-- dromozoa-curl is distributed in the hope that it will be useful,
-- but WITHOUT ANY WARRANTY; without even the implied warranty of
-- MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
-- GNU General Public License for more details.
--
-- You should have received a copy of the GNU General Public License
-- along with dromozoa-curl.  If not, see <http://www.gnu.org/licenses/>.

io.write(([[
Content-Type: text/plain; charset=UTF-8
Set-Cookie: bar=baz; Secure; Path=/
Set-Cookie: baz=qux; Secure; Path=/

return {
  REQUEST_METHOD = %q;
  REQUEST_SCHEME = %q;
  REQUEST_URI = %q;
  QUERY_STRING = %q;
  HTTP_HOST = %q;
  HTTP_USER_AGENT = %q;
  %q;
}
]]):format(
  os.getenv "REQUEST_METHOD",
  os.getenv "REQUEST_SCHEME",
  os.getenv "REQUEST_URI",
  os.getenv "QUERY_STRING",
  os.getenv "HTTP_HOST",
  os.getenv "HTTP_USER_AGENT" or "",
  io.read "*a"))
