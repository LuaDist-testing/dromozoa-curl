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

local unpack = table.unpack or unpack

local source_dir = ...

local ignore_symbols = {
  CURL_DID_MEMORY_FUNC_TYPEDEFS = true;
  CURL_STRICTER = true;
  CURLOPT_WRITEINFO = true;
  CURLKHTYPE_DSS = true;
  CURLKHTYPE_RSA = true;
  CURLKHTYPE_RSA1 = true;
  CURLKHTYPE_UNKNOWN = true;
}

local alias_symbols = {
  CURLOPT_ENCODING = "CURLOPT_ACCEPT_ENCODING";
  CURLOPT_POST301 = "CURLOPT_POSTREDIR";
  CURLOPT_RTSPHEADER = "CURLOPT_HTTPHEADER";
  CURLOPT_SERVER_RESPONSE_TIMEOUT = "CURLOPT_FTP_RESPONSE_TIMEOUT";
  CURLOPT_WRITEHEADER = "CURLOPT_HEADERDATA";
}

local param_names = {
  mime = "curl_mime *";
  string = "char *";
}

local function curl_version_bits(source)
  if not source or source == "-" then
    return
  else
    local major, minor, patch = source:match "^(%d+)%.(%d+)%.(%d+)$"
    if not major then
      major, minor = assert(source:match "^(%d+)%.(%d+)$")
      if not major then
        return
      end
      patch = 0
    end
    return tonumber(major) * 65536 + tonumber(minor) * 256 + tonumber(patch)
  end
end

local function parse_option_man(name)
  assert(name:find "^CURLM?OPT_")

  local doc_name = name
  local handle = io.open(source_dir .. "/docs/libcurl/opts/" .. doc_name .. ".3")
  if not handle then
    doc_name = alias_symbols[name]
    handle = assert(io.open(source_dir .. "/docs/libcurl/opts/" .. doc_name .. ".3"))
  end
  local doc = handle:read "*a"
  handle:close()

  local params
  if name:match("^CURLOPT_") then
    params = assert(doc:match "CURLcode%s+curl_easy_setopt%(%s*(.-)%)") .. ","
  elseif name:match("^CURLMOPT_") then
    params = assert(doc:match "CURLMcode%s+curl_multi_setopt%(%s*(.-)%)") .. ","
  end
  local items = {}
  for item in params:gmatch "(.-),%s*" do
    items[#items + 1] = item
  end
  assert(items[2] == doc_name)

  local param = items[3]:gsub("%s+", " ")
  local param_type, param_name = param:match "^([%w_]+) ([%w_]+)$"
  if not param_type then
    param_type, param_name = param:match "^(char %*%*)([%w_]+)$"
  end
  if not param_type then
    param_type, param_name = param:match "^([%w_]+ %*)([%w_]+)$"
  end
  if not param_type then
    param_type, param_name = param:match "^(struct [%w_]+ %*)([%w_]+)$"
  end
  if not param_type then
    param_type, param_name = param:match "^([%w_]+callback) ([%w_]+)$"
  end
  if not param_type then
    param_type, param_name = param:match "^([%w_]+callback)$"
  end
  if not param_type then
    param_type, param_name = param:match "^([%w_]+cb)$"
  end
  if not param_type then
    param_type = param_names[param]
    if param_type then
      param_name = param
    end
  end
  assert(param_type)
  if not param_name then
    param_name = ""
  end

  local param_enum
  if name:find "CURLOPT_" then
    param_enum = "easy_setopt_param_"
  else
    param_enum = "multi_setopt_param_"
  end
  if param_type:find "callback$" or param_type:find "cb$" then
    param_enum = param_enum .. "callback"
  else
    param_enum = param_enum .. param_type:gsub("%*", "p"):gsub(" ", "_")
  end

  return {
    name = name;
    doc_name = doc_name;
    param_type = param_type;
    param_name = param_name;
    param_enum = param_enum;
  }
end

--[[
https://curl.haxx.se/libcurl/c/curl_easy_setopt.html
> Before version 7.17.0, strings were not copied. Instead the user was forced
> keep them available until libcurl no longer needed them.
]]
local version_min = curl_version_bits "7.17.0"

local symbols_file = source_dir .. "/docs/libcurl/symbols-in-versions"
local easy_setopts = {}
local easy_setopt_enums = {}
local multi_setopts = {}
local multi_setopt_enums = {}
local form_codes = {}

local out = assert(io.open("symbols.cpp", "w"))

out:write [[
#include "common.hpp"
#include "symbols.hpp"

namespace dromozoa {
  void initialize_symbols(lua_State* L) {
]]

for line in io.lines(symbols_file) do
  if line:find "^CURL" then
    local items = {}
    for item in line:gmatch "%S+" do
      items[#items + 1] = item
    end
    local name, introduced, deprecated, removed = unpack(items)
    introduced = assert(curl_version_bits(introduced))
    deprecated = curl_version_bits(deprecated)
    removed = curl_version_bits(removed)
    if not ignore_symbols[name] and (not deprecated or deprecated > version_min) and (not removed or removed > version_min) then
      local option = {}
      if name:find "^CURLOPT_" then
        option = parse_option_man(name)
        easy_setopts[#easy_setopts + 1] = option
        easy_setopt_enums[option.param_enum] = true
      elseif name:find "^CURLMOPT_" then
        option = parse_option_man(name)
        multi_setopts[#multi_setopts + 1] = option
        multi_setopt_enums[option.param_enum] = true
      elseif name:find "^CURL_FORMADD_" then
        form_codes[#form_codes + 1] = name
      end

      local condition
      if introduced >= version_min then
        condition = ("0x%06x <= LIBCURL_VERSION_NUM"):format(introduced)
      end
      if removed then
        condition = condition .. " && " .. ("LIBCURL_VERSION_NUM < 0x%06x"):format(removed)
      end
      if condition then
        option.condition_begin = "#if " .. condition .. "\n"
        option.condition_end = "#endif\n"
      else
        option.condition_begin = ""
        option.condition_end = ""
      end

      out:write(option.condition_begin)
      out:write(([[    luaX_set_field<lua_Integer>(L, -1, "%s", %s);]]):format(name, name), "\n")
      out:write(option.condition_end)
    end
  end
end

out:write [[
  }

  easy_setopt_param_enum easy_setopt_param(CURLoption option) {
]]

for i = 1, #easy_setopts do
  local option = easy_setopts[i]
  out:write(option.condition_begin)
  out:write(("    if (option == %s) { return %s; }\n"):format(option.name, option.param_enum))
  out:write(option.condition_end)
end

out:write [[
    return easy_setopt_param_unknown;
  }

  multi_setopt_param_enum multi_setopt_param(CURLMoption option) {
]]

for i = 1, #multi_setopts do
  local option = multi_setopts[i]
  local condition = option.condition
  out:write(option.condition_begin)
  out:write(("    if (option == %s) { return %s; }\n"):format(option.name, option.param_enum))
  out:write(option.condition_end)
end

out:write [[
    return multi_setopt_param_unknown;
  }

  const char* error_to_string(CURLFORMcode code) {
    switch (code) {
]]

for i = 1, #form_codes do
  local name = form_codes[i]
  out:write(([[      case %s: return "%s";]]):format(name, name), "\n");
end

out:write [[
      default: return "CURLFORMcode unknown";
    }
  }
}
]]
out:close()

local out = assert(io.open("symbols.hpp", "w"))

out:write [[
#ifndef DROMOZOA_SYMBOLS_HPP
#define DROMOZOA_SYMBOLS_HPP

#include "common.hpp"

namespace dromozoa {
  enum easy_setopt_param_enum {
    easy_setopt_param_unknown,
]]

local enums = {}
for enum in pairs(easy_setopt_enums) do
  enums[#enums + 1] = enum
end
table.sort(enums)
for i = 1, #enums do
  out:write("    ", enums[i], ",\n")
end

out:write [[
  };

  enum multi_setopt_param_enum {
    multi_setopt_param_unknown,
]]

local enums = {}
for enum in pairs(multi_setopt_enums) do
  enums[#enums + 1] = enum
end
table.sort(enums)
for i = 1, #enums do
  out:write("    ", enums[i], ",\n")
end

out:write [[
  };

  void initialize_symbols(lua_State* L);
  easy_setopt_param_enum easy_setopt_param(CURLoption option);
  multi_setopt_param_enum multi_setopt_param(CURLMoption option);
  const char* error_to_string(CURLFORMcode code);
}

#endif
]]
out:close()

local out = assert(io.open("docs/option.html", "w"))

out:write [[
<!DOCTYPE html>
<html>
<head>
<meta charset="UTF-8">
<meta name="viewport" content="width=device-width, initial-scale=1, shrink-to-fit=no">
<title>dromozoa-curl</title>
<link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/github-markdown-css/2.10.0/github-markdown.min.css">
<style>
.markdown-body {
  box-sizing: border-box;
  min-width: 200px;
  max-width: 980px;
  margin: 0 auto;
  padding: 45px;
}
@media (max-width: 767px) {
  .markdown-body {
    padding: 15px;
  }
}
</style>
</head>
<body>
<div class="markdown-body">

<h1>dromozoa-curl</h1>

<h2>CURLOPT</h2>

<table>
  <tr>
    <th>Option Name</th>
    <th>Param Type</th>
    <th>Param Name</th>
  </tr>
]]

for i = 1, #easy_setopts do
  local option = easy_setopts[i]
  out:write(([[
  <tr>
    <td><a href="https://curl.haxx.se/libcurl/c/%s.html">%s</a></td>
    <td>%s</td>
    <td>%s</td>
  </tr>
]]):format(
    option.doc_name,
    option.name,
    option.param_type,
    option.param_name))
end

out:write [[
</table>

<h2>CURLMOPT</h2>

<table>
  <tr>
    <th>Option Name</th>
    <th>Param Type</th>
    <th>Param Name</th>
  </tr>
]]

for i = 1, #multi_setopts do
  local option = multi_setopts[i]
  out:write(([[
  <tr>
    <td><a href="https://curl.haxx.se/libcurl/c/%s.html">%s</a></td>
    <td>%s</td>
    <td>%s</td>
  </tr>
]]):format(
    option.doc_name,
    option.name,
    option.param_type,
    option.param_name))
end

out:write [[
</table>

</div>
</body>
</html>
]]

out:close()
