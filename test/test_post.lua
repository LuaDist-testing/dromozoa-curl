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
local dyld = require "dromozoa.dyld"

local verbose = os.getenv "VERBOSE" == "1"

assert(dyld.dlopen_pthread())
assert(curl.global_init())

local body_data = {}

local easy = assert(curl.easy())
if verbose then
  assert(easy:setopt(curl.CURLOPT_VERBOSE, 1))
end
assert(easy:setopt(curl.CURLOPT_IPRESOLVE, curl.CURL_IPRESOLVE_V4))
assert(easy:setopt(curl.CURLOPT_URL, "https://kotori.dromozoa.com/cgi-bin/dromozoa-curl.cgi"))
assert(easy:setopt(curl.CURLOPT_POSTFIELDS, "foo=bar&baz\0=" .. ("X"):rep(16)))
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
  body_data[#body_data + 1] = data
end))
collectgarbage()
collectgarbage()

assert(easy:perform())

local body = table.concat(body_data)
if verbose then
  io.stderr:write(body)
end

local result = assert(assert((loadstring or load)(body))())
assert(result.REQUEST_METHOD == "POST")
assert(result.REQUEST_SCHEME == "https")
assert(result.REQUEST_URI == "/cgi-bin/dromozoa-curl.cgi")
assert(result.QUERY_STRING == "")
assert(result.HTTP_HOST == "kotori.dromozoa.com")
assert(result.HTTP_USER_AGENT == "")
assert(result[1]:find "^foo=bar&baz%z=X+$")
