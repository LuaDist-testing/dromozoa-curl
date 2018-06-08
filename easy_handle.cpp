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
  easy_handle::easy_handle(CURL* handle) : handle_(handle), multi_handle_() {}

  easy_handle::~easy_handle() {
    if (handle_) {
      cleanup();
    }
  }

  void easy_handle::reset() {
    curl_easy_reset(handle_);
    clear();
  }

  void easy_handle::cleanup() {
    if (multi_handle_) {
      CURLMcode result = multi_handle_->remove_handle(this);
      if (result != CURLM_OK) {
        DROMOZOA_UNEXPECTED(curl_multi_strerror(result));
      }
    }

    CURL* handle = handle_;
    handle_ = 0;
    curl_easy_cleanup(handle);

    clear();
  }

  CURL* easy_handle::get() const {
    return handle_;
  }

  void easy_handle::clear() {
    {
      std::map<CURLoption, luaX_reference<>*>::iterator i = references_.begin();
      std::map<CURLoption, luaX_reference<>*>::iterator end = references_.end();
      for (; i != end; ++i) {
        scoped_ptr<luaX_reference<> > deleter(i->second);
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

  luaX_reference<>* easy_handle::new_reference(CURLoption option, lua_State* L, int index) {
    scoped_ptr<luaX_reference<> > reference(new luaX_reference<>(L, index));
    std::map<CURLoption, luaX_reference<>*>::iterator i = references_.find(option);
    if (i == references_.end()) {
      references_.insert(std::make_pair(option, reference.get()));
    } else {
      scoped_ptr<luaX_reference<> > deleter(i->second);
      i->second = reference.get();
    }
    return reference.release();
  }

  void easy_handle::delete_reference(CURLoption option) {
    std::map<CURLoption, luaX_reference<>*>::iterator i = references_.find(option);
    if (i != references_.end()) {
      scoped_ptr<luaX_reference<> > deleter(i->second);
      references_.erase(i);
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

  void easy_handle::free_slist(CURLoption option) {
    std::map<CURLoption, struct curl_slist*>::iterator i = slists_.find(option);
    if (i != slists_.end()) {
      curl_slist_free_all(i->second);
      slists_.erase(i);
    }
  }
}
