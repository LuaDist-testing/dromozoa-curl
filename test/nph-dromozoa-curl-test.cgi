#! /opt/dromozoa53/bin/lua

local datetime = require "dromozoa.commons.datetime"
local ipairs = require "dromozoa.commons.ipairs"
local json = require "dromozoa.commons.json"
local linked_hash_table = require "dromozoa.commons.linked_hash_table"
local split = require "dromozoa.commons.split"
local unix_time = require "dromozoa.commons.unix_time"
local uri = require "dromozoa.commons.uri"
local unix = require "dromozoa.unix"

local JST = 9 * 60 * 60

local function current_time()
  local tv = unix.clock_gettime(unix.CLOCK_REALTIME)
  local d = unix_time.decode(tv.tv_sec, JST)
  d.nsec = tv.tv_nsec
  return datetime.encode(d, JST)
end

local reason_3xx = {
  [301] = "Moved Permanently";
  [302] = "Found";
  [307] = "Temporary Redirect";
  [308] = "Permanent Redirect";
}

local env = linked_hash_table()
for _, item in ipairs(unix.get_environ()) do
  local k = item:match("^([^=]*)")
  env[k] = os.getenv(k)
end

local result = linked_hash_table()
result.env = env

local request_method = env.REQUEST_METHOD
local request_uri = env.REQUEST_URI
local script_name = env.SCRIPT_NAME
local query_string = env.QUERY_STRING

local params = linked_hash_table()
if query_string ~= nil and query_string ~= "" then
  for item in split(query_string, "&"):each() do
    local k, v = item:match("^([^=]*)=(.*)$")
    if k == nil then
      params[uri.decode(item)] = true
    else
      params[uri.decode(k)] = uri.decode(v)
    end
  end
end
result.params = params
result.content = io.read("*a")

local command = params.command
if command == "sleep" then
  local sleep_duration = tonumber(params.sleep_duration)
  if sleep_duration == nil then
    sleep_duration = 1
  end
  local sleep_count = tonumber(params.sleep_count)
  if sleep_count == nil then
    sleep_count = 10
  end

  io.write("HTTP/1.1 200 OK\r\n")
  io.write("Content-Type: text/plain; charset=UTF-8\r\n")
  io.write("\r\n")

  for i = 1, sleep_count do
    unix.nanosleep(sleep_duration)
    io.write(i, ": ", current_time(), "\n")
    io.flush()
  end
elseif command == "redirect" then
  local redirect_code = tonumber(params.redirect_code)
  local redirect_reason = reason_3xx[redirect_code]
  if redirect_reason == nil then
    redirect_code = 301
    redirect_reason = reason_3xx[redirect_code]
  end
  local redirect_count = tonumber(params.redirect_count)
  if redirect_count == nil then
    redirect_count = 1
  end
  local location
  if redirect_count == 1 then
    location = "http://localhost" .. script_name
  else
    location = "http://localhost" .. script_name .. "?command=redirect&" .. "redirect_code=" .. redirect_code .. "&redirect_count=" .. (redirect_count - 1)
  end
  io.write("HTTP/1.1 ", redirect_code, " ", redirect_reason, "\r\n")
  io.write("Location: ", location, "\r\n")
  io.write("\r\n")
else
  io.write("HTTP/1.1 200 Not Found\r\n")
  io.write("Content-Type: application/json; charset=UTF-8\r\n")
  io.write("\r\n")
  io.write(json.encode(result, { pretty = true }), "\n")
end
