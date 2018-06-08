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

local form = assert(curl.httppost())
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_COPYCONTENTS, "bar",
    curl.CURLFORM_END))
assert(form:add(
    curl.CURLFORM_COPYNAME, "foo\0bar",
    curl.CURLFORM_COPYCONTENTS, "bar\0baz"))

local stream_bar_count = 0
local stream_baz_count = 0

assert(form
:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILECONTENT, "test.sh")
:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILE, "test.sh")
:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_FILE, "test.sh",
    curl.CURLFORM_CONTENTTYPE, "text/plain",
    curl.CURLFORM_FILENAME, "foo.sh")
:add(
    curl.CURLFORM_COPYNAME, "foo",
    curl.CURLFORM_BUFFER, "test.html",
    curl.CURLFORM_BUFFERPTR, "<html><body><h1>test</h1></body></html>",
    curl.CURLFORM_CONTENTHEADER, { "X-Foo: foo", "X-Bar: bar" })
:add(
    curl.CURLFORM_COPYNAME, "bar",
    curl.CURLFORM_FILENAME, "bar.txt",
    curl.CURLFORM_CONTENTSLENGTH, 3,
    curl.CURLFORM_STREAM, function (n)
      print("stream bar", n)
      if stream_bar_count < 3 then
        stream_bar_count = stream_bar_count + 1
        return "X"
      else
        return ""
      end
    end)
:add(
    curl.CURLFORM_COPYNAME, "baz",
    curl.CURLFORM_STREAM, function (n)
      print("stream bar", n)
      if stream_baz_count < 3 then
        stream_baz_count = stream_baz_count + 1
        return "XYZ\r\n"
      else
        return ""
      end
    end))

local easy = assert(curl.easy())

assert(easy:setopt(curl.CURLOPT_URL, "http://localhost/cgi-bin/nph-dromozoa-curl-test.cgi"))
assert(easy:setopt(curl.CURLOPT_HTTPPOST, form));
form = nil
collectgarbage()
collectgarbage()

assert(easy:perform())

assert(curl.global_cleanup())
