-- Copyright (C) 2017,2018 Tomoyuki Fujimori <moyu@dromozoa.com>
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

local function parse_header(data)
  local line, header = assert(table.concat(data):gsub("\r\n\r\n$", "\r\n"):gsub("\r\n%s+", " "):match "(.-)\r\n(.*)")
  local result = {}
  for item in header:gmatch "(.-)\r\n" do
    if verbose then
      io.stderr:write(item, "\n")
    end
    local name, value = assert(item:match "(.-):%s*(.*)")
    result[name] = value
  end
  return line, result
end

assert(curl.global_init())

local url = "https://dromozoa.s3.amazonaws.com/pub/dromozoa-curl/test.txt"
local header_data
local body_data

local easy = assert(curl.easy())
assert(easy:reset())

local result, message, code = easy:setopt(-1, 1)
if verbose then
  io.stderr:write(message, "\n")
end
assert(not result)
assert(code == curl.CURLE_UNKNOWN_OPTION or code == curl.CURLE_BAD_FUNCTION_ARGUMENT)

if verbose then
  assert(easy:setopt(curl.CURLOPT_VERBOSE, 1))
end
assert(easy:setopt(curl.CURLOPT_IPRESOLVE, curl.CURL_IPRESOLVE_V4))
assert(easy:setopt(curl.CURLOPT_URL, url))
assert(easy:setopt(curl.CURLOPT_HEADERFUNCTION, function (data)
  header_data[#header_data + 1] = data
end))
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
  body_data[#body_data + 1] = data
end))

header_data = {}
body_data = {}
assert(easy:perform())
assert(easy:getinfo(curl.CURLINFO_EFFECTIVE_URL) == url)
assert(easy:getinfo(curl.CURLINFO_RESPONSE_CODE) == 200)
assert(easy:getinfo(curl.CURLINFO_CONTENT_LENGTH_DOWNLOAD) == 56)
assert(easy:getinfo(curl.CURLINFO_CONTENT_TYPE) == "text/plain")

local line, header = parse_header(header_data)
assert(line == "HTTP/1.1 200 OK")
assert(header["ETag"] == [["edea258640a0460e6156cfb98d6cdf3b"]])
assert(header["Accept-Ranges"] == "bytes")
assert(header["Content-Type"] == "text/plain")
assert(header["Content-Length"] == "56")
assert(header["Server"] == "AmazonS3")

local body = table.concat(body_data)
if verbose then
  io.stderr:write(body)
end
assert(body == [[
1. foo
2. bar
3. baz
4. qux
5. foo
6. bar
7. baz
8. qux
]])

assert(easy:setopt(curl.CURLOPT_RANGE, "14-41"))

header_data = {}
body_data = {}
assert(easy:perform())
assert(easy:getinfo(curl.CURLINFO_EFFECTIVE_URL) == url)
assert(easy:getinfo(curl.CURLINFO_RESPONSE_CODE) == 206)
assert(easy:getinfo(curl.CURLINFO_CONTENT_LENGTH_DOWNLOAD) == 28)
assert(easy:getinfo(curl.CURLINFO_CONTENT_TYPE) == "text/plain")

local line, header = parse_header(header_data)
assert(line == "HTTP/1.1 206 Partial Content")
assert(header["ETag"] == [["edea258640a0460e6156cfb98d6cdf3b"]])
assert(header["Accept-Ranges"] == "bytes")
assert(header["Content-Range"] == "bytes 14-41/56")
assert(header["Content-Type"] == "text/plain")
assert(header["Content-Length"] == "28")
assert(header["Server"] == "AmazonS3")

local body = table.concat(body_data)
if verbose then
  io.stderr:write(body)
end
assert(body == [[
3. baz
4. qux
5. foo
6. bar
]])
