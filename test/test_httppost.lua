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

local function parse_header_value(data)
  local result = {}
  for item in (data .. ";"):gmatch "(.-);%s*" do
    local name, value = item:match "(.-)=(.*)"
    if name then
      result[name] = value
    else
      result[1] = item
    end
  end
  return result
end

local function parse_part(data)
  local header, body = assert(data:match "(.-\r\n)\r\n(.*)")
  local result = { body }
  for item in header:gsub("\r\n%s+", " "):gmatch "(.-)\r\n" do
    if verbose then
      io.stderr:write(item, "\n")
    end
    local name, value = assert(item:match "(.-):%s*(.*)")
    result[name] = parse_header_value(value)
  end
  if verbose then
    io.stderr:write(body, "\n")
  end
  return result
end

assert(curl.global_init())

local body_data = {}
local bar_cursor = 0
local baz_cursor = 0

local form = assert(curl.httppost())
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_COPYCONTENTS, "bar",
    curl.CURLFORM_END))
assert(form:add(
    curl.CURLFORM_PTRNAME, "foo" .. "\0" .. "bar",
    curl.CURLFORM_PTRCONTENTS, "bar" .. ("\0"):rep(16) .. "baz"))
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILECONTENT, "test/test.txt"))
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILE, "test/test.txt"))
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILE, "test/test.txt",
    curl.CURLFORM_CONTENTTYPE, "text/plain",
    curl.CURLFORM_FILENAME, "bar.txt"))
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_BUFFER, "test.html",
    curl.CURLFORM_CONTENTTYPE, "text/html",
    curl.CURLFORM_BUFFERPTR, "<html><body><h1>test</h1><div>" .. ("X"):rep(16) .. "</div></body></html>",
    curl.CURLFORM_CONTENTHEADER, { "X-Foo: foo", "X-Bar: bar" }))
assert(form:add(
    curl.CURLFORM_COPYNAME, "bar",
    curl.CURLFORM_FILENAME, "bar.txt",
    curl.CURLFORM_CONTENTSLENGTH, 16,
    curl.CURLFORM_STREAM, function (n)
      if verbose then
        io.stderr:write("bar ", n, "\n")
      end
      assert(n > 0)
      if bar_cursor < 16 then
        bar_cursor = bar_cursor + 1
        return "X"
      else
        return ""
      end
    end))
assert(form:add(
    curl.CURLFORM_COPYNAME, "baz",
    curl.CURLFORM_CONTENTSLENGTH, 64,
    curl.CURLFORM_STREAM, function (n)
      if verbose then
        io.stderr:write("baz ", n, "\n")
      end
      assert(n > 3)
      if baz_cursor < 16 then
        baz_cursor = baz_cursor + 1
        return "XYZ\n"
      else
        return ""
      end
    end))

local easy = assert(curl.easy())
if verbose then
  assert(easy:setopt(curl.CURLOPT_VERBOSE, 1))
end
assert(easy:setopt(curl.CURLOPT_IPRESOLVE, curl.CURL_IPRESOLVE_V4))
assert(easy:setopt(curl.CURLOPT_URL, "https://kotori.dromozoa.com/cgi-bin/dromozoa-curl.cgi"))
assert(easy:setopt(curl.CURLOPT_HTTPPOST, form))
assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
  body_data[#body_data + 1] = data
end))
form = nil
collectgarbage()
collectgarbage()

assert(easy:perform())

local body = table.concat(body_data)
if verbose then
  io.stderr:write(body)
end
local result = assert(assert((loadstring or load)(body))())
local request = result[1]
local sep, multipart = assert(result[1]:match "(.-)\r\n(.*)")
local sep1 = "\r\n" .. sep .. "\r\n"
local sep2 = "\r\n" .. sep .. "--\r\n"

local cursor = 1
local parts = {}
while true do
  local i, j = multipart:find(sep1, cursor, true)
  if i then
    parts[#parts + 1] = parse_part(multipart:sub(cursor, i - 1))
  else
    i, j = assert(multipart:find(sep2, cursor, true))
    parts[#parts + 1] = parse_part(multipart:sub(cursor, i - 1))
    break
  end
  cursor = j + 1
end

local test_data = [[
1. foo
2. bar
3. baz
4. qux
5. foo
6. bar
7. baz
8. qux
]]

assert(#parts == 8)
local part1, part2, part3, part4, part5, part6, part7, part8 = (table.unpack or unpack)(parts)
assert(part1["Content-Disposition"].name == [["foo"]])
assert(part1[1] == "bar")
assert(part2["Content-Disposition"].name == "\"foo\0bar\"")
assert(part2[1]:find "bar%z+baz")
assert(part3["Content-Disposition"].name == [["foo"]])
assert(part3[1] == test_data)
assert(part4["Content-Disposition"].name == [["foo"]])
assert(part4["Content-Disposition"].filename == [["test.txt"]])
assert(part4["Content-Type"][1] == "text/plain")
assert(part4[1] == test_data)
assert(part5["Content-Disposition"].name == [["foo"]])
assert(part5["Content-Disposition"].filename == [["bar.txt"]])
assert(part5["Content-Type"][1] == "text/plain")
assert(part5[1] == test_data)
assert(part6["Content-Disposition"].name == [["foo"]])
assert(part6["Content-Disposition"].filename == [["test.html"]])
assert(part6["Content-Type"][1] == "text/html")
assert(part6["X-Foo"][1] == "foo")
assert(part6["X-Bar"][1] == "bar")
assert(part6[1]:find "^<html><body><h1>test</h1><div>X+</div></body></html>$")
assert(part7["Content-Disposition"].name == [["bar"]])
assert(part7["Content-Disposition"].filename == [["bar.txt"]])
assert(part7[1] == ("X"):rep(16))
assert(part8["Content-Disposition"].name == [["baz"]])
assert(part8[1] == ("XYZ\n"):rep(16))
