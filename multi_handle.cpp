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

#include "common.hpp"

namespace dromozoa {
  multi_handle::multi_handle(CURLM* handle) : handle_(handle) {}

  multi_handle::~multi_handle() {
    if (handle_) {
      cleanup();
    }
  }

  CURLMcode multi_handle::cleanup() {
    {
      std::map<CURLMoption, luaX_binder*>::iterator i = references_.begin();
      std::map<CURLMoption, luaX_binder*>::iterator end = references_.end();
      for (; i != end; ++i) {
        delete i->second;
      }
      references_.clear();
    }

    {
      std::map<easy_handle*, luaX_binder*>::iterator i = easy_handles_.begin();
      std::map<easy_handle*, luaX_binder*>::iterator end = easy_handles_.end();
      for (; i != end; ++i) {
        easy_handle* that = i->first;
        CURLMcode result = curl_multi_remove_handle(handle_, that->get());
        if (result != CURLM_OK) {
          DROMOZOA_UNEXPECTED(curl_multi_strerror(result));
        }
        that->multi_handle_ = 0;
        delete i->second;
      }
      easy_handles_.clear();
    }

    CURLM* handle = handle_;
    handle_ = 0;
    return curl_multi_cleanup(handle);
  }

  CURLMcode multi_handle::add_handle(lua_State* L, int index) {
    easy_handle* that = check_easy_handle(L, index);
    if (that->multi_handle_) {
      return CURLM_ADDED_ALREADY;
    }

    std::map<easy_handle*, luaX_binder*>::iterator i = easy_handles_.find(that);
    if (i != easy_handles_.end()) {
      return CURLM_ADDED_ALREADY;
    }

    luaX_reference<>* reference = 0;
    try {
      reference = new luaX_reference<>(L, index);
      easy_handles_.insert(std::make_pair(that, reference));
    } catch (...) {
      delete reference;
      throw;
    }

    CURLMcode result = curl_multi_add_handle(handle_, that->get());
    if (result == CURLM_OK) {
      that->multi_handle_ = this;
    }

    return result;
  }

  CURLMcode multi_handle::remove_handle(easy_handle* that) {
    if (!that->multi_handle_) {
      return CURLM_OK;
    }

    std::map<easy_handle*, luaX_binder*>::iterator i = easy_handles_.find(that);
    if (i == easy_handles_.end()) {
      return CURLM_OK;
    }

    CURLMcode result = curl_multi_remove_handle(handle_, that->get());
    if (result == CURLM_OK) {
      that->multi_handle_ = 0;
      delete i->second;
      easy_handles_.erase(i);
    }

    return result;
  }

  CURLM* multi_handle::get() const {
    return handle_;
  }

  luaX_reference<>* multi_handle::new_reference(CURLMoption option, lua_State* L, int index) {
    luaX_reference<>* reference = 0;
    try {
      reference = new luaX_reference<>(L, index);
      std::map<CURLMoption, luaX_binder*>::iterator i = references_.find(option);
      if (i == references_.end()) {
        references_.insert(std::make_pair(option, reference));
      } else {
        delete i->second;
        i->second = reference;
      }
      return reference;
    } catch (...) {
      delete reference;
      throw;
    }
  }

  void multi_handle::delete_reference(CURLMoption option) {
    std::map<CURLMoption, luaX_binder*>::iterator i = references_.find(option);
    if (i != references_.end()) {
      delete i->second;
      references_.erase(i);
    }
  }
}
