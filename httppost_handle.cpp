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

#include <stddef.h>

#include <vector>

#include "common.hpp"

namespace dromozoa {
  class httppost_handle_impl {
  public:
    static CURLFORMcode add_string(httppost_handle*, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      if (lua_isnoneornil(L, arg)) {
        return CURL_FORMADD_NULL;
      } else {
        add(forms, option, luaL_checkstring(L, arg));
        return CURL_FORMADD_OK;
      }
    }

    static CURLFORMcode add_string(httppost_handle*, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option, CURLformoption option_length) {
      if (lua_isnoneornil(L, arg)) {
        return CURL_FORMADD_NULL;
      } else {
        size_t length = 0;
        add(forms, option, luaL_checklstring(L, arg, &length));
        add(forms, option_length, length);
        return CURL_FORMADD_OK;
      }
    }

    static CURLFORMcode add_string_ref(httppost_handle* self, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      if (lua_isnoneornil(L, arg)) {
        return CURL_FORMADD_NULL;
      } else {
        const char* ptr = luaL_checkstring(L, arg);
        self->new_reference(L, arg);
        add(forms, option, ptr);
        return CURL_FORMADD_OK;
      }
    }

    static CURLFORMcode add_string_ref(httppost_handle* self, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option, CURLformoption option_length) {
      if (lua_isnoneornil(L, arg)) {
        return CURL_FORMADD_NULL;
      } else {
        size_t length = 0;
        const char* ptr = luaL_checklstring(L, arg, &length);
        self->new_reference(L, arg);
        add(forms, option, ptr);
        add(forms, option_length, length);
        return CURL_FORMADD_OK;
      }
    }

    template <class T>
    static CURLFORMcode add_integer(httppost_handle*, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      add(forms, option, luaX_check_integer<T>(L, arg));
      return CURL_FORMADD_OK;
    }

    static CURLFORMcode add_function_ref(httppost_handle* self, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      if (lua_isnoneornil(L, arg)) {
        return CURL_FORMADD_NULL;
      } else {
        luaX_reference<>* ref = self->new_reference(L, arg);
        add(forms, option, ref);
        ++self->stream_;
        return CURL_FORMADD_OK;
      }
    }

    static CURLFORMcode add_slist(httppost_handle* self, std::vector<struct curl_forms>& forms, lua_State* L, int arg, CURLformoption option) {
      if (!lua_isnoneornil(L, arg)) {
        luaL_checktype(L, arg, LUA_TTABLE);
        string_list list(L, arg);
        if (struct curl_slist* slist = list.get()) {
          self->save_slist(slist);
          list.release();
          add(forms, option, slist);
          return CURL_FORMADD_OK;
        }
      }
      return CURL_FORMADD_NULL;
    }

  private:
    static void add(std::vector<struct curl_forms>& forms, CURLformoption option, const char* value) {
      struct curl_forms f = { option, const_cast<char*>(value) };
      forms.push_back(f);
    }

    template <class T>
    static void add(std::vector<struct curl_forms>& forms, CURLformoption option, const T& value) {
      struct curl_forms f = { option, reinterpret_cast<char*>(value) };
      forms.push_back(f);
    }
  };

  httppost_handle::httppost_handle() : first_(), last_(), stream_() {}

  httppost_handle::~httppost_handle() {
    if (first_) {
      free();
    }
  }

  void httppost_handle::free() {
    stream_ = 0;

    {
      std::set<struct curl_slist*>::iterator i = slists_.begin();
      std::set<struct curl_slist*>::iterator end = slists_.end();
      for (; i != end; ++i) {
        curl_slist_free_all(*i);
      }
      slists_.clear();
    }

    {
      std::set<luaX_binder*>::iterator i = references_.begin();
      std::set<luaX_binder*>::iterator end = references_.end();
      for (; i != end; ++i) {
        delete *i;
      }
      references_.clear();
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
        case CURLFORM_COPYNAME:
          result = httppost_handle_impl::add_string(this, forms, L, arg + 1, option, CURLFORM_NAMELENGTH);
          break;

        case CURLFORM_PTRNAME:
          result = httppost_handle_impl::add_string_ref(this, forms, L, arg + 1, option, CURLFORM_NAMELENGTH);
          break;

        case CURLFORM_COPYCONTENTS:
#if CURL_AT_LEAST_VERSION(7,46,0)
          result = httppost_handle_impl::add_string(this, forms, L, arg + 1, option, CURLFORM_CONTENTLEN);
#else
          result = httppost_handle_impl::add_string(this, forms, L, arg + 1, option, CURLFORM_CONTENTSLENGTH);
#endif
          break;

        case CURLFORM_PTRCONTENTS:
#if CURL_AT_LEAST_VERSION(7,46,0)
          result = httppost_handle_impl::add_string_ref(this, forms, L, arg + 1, option, CURLFORM_CONTENTLEN);
#else
          result = httppost_handle_impl::add_string_ref(this, forms, L, arg + 1, option, CURLFORM_CONTENTSLENGTH);
#endif
          break;

#if CURL_AT_LEAST_VERSION(7,46,0)
        case CURLFORM_CONTENTLEN:
#endif
        case CURLFORM_CONTENTSLENGTH:
          result = httppost_handle_impl::add_integer<size_t>(this, forms, L, arg + 1, option);
          break;

        case CURLFORM_FILECONTENT:
        case CURLFORM_FILE:
        case CURLFORM_CONTENTTYPE:
        case CURLFORM_FILENAME:
        case CURLFORM_BUFFER:
          result = httppost_handle_impl::add_string(this, forms, L, arg + 1, option);
          break;

        case CURLFORM_BUFFERPTR:
          result = httppost_handle_impl::add_string_ref(this, forms, L, arg + 1, option, CURLFORM_BUFFERLENGTH);
          break;

#if CURL_AT_LEAST_VERSION(7,18,2)
        case CURLFORM_STREAM:
          result = httppost_handle_impl::add_function_ref(this, forms, L, arg + 1, option);
          break;
#endif

        case CURLFORM_CONTENTHEADER:
          result = httppost_handle_impl::add_slist(this, forms, L, arg + 1, option);
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

  int httppost_handle::stream() const {
    return stream_;
  }

  luaX_reference<>* httppost_handle::new_reference(lua_State* L, int index) {
    luaX_reference<>* reference = 0;
    try {
      reference = new luaX_reference<>(L, index);
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
}
