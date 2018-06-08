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

#include <vector>

#include "common.hpp"

namespace dromozoa {
  namespace {
    void save_forms(std::vector<struct curl_forms>& forms, CURLformoption option, const char* value) {
      struct curl_forms f = { option, const_cast<char*>(value) };
      forms.push_back(f);
    }

    void save_forms(std::vector<struct curl_forms>& forms, CURLformoption option, size_t value) {
      struct curl_forms f = { option, reinterpret_cast<char*>(value) };
      forms.push_back(f);
    }

    void save_forms(std::vector<struct curl_forms>& forms, CURLformoption option, luaX_reference* value) {
      struct curl_forms f = { option, reinterpret_cast<char*>(value) };
      forms.push_back(f);
    }

    void save_forms(std::vector<struct curl_forms>& forms, CURLformoption option, struct curl_slist* value) {
      struct curl_forms f = { option, reinterpret_cast<char*>(value) };
      forms.push_back(f);
    }

    CURLFORMcode save_forms_string(std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      if (const char* p = lua_tostring(L, arg)) {
        save_forms(forms, option, p);
        return CURL_FORMADD_OK;
      } else {
        return CURL_FORMADD_NULL;
      }
    }

    CURLFORMcode save_forms_string(std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option, CURLformoption option_length) {
      size_t length = 0;
      if (const char* p = lua_tolstring(L, arg, &length)) {
        save_forms(forms, option, p);
        save_forms(forms, option_length, length);
        return CURL_FORMADD_OK;
      } else {
        return CURL_FORMADD_NULL;
      }
    }

    template <class T>
    CURLFORMcode save_forms_integer(std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      save_forms(forms, option, luaX_check_integer<T>(L, arg));
      return CURL_FORMADD_OK;
    }

    CURLFORMcode save_forms_function(std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      httppost_handle* self = check_httppost_handle(L, 1);
      lua_pushvalue(L, arg);
      luaX_reference* ref = self->new_reference(L);
      save_forms(forms, option, ref);
      return CURL_FORMADD_OK;
    }

    CURLFORMcode save_forms_slist(std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      string_list list(L, arg);
      if (list.get()) {
        httppost_handle* self = check_httppost_handle(L, 1);
        self->save_slist(list.get());
        save_forms(forms, option, list.release());
        return CURL_FORMADD_OK;
      } else {
        return CURL_FORMADD_NULL;
      }
    }
  }

  httppost_handle::httppost_handle() : first_(), last_() {}

  httppost_handle::~httppost_handle() {
    if (first_) {
      free();
    }
  }

  void httppost_handle::free() {
    {
      std::set<luaX_reference*>::iterator i = references_.begin();
      std::set<luaX_reference*>::iterator end = references_.end();
      for (; i != end; ++i) {
        delete *i;
      }
      references_.clear();
    }

    {
      std::set<struct curl_slist*>::iterator i = slists_.begin();
      std::set<struct curl_slist*>::iterator end = slists_.end();
      for (; i != end; ++i) {
        curl_slist_free_all(*i);
      }
      slists_.clear();
    }

    struct curl_httppost* first = first_;
    first_ = 0;
    last_ = 0;
    curl_formfree(first);
  }

  CURLFORMcode httppost_handle::add(lua_State* L) {
    std::vector<struct curl_forms> forms;
    int top = lua_gettop(L);
    for (int arg = 2; arg <= top; arg += 2) {
      CURLformoption option = luaX_check_enum<CURLformoption>(L, arg);
      if (option == CURLFORM_END) {
        break;
      }
      CURLFORMcode result = CURL_FORMADD_OK;
      switch (option) {
        case CURLFORM_FILECONTENT:
        case CURLFORM_FILE:
        case CURLFORM_CONTENTTYPE:
        case CURLFORM_FILENAME:
        case CURLFORM_BUFFER:
          result = save_forms_string(forms, L, arg + 1, option);
          break;
        case CURLFORM_COPYNAME:
          result = save_forms_string(forms, L, arg + 1, option, CURLFORM_NAMELENGTH);
          break;
        case CURLFORM_COPYCONTENTS:
#if CURL_AT_LEAST_VERSION(7,46,0)
          result = save_forms_string(forms, L, arg + 1, option, CURLFORM_CONTENTLEN);
#else
          result = save_forms_string(forms, L, arg + 1, option, CURLFORM_CONTENTSLENGTH);
#endif
          break;
        case CURLFORM_BUFFERPTR:
          result = save_forms_string(forms, L, arg + 1, option, CURLFORM_BUFFERLENGTH);
          break;
#if CURL_AT_LEAST_VERSION(7,46,0)
        case CURLFORM_CONTENTLEN:
#endif
        case CURLFORM_CONTENTSLENGTH:
          result = save_forms_integer<size_t>(forms, L, arg + 1, option);
          break;
#if CURL_AT_LEAST_VERSION(7,18,2)
        case CURLFORM_STREAM:
          result = save_forms_function(forms, L, arg + 1, option);
          break;
#endif
        case CURLFORM_CONTENTHEADER:
          result = save_forms_slist(forms, L, arg + 1, option);
          break;
        default:
          result = CURL_FORMADD_UNKNOWN_OPTION;
      }
      if (result != CURL_FORMADD_OK) {
        return result;
      }
    }
    struct curl_forms f = { CURLFORM_END, 0 };
    forms.push_back(f);
    return curl_formadd(&first_, &last_, CURLFORM_ARRAY, &forms[0], CURLFORM_END);
  }

  struct curl_httppost* httppost_handle::get() const {
    return first_;
  }

  luaX_reference* httppost_handle::new_reference(lua_State* L) {
    luaX_reference* reference = 0;
    try {
      reference = new luaX_reference(L);
      references_.insert(reference);
      return reference;
    } catch (...) {
      delete reference;
      throw;
    }
  }

  void httppost_handle::save_slist(struct curl_slist* slist) {
    slists_.insert(slist);
  }

  bool httppost_handle::have_stream() const {
    return !references_.empty();
  }
}
