-- Copyright (C) 2017 Tomoyuki Fujimori <moyu@dromozoa.com>
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

assert(curl.global_init())

local easy = assert(curl.easy())
assert(easy:setopt(curl.CURLOPT_URL, "https://dromozoa.s3.amazonaws.com/pub/index.html"))
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
  print(data)
end))
assert(easy:perform())
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION))
assert(easy:perform())

assert(easy:cleanup())
assert(curl.global_cleanup())
