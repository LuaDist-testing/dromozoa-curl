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

local unix = require "dromozoa.unix"
local curl = require "dromozoa.curl"
local multimap = require "dromozoa.commons.multimap"
local uint32 = require "dromozoa.commons.uint32"

local selector = unix.selector()
local selector_time = unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW)
local timers = multimap()

local multi = assert(curl.multi())

local easy1 = assert(curl.easy())
assert(easy1:setopt(curl.CURLOPT_URL, "https://dromozoa.s3.amazonaws.com/pub/index.html"))
assert(multi:add_handle(easy1))

local easy2 = assert(curl.easy())
assert(easy2:setopt(curl.CURLOPT_URL, "https://dromozoa.s3.amazonaws.com/pub/dromozoa-s3-browser/1.2/dromozoa-s3-browser.js"))
assert(multi:add_handle(easy2))

local socket_map = {}

multi:setopt(curl.CURLMOPT_SOCKETFUNCTION, function (easy, s, what)
  print("socket", easy, s, what)
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
    if socket_map[s] == nil then
      selector:add(s, event)
    else
      selector:mod(s, event)
    end
    socket_map[s] = event
  end
end)

multi:setopt(curl.CURLMOPT_TIMERFUNCTION, function (multi, timeout_ms)
  print("timer", multi, timeout_ms)
  if timeout_ms == 0 then
    local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
    print("1:running_handles", running_handles)
  elseif timeout_ms > 0 then
    local tv = unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW)
    tv:add(timeout_ms * 0.001)
    timers:insert(tv, function ()
      local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
      print("2:running_handles", running_handles)
    end)
  end
end)

local running_handles = assert(multi:socket_action(curl.CURL_SOCKET_TIMEOUT, 0))
print("0:running_handles", running_handles)
while true do
  selector_time = unix.clock_gettime(unix.CLOCK_MONOTONIC_RAW)
  local range = timers:upper_bound(selector_time)
  for _, f in range:each() do
    f()
  end
  for _, _, h in range:each() do
    h:remove()
  end
  local result = selector:select(0.1)
  local running_handles
  for i = 1, result do
    local fd, event = selector:event(i)
    local curl_events = 0
    if uint32.band(event, unix.SELECTOR_READ) ~= 0 then
      curl_events = uint32.bor(curl_events, curl.CURL_POLL_IN)
    end
    if uint32.band(event, unix.SELECTOR_WRITE) ~= 0 then
      curl_events = uint32.bor(curl_events, curl.CURL_POLL_OUT)
    end
    running_handles = assert(multi:socket_action(fd, curl_events))
    print("3:running_handles", running_handles)
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
  print(info, n)
  if info == nil then
    break
  else
    assert(info.msg == curl.CURLMSG_DONE)
    assert(info.result == curl.CURLE_OK)
  end
end

assert(multi:remove_handle(easy1))
assert(easy1:cleanup())
assert(multi:remove_handle(easy2))
assert(easy2:cleanup())
assert(multi:cleanup())
