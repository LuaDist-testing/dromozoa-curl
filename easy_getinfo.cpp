// Copyright (C) 2017 Tomoyuki Fujimori <moyu@dromozoa.com>
//
// This file is part of dromozoa-curl.
//
// dromozoa-curl is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// dromozoa-curl is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with dromozoa-curl.  If not, see <http://www.gnu.org/licenses/>.

#include "common.hpp"

namespace dromozoa {
  namespace {
    template <class T>
    void getinfo(lua_State* L, CURLINFO info) {
      T value = 0;
      CURLcode result = curl_easy_getinfo(check_easy(L, 1), info, &value);
      if (result == CURLE_OK) {
        luaX_push(L, value);
      } else {
        push_error(L, result);
      }
    }

    void getinfo_slist(lua_State* L, CURLINFO info) {
      struct curl_slist* slist = 0;
      CURLcode result = curl_easy_getinfo(check_easy(L, 1), info, &slist);
      if (result == CURLE_OK) {
        string_list list(slist);
        lua_newtable(L);
        struct curl_slist* item = list.get();
        for (int i = 1; item; ++i) {
          luaX_set_field(L, -1, i, item->data);
          item = item->next;
        }
      } else {
        push_error(L, result);
      }
    }

    void getinfo_certinfo(lua_State* L, CURLINFO info) {
      struct curl_certinfo* certinfo = 0;
      CURLcode result = curl_easy_getinfo(check_easy(L, 1), info, &certinfo);
      if (result == CURLE_OK) {
        lua_newtable(L);
        for (int i = 0; i < certinfo->num_of_certs; ++i) {
          lua_newtable(L);
          struct curl_slist* item = certinfo->certinfo[i];
          for (int j = 1; item; ++j) {
            luaX_set_field(L, -1, j, item->data);
            item = item->next;
          }
          luaX_set_field(L, -2, i + 1);
        }
      } else {
        push_error(L, result);
      }
    }

    void impl_getinfo(lua_State* L) {
      CURLINFO info = luaX_check_enum<CURLINFO>(L, 2);
      switch (info & CURLINFO_TYPEMASK) {
        case CURLINFO_STRING:
          getinfo<const char*>(L, info);
          return;
        case CURLINFO_LONG:
          getinfo<long>(L, info);
          return;
        case CURLINFO_DOUBLE:
          getinfo<double>(L, info);
          return;
        case CURLINFO_SLIST:
          switch (info) {
            case CURLINFO_CERTINFO:
              getinfo_certinfo(L, info);
              return;
#if CURL_AT_LEAST_VERSION(7,34,0)
            case CURLINFO_TLS_SESSION:
#if CURL_AT_LEAST_VERSION(7,48,0)
            case CURLINFO_TLS_SSL_PTR:
#endif
              push_error(L, CURLE_UNKNOWN_OPTION);
              return;
#endif
            default:
              getinfo_slist(L, info);
              return;
          }
          return;
#if CURL_AT_LEAST_VERSION(7,45,0)
        case CURLINFO_SOCKET:
          getinfo<curl_socket_t>(L, info);
          return;
#endif
        default:
          push_error(L, CURLE_UNKNOWN_OPTION);
      }
    }
  }

  void initialize_easy_getinfo(lua_State* L) {
    luaX_set_field(L, -1, "getinfo", impl_getinfo);
  }
}
