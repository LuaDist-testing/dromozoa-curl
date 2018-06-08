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
local unix = require "dromozoa.unix"

local verbose = os.getenv "VERBOSE" == "1"

assert(dyld.dlopen_pthread())
assert(curl.global_init())

local selector = assert(unix.selector())
local selector_time = assert(unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW))
local timer = unix.timer()

local multi = assert(curl.multi())
local multi_timer
local easy

for i = 1, 10 do
  easy = assert(curl.easy())
  local j = 0
  if verbose then
    assert(easy:setopt(curl.CURLOPT_VERBOSE, 1))
  end
  assert(easy:setopt(curl.CURLOPT_IPRESOLVE, curl.CURL_IPRESOLVE_V4))
  assert(easy:setopt(curl.CURLOPT_URL, "http://kotori.dromozoa.com/cgi-bin/nph-dromozoa-curl.cgi"))
  assert(easy:setopt(curl.CURLOPT_WRITEFUNCTION, function (data)
    j = j + 1
    if verbose then
      io.stderr:write(i, " ", j, " ", data)
      io.stderr:flush()
    end
  end))
  assert(multi:add_handle(easy))
end

if verbose then
  io.stderr:write "collectgarbage1\n"
  io.stderr:flush()
end
collectgarbage()
if verbose then
  io.stderr:write "collectgarbage2\n"
  io.stderr:flush()
end
collectgarbage()
if verbose then
  io.stderr:write "collectgarbage3\n"
  io.stderr:flush()
end

local socket_map = {}

assert(multi:setopt(curl.CURLMOPT_SOCKETFUNCTION, function (easy, s, what)
  if what == curl.CURL_POLL_REMOVE then
    socket_map[s] = nil
    selector:del(s)
  else
    local event = 0
    if what == curl.CURL_POLL_IN then
      event = unix.SELECTOR_READ
    elseif what == curl.CURL_POLL_OUT then
      event = unix.SELECTOR_WRITE
    elseif what == curl.CURL_POLL_INOUT then
      event = unix.SELECTOR_READ_WRITE
    end
    if socket_map[s] then
      selector:mod(s, event)
    else
      selector:add(s, event)
    end
    socket_map[s] = event
  end
end))

assert(multi:setopt(curl.CURLMOPT_TIMERFUNCTION, function (multi, timeout_ms)
  if timeout_ms == 0 then
    local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
  elseif timeout_ms > 0 then
    multi_timer = unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW) + unix.timespec(timeout_ms * 0.001)
  else
    multi_timer = nil
  end
end))

timer:start()

local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
while true do
  selector_time = assert(unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW))
  if multi_timer then
    multi_timer = nil
    local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
  end
  local result = selector:select(0.1)
  local running_handles
  for i = 1, result do
    local fd, event = selector:event(i)
    local curl_events = 0
    if unix.band(event, unix.SELECTOR_READ) ~= 0 then
      curl_events = unix.bor(curl_events, curl.CURL_POLL_IN)
    end
    if unix.band(event, unix.SELECTOR_WRITE) ~= 0 then
      curl_events = unix.bor(curl_events, curl.CURL_POLL_OUT)
    end
    running_handles = assert(multi:socket_action(fd, curl_events))
    if running_handles == 0 then
      break
    end
  end
  if running_handles == 0 then
    break
  end
end

while true do
  local info, n = multi:info_read()
  if info then
    assert(info.msg == curl.CURLMSG_DONE)
    assert(info.result == curl.CURLE_OK)
  else
    break
  end
  if verbose then
    io.stderr:write(n, "\n")
  end
end

timer:stop()

if verbose then
  io.stderr:write(timer:elapsed(), "\n")
end
assert(timer:elapsed() < 5)

local result, message = multi:add_handle(easy)
if verbose then
  io.stderr:write(message, "\n")
end
assert(not result)

assert(multi:remove_handle(easy))
easy = nil

collectgarbage()
collectgarbage()
