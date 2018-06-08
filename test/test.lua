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

local json = require "dromozoa.commons.json"
local pairs = require "dromozoa.commons.pairs"
local sequence = require "dromozoa.commons.sequence"
local curl = require "dromozoa.curl"

assert(curl.global_init())
assert(curl.global_init())

local easy = assert(curl.easy())
assert(easy:reset())

assert(easy:setopt(curl.CURLOPT_URL, "https://dromozoa.s3.amazonaws.com/pub/index.html"))
-- assert(easy:setopt(curl.CURLOPT_URL, "https://dromozoa.s3.amazonaws.com/pub/no-such-file.html"))
-- assert(easy:setopt(curl.CURLOPT_URL, "http://localhost/cgi-bin/nph-dromozoa-curl-test.cgi?command=redirect&redirect_count=3"))
-- assert(easy:setopt(curl.CURLOPT_URL, "http://localhost/cgi-bin/nph-dromozoa-curl-test.cgi?command=sleep&sleep_duration=0.5&sleep_count=10"))
assert(easy:setopt(curl.CURLOPT_VERBOSE, 0))
assert(easy:setopt(curl.CURLOPT_NOPROGRESS, 0))
assert(easy:setopt(curl.CURLOPT_FAILONERROR, 1))
assert(easy:setopt(curl.CURLOPT_FILETIME, 1))
assert(easy:setopt(curl.CURLOPT_SSL_VERIFYPEER, 1))
assert(easy:setopt(curl.CURLOPT_FOLLOWLOCATION, 1))
assert(assert(easy:setopt(curl.CURLOPT_REFERER, "http://localhost/")) == easy)
-- assert(easy:setopt(curl.CURLOPT_CERTINFO, 1))

assert(easy:setopt(curl.CURLOPT_HEADERFUNCTION, function (data)
  print(("header:%q"):format(data))
  return #data
end))

local content = ""
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
  content = content .. data
  -- print(("write:%q"):format(data))
  -- print(data)
end))

local result, message, code = easy.setopt(9999999, 1)
assert(result == nil)
assert(code == curl.CURLE_UNKNOWN_OPTION or code == curl.CURLE_BAD_FUNCTION_ARGUMENT)
print(message)

assert(easy:perform())

print(easy:getinfo(curl.CURLINFO_EFFECTIVE_URL))
if false then
  print(easy:getinfo(curl.CURLINFO_RESPONSE_CODE))
  print(os.date("!%Y-%m-%dT%H:%M:%SZ", easy:getinfo(curl.CURLINFO_FILETIME)))
  print(easy:getinfo(curl.CURLINFO_TOTAL_TIME))
  print(easy:getinfo(curl.CURLINFO_NAMELOOKUP_TIME))
  print(easy:getinfo(curl.CURLINFO_CONNECT_TIME))
  print(easy:getinfo(curl.CURLINFO_APPCONNECT_TIME))
  print(easy:getinfo(curl.CURLINFO_PRETRANSFER_TIME))
  print(easy:getinfo(curl.CURLINFO_STARTTRANSFER_TIME))
  print(easy:getinfo(curl.CURLINFO_REDIRECT_TIME))
  print(easy:getinfo(curl.CURLINFO_REDIRECT_COUNT))
  print(easy:getinfo(curl.CURLINFO_REDIRECT_URL))
  print(easy:getinfo(curl.CURLINFO_SIZE_UPLOAD))
  print(easy:getinfo(curl.CURLINFO_SIZE_DOWNLOAD))
  print(easy:getinfo(curl.CURLINFO_SPEED_DOWNLOAD))
  print(easy:getinfo(curl.CURLINFO_SPEED_UPLOAD))
  print(easy:getinfo(curl.CURLINFO_HEADER_SIZE))
  print(easy:getinfo(curl.CURLINFO_REQUEST_SIZE))
  print(easy:getinfo(curl.CURLINFO_SSL_VERIFYRESULT))
  print(json.encode(easy:getinfo(curl.CURLINFO_SSL_ENGINES)))
  print(easy:getinfo(curl.CURLINFO_CONTENT_LENGTH_DOWNLOAD))
  print(easy:getinfo(curl.CURLINFO_CONTENT_LENGTH_UPLOAD))
  print(easy:getinfo(curl.CURLINFO_CONTENT_TYPE))
  print(easy:getinfo(curl.CURLINFO_HTTPAUTH_AVAIL))
  print(easy:getinfo(curl.CURLINFO_PROXYAUTH_AVAIL))
  print(easy:getinfo(curl.CURLINFO_OS_ERRNO))
  print(easy:getinfo(curl.CURLINFO_NUM_CONNECTS))
  print(easy:getinfo(curl.CURLINFO_PRIMARY_IP))
  print(easy:getinfo(curl.CURLINFO_PRIMARY_PORT))
  print(easy:getinfo(curl.CURLINFO_LOCAL_IP))
  print(easy:getinfo(curl.CURLINFO_LOCAL_PORT))
  print(json.encode(easy:getinfo(curl.CURLINFO_COOKIELIST)))
end
print(json.encode(easy:getinfo(curl.CURLINFO_CERTINFO)))

if curl.CURLINFO_ACTIVESOCKET then
  print(json.encode(easy:getinfo(curl.CURLINFO_ACTIVESOCKET)))
end

-- print(curl.CURL_HTTP_VERSION_1_0)
-- print(curl.CURL_HTTP_VERSION_1_1)
-- print(curl.CURL_HTTP_VERSION_2_0)

-- local result = json.decode(content)
-- print(json.encode(result, { pretty = true }))

assert(easy:cleanup())

local data = sequence()
for k, v in pairs(curl) do
  if k:match("^CURLOPT") then
    data:push({ name = k, value = v })
  end
end
data:sort(function (a, b) return a.value < b.value end)
for item in data:each() do
  -- print(item.name, item.value)
end

assert(curl.global_cleanup())
