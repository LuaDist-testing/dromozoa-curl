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
  easy_handle::easy_handle(CURL* handle) : handle_(handle) {}

  easy_handle::~easy_handle() {
    if (handle_) {
      cleanup();
    }
  }

  void easy_handle::reset() {
    clear();
    curl_easy_reset(handle_);
  }

  void easy_handle::cleanup() {
    clear();
    CURL* handle = handle_;
    handle_ = 0;
    curl_easy_cleanup(handle);
  }

  CURL* easy_handle::get() const {
    return handle_;
  }

  luaX_reference<>* easy_handle::new_reference(CURLoption option, lua_State* L, int index) {
    luaX_reference<>* reference = 0;
    try {
      reference = new luaX_reference<>(L, index);
      std::map<CURLoption, luaX_binder*>::iterator i = references_.find(option);
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

  void easy_handle::save_slist(CURLoption option, struct curl_slist* slist) {
    std::map<CURLoption, struct curl_slist*>::iterator i = slists_.find(option);
    if (i == slists_.end()) {
      slists_.insert(std::make_pair(option, slist));
    } else {
      curl_slist_free_all(i->second);
      i->second = slist;
    }
  }

  void easy_handle::clear() {
    {
      std::map<CURLoption, luaX_binder*>::iterator i = references_.begin();
      std::map<CURLoption, luaX_binder*>::iterator end = references_.end();
      for (; i != end; ++i) {
        delete i->second;
      }
      references_.clear();
    }

    {
      std::map<CURLoption, struct curl_slist*>::iterator i = slists_.begin();
      std::map<CURLoption, struct curl_slist*>::iterator end = slists_.end();
      for (; i != end; ++i) {
        curl_slist_free_all(i->second);
      }
      slists_.clear();
    }
  }
}
