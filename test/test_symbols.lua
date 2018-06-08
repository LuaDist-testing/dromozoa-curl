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

assert(curl.CURLE_OK == 0)

local easy_options = {}
local easy_option_name_max = 0
local multi_options = {}
local multi_option_name_max = 0
local error_codes = {}
local error_code_name_max = 0

for name, value in pairs(curl) do
  if name:find "^CURLOPT_" then
    easy_options[#easy_options + 1] = { name = name, value = value }
    if easy_option_name_max < #name then
      easy_option_name_max = #name
    end
  elseif name:find "^CURLMOPT_" then
    multi_options[#multi_options + 1] = { name = name, value = value }
    if multi_option_name_max < #name then
      multi_option_name_max = #name
    end
  elseif name:find "^CURLE_" then
    error_codes[#error_codes + 1] = { name = name, value = value }
    if error_code_name_max < #name then
      error_code_name_max = #name
    end
  end
end

table.sort(easy_options, function (a, b) return a.value < b.value end)
table.sort(multi_options, function (a, b) return a.value < b.value end)
table.sort(error_codes, function (a, b) return a.value < b.value end)

if verbose then
  local format = "%-" .. easy_option_name_max .. "s | %d\n"
  io.stderr:write(("-"):rep(70), "\n")
  for i = 1, #easy_options do
    local option = easy_options[i]
    io.stderr:write(format:format(option.name, option.value))
  end

  local format = "%-" .. multi_option_name_max .. "s | %d\n"
  io.stderr:write(("-"):rep(70), "\n")
  for i = 1, #multi_options do
    local option = multi_options[i]
    io.stderr:write(format:format(option.name, option.value))
  end

  local format = "%-" .. error_code_name_max .. "s | %d\n"
  io.stderr:write(("-"):rep(70), "\n")
  for i = 1, #error_codes do
    local code = error_codes[i]
    io.stderr:write(format:format(code.name, code.value))
  end
end
