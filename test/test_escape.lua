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

local curl = require "dromozoa.curl"

local verbose = os.getenv "VERBOSE" == "1"

assert(curl.global_init())

local easy = assert(curl.easy())

local e = assert(easy:escape "あいうえお")
if verbose then
  io.stderr:write(e, "\n")
end
assert(e == "%E3%81%82%E3%81%84%E3%81%86%E3%81%88%E3%81%8A")

local u = assert(easy:unescape "%E3%81%82%E3%81%84%E3%81%86%E3%81%88%E3%81%8A")
if verbose then
  io.stderr:write(u, "\n")
end
assert(u == "あいうえお")

assert(easy:escape "foo\0bar" == "foo%00bar")
assert(easy:unescape "foo%00bar" == "foo\0bar")
