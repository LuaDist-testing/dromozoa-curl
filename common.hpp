// Copyright (C) 2017,2018 Tomoyuki Fujimori <moyu@dromozoa.com>
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

#ifndef DROMOZOA_COMMON_HPP
#define DROMOZOA_COMMON_HPP

#include <map>
#include <set>

#include <curl/curl.h>

#ifndef CURL_VERSION_BITS
#define CURL_VERSION_BITS(x, y, z) ((x) << 16 | (y) << 8 | (z))
#endif

#ifndef CURL_AT_LEAST_VERSION
#define CURL_AT_LEAST_VERSION(x, y, z) (LIBCURL_VERSION_NUM >= CURL_VERSION_BITS(x, y, z))
#endif

#if !CURL_AT_LEAST_VERSION(7,17,0)
#error libcurl 7.17.0 or newer is required
#endif

#if !CURL_AT_LEAST_VERSION(7,21,5)
#define CURLE_UNKNOWN_OPTION CURLE_BAD_FUNCTION_ARGUMENT
#endif

#if !CURL_AT_LEAST_VERSION(7,32,1)
#define CURLM_ADDED_ALREADY CURLM_BAD_EASY_HANDLE
#endif

#include <dromozoa/bind.hpp>

namespace dromozoa {
  class string_list {
  public:
    explicit string_list(struct curl_slist* slist);
    string_list(lua_State* L, int index);
    ~string_list();
    struct curl_slist* get() const;
    struct curl_slist* release();
  private:
    struct curl_slist* slist_;
    string_list(const string_list&);
    string_list& operator=(const string_list&);
  };

  class httppost_handle {
  public:
    httppost_handle();
    ~httppost_handle();
    void free();
    CURLFORMcode add(lua_State* L);
    struct curl_httppost* get() const;
    int stream() const;
  private:
    friend class httppost_handle_impl;
    struct curl_httppost* first_;
    struct curl_httppost* last_;
    std::set<luaX_reference<>*> references_;
    std::set<struct curl_slist*> slists_;
    int stream_;
    httppost_handle(const httppost_handle&);
    httppost_handle& operator=(const httppost_handle&);
    luaX_reference<>* new_reference(lua_State* L, int index);
    void save_slist(struct curl_slist* slist);
  };

  httppost_handle* check_httppost_handle(lua_State* L, int arg);

  class multi_handle;

  class easy_handle {
  public:
    explicit easy_handle(CURL* handle);
    ~easy_handle();
    void reset();
    void cleanup();
    CURL* get() const;
  private:
    friend class easy_handle_impl;
    friend class multi_handle;
    CURL* handle_;
    multi_handle* multi_handle_;
    std::map<CURLoption, luaX_reference<>*> references_;
    std::map<CURLoption, struct curl_slist*> slists_;
    easy_handle(const easy_handle&);
    easy_handle& operator=(const easy_handle&);
    void clear();
    luaX_reference<>* new_reference(CURLoption option, lua_State* L, int index);
    void delete_reference(CURLoption option);
    void save_slist(CURLoption option, struct curl_slist* slist);
    void free_slist(CURLoption option);
  };

  easy_handle* check_easy_handle(lua_State* L, int arg);
  CURL* check_easy(lua_State* L, int arg);
  void new_easy_ref(lua_State* L, CURL* handle);

  class multi_handle {
  public:
    explicit multi_handle(CURLM* handle);
    ~multi_handle();
    CURLMcode cleanup();
    CURLMcode add_handle(lua_State* L, int index);
    CURLMcode remove_handle(easy_handle* that);
    CURLM* get() const;
  private:
    friend class multi_handle_impl;
    CURLM* handle_;
    std::map<CURLMoption, luaX_reference<>*> references_;
    std::map<easy_handle*, luaX_reference<>*> easy_handles_;
    multi_handle(const multi_handle&);
    multi_handle& operator=(const multi_handle&);
    luaX_reference<>* new_reference(CURLMoption option, lua_State* L, int index);
    void delete_reference(CURLMoption option);
  };

  multi_handle* check_multi_handle(lua_State* L, int arg);
  void new_multi_ref(lua_State* L, CURLM* handle);

  void push_error(lua_State* L, CURLcode code);
  void push_error(lua_State* L, CURLMcode code);
  void push_error(lua_State* L, CURLFORMcode code);
}

#endif
