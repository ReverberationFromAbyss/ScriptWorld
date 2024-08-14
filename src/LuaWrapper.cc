
module;

#ifdef __cplusplus
extern "C" {
#endif // ! __cplusplus
namespace lua {

#include "lauxlib.h"
#include "lualib.h"

#include "lua.h"

}; // namespace lua

#ifdef __cplusplus
}
#endif // ! __cplusplus

export module LuaWrapper;
import std;

export namespace lua {

using lua::lua_State;

auto lua_open = lua::luaL_newstate;

// using lua::luaL_loadbuffer;
// using lua::luaL_loadfile;
// using lua::luaL_loadstring;
// using lua::luaL_openlib;
// using lua::luaL_openlibs;

// using lua::lua_close;
// using lua::luaL_newstate;

// using lua::lua_call;
// using lua::lua_cpcall;
// using lua::lua_load;
// using lua::lua_pcall;

// using lua::lua_getfield;
// using lua::lua_setfield;

// auto lua_getglobal = [](lua_State *L, const char *name) {
//   return lua_getfield(L, LUA_GLOBALSINDEX, name);
// };
//::std::function<void(lua_State *L, const char *name)> lua_setglobal =
//    [](lua_State *L, const char *name) {
//      lua_setfield(L, LUA_GLOBALSINDEX, name);
//    };

// using lua::lua_gettop;
// using lua::lua_settop;

// using lua::lua_insert;
// using lua::lua_pushvalue;
// using lua::lua_remove;
// using lua::lua_replace;

// using lua::lua_gettable;
// using lua::lua_settable;

// using lua::lua_concat;

// using lua::lua_type;
// using lua::lua_typename;

// using lua::lua_checkstack;

// using lua::lua_iscfunction;
// using lua::lua_isnumber;
// using lua::lua_isstring;
// using lua::lua_isuserdata;

// auto lua_isfunction = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TFUNCTION;
// };
// auto lua_istable = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TTABLE;
// };
// auto lua_islightuserdata = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TLIGHTUSERDATA;
// };
// auto lua_isnil = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TNIL;
// };
// auto lua_isboolean = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TBOOLEAN;
// };
// auto lua_isthread = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TTHREAD;
// };
// auto lua_isnone = [](lua_State *L, int index) {
//   return lua_type(L, (index)) == LUA_TNONE;
// };
// auto lua_isnoneornil = [](lua_State *L, int index) {
//   return lua_type(L, (index)) <= 0;
// };

// using lua::lua_equal;
// using lua::lua_lessthan;
// using lua::lua_rawequal;

// using lua::lua_toboolean;
// using lua::lua_tocfunction;
// using lua::lua_tointeger;
// using lua::lua_tolstring;
// using lua::lua_tonumber;
// using lua::lua_topointer;
// using lua::lua_tothread;
// auto lua_tostring = [](lua_State *L, int i) {
//  return lua_tolstring(L, i, NULL);
//};

// using lua::lua_pushboolean;
// using lua::lua_pushcclosure;
// auto lua_pushcfunction = [](lua_State *L, lua_CFunction f) {
//  lua_pushcclosure(L, (f), 0);
//};
// using lua::lua_pushfstring;
// using lua::lua_pushinteger;
#undef lua_pushliteral
void lua_pushliteral(lua_State *L, const char *s) {
  return lua_pushlstring(L, s, ::std::string(s).size() - 1);
};
// using lua::lua_pushlstring;
// using lua::lua_pushnil;
// using lua::lua_pushnumber;
// using lua::lua_pushstring;
// using lua::lua_pushvfstring;

// using lua::luaL_register;
#undef lua_register
void lua_register(lua_State *L, const char *n, lua_CFunction f) {
  return (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)));
};

// using lua::luaL_Reg;

// using lua::luaopen_base;
// using lua::luaopen_debug;
// using lua::luaopen_io;
// using lua::luaopen_math;
// using lua::luaopen_os;
// using lua::luaopen_package;
// using lua::luaopen_string;
// using lua::luaopen_table;

// using lua::luaL_addlstring;
// using lua::luaL_addstring;
// using lua::luaL_addvalue;
// using lua::luaL_argerror;
// using lua::luaL_buffinit;
// using lua::luaL_callmeta;
// using lua::luaL_checkany;
// using lua::luaL_checkstack;
// using lua::luaL_checktype;
// using lua::luaL_checkudata;
// using lua::luaL_error;
// using lua::luaL_findtable;
// using lua::luaL_gsub;
// using lua::luaL_optnumber;
// using lua::luaL_ref;
// using lua::luaL_register;
// using lua::luaL_typerror;
// using lua::luaL_unref;
// using lua::luaL_where;
// auto luaL_addchar = [](lua::luaL_Buffer *B, char c) {
//  return ((void)((B)->p < ((B)->buffer + LUAL_BUFFERSIZE) ||
//  luaL_prepbuffer(B)),
//   (*(B)->p++ = (char)(c)));
//};
// using lua::luaL_addlstring;
// auto luaL_addsize = [](lua::luaL_Buffer *B, size_t n) {
//  return ((B)->p += (n));
//};
// using lua::luaL_addstring;
// using lua::luaL_addvalue;
// auto luaL_argcheck = [](lua_State *L, int cond, int numarg,
//                        const char *extramsg) {
//  return ((void)((cond) || luaL_argerror(L, (numarg), (extramsg))));
//};
// using lua::luaL_argerror;
// using lua::luaL_Buffer;
// using lua::luaL_buffinit;
// using lua::luaL_callmeta;
// using lua::luaL_checkany;
// using lua::luaL_checkinteger;
// auto luaL_checkint = [](lua_State *L, int n) {
//  return ((int)luaL_checkinteger(L, (n)));
//};
// auto luaL_checklong = [](lua_State *L, int n) {
//  return ((long)luaL_checkinteger(L, (n)));
//};
// using lua::luaL_checklstring;
// using lua::luaL_checknumber;
// using lua::luaL_checkoption;
// using lua::luaL_checkstack;
// auto luaL_checkstring = [](lua_State *L, int n) {
//  return (luaL_checklstring(L, (n), NULL));
//};
// using lua::luaL_checktype;
// using lua::luaL_checkudata;
// auto luaL_dofile = [](lua_State *L, const char *fn) {
//  return (luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0));
//};
// auto luaL_dostring = [](lua_State *L, const char *s) {
//  return (luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0));
//};
// using lua::lua_getmetatable;
// using lua::luaL_error;
// using lua::luaL_getmetafield;
// using lua::luaL_gsub;
// using lua::luaL_loadbuffer;
// using lua::luaL_loadfile;
// using lua::luaL_loadstring;
// using lua::luaL_newmetatable;
// using lua::luaL_optinteger;
// auto luaL_optint = [](lua_State *L, int n, lua_Integer d) {
//  return ((int)luaL_optinteger(L, (n), (d)));
//};
// auto luaL_optlong = [](lua_State *L, int n, long d) {
//  return ((long)luaL_optinteger(L, (n), (d)));
//};
// using lua::luaL_optlstring;
// using lua::luaL_optnumber;
// auto luaL_optstring = [](lua_State *L, int n, const char *d) {
//  return (luaL_optlstring(L, (n), (d), NULL));
//};
// using lua::luaL_prepbuffer;
// using lua::luaL_pushresult;
// using lua::luaL_ref;
// using lua::luaL_Reg;
// using lua::luaL_register;
// auto luaL_typename = [](lua_State *L, int i) {
//  return lua_typename(L, lua_type(L, (i)));
//};
// using lua::luaL_typerror;
// using lua::luaL_unref;
// using lua::luaL_where;
//

constexpr const auto Lua_Globalsindex{LUA_GLOBALSINDEX};
constexpr const auto Lua_Environindex{LUA_ENVIRONINDEX};
constexpr const auto Lua_Registryindex{LUA_REGISTRYINDEX};
auto Lua_Upvalueindex = [](int i) { return (LUA_GLOBALSINDEX - (i)); };

constexpr const auto Lua_Yield{LUA_YIELD};
constexpr const auto Lua_Errrun{LUA_ERRRUN};
constexpr const auto Lua_Errsyntax{LUA_ERRSYNTAX};
constexpr const auto Lua_Errmem{LUA_ERRMEM};
constexpr const auto Lua_Errerr{LUA_ERRERR};

/* mark for precompiled code (`<esc>Lua') */
constexpr const auto Lua_Signature{LUA_SIGNATURE};

/* option for multiple returns in `lua_pcall' and `lua_call' */
constexpr const auto Lua_Multret{LUA_MULTRET};

constexpr const auto Lua_Tnone{LUA_TNONE};

constexpr const auto Lua_Tnil{LUA_TNIL};
constexpr const auto Lua_Tboolean{LUA_TBOOLEAN};
constexpr const auto Lua_Tlightuserdata{LUA_TLIGHTUSERDATA};
constexpr const auto Lua_Tnumber{LUA_TNUMBER};
constexpr const auto Lua_Tstring{LUA_TSTRING};
constexpr const auto Lua_Ttable{LUA_TTABLE};
constexpr const auto Lua_Tfunction{LUA_TFUNCTION};
constexpr const auto Lua_Tuserdata{LUA_TUSERDATA};
constexpr const auto Lua_Tthread{LUA_TTHREAD};

constexpr const auto Lua_Minstack{LUA_MINSTACK};

constexpr const auto Lua_GCstop{LUA_GCSTOP};
constexpr const auto Lua_GCrestart{LUA_GCRESTART};
constexpr const auto Lua_GCcollect{LUA_GCCOLLECT};
constexpr const auto Lua_GCcount{LUA_GCCOUNT};
constexpr const auto Lua_GCcountb{LUA_GCCOUNTB};
constexpr const auto Lua_GCstep{LUA_GCSTEP};
constexpr const auto Lua_GCsetpause{LUA_GCSETPAUSE};
constexpr const auto Lua_GCsetstepmul{LUA_GCSETSTEPMUL};

constexpr const auto Lua_HOOKcall{LUA_HOOKCALL};
constexpr const auto Lua_HOOKret{LUA_HOOKRET};
constexpr const auto Lua_HOOKline{LUA_HOOKLINE};
constexpr const auto Lua_HOOKcount{LUA_HOOKCOUNT};
constexpr const auto Lua_HOOKtailret{LUA_HOOKTAILRET};

/*
** Event masks
*/
auto Lua_MASKcall = []() { return (1 << LUA_HOOKCALL); };
auto Lua_MASKret = []() { return (1 << LUA_HOOKRET); };
auto Lua_MASKline = []() { return (1 << LUA_HOOKLINE); };
auto Lua_MASKcount = []() { return (1 << LUA_HOOKCOUNT); };

using lua::lua_Alloc;
using lua::lua_atpanic;
using lua::lua_call;
using lua::lua_CFunction;
using lua::lua_checkstack;
using lua::lua_close;
using lua::lua_concat;
using lua::lua_cpcall;
using lua::lua_createtable;
using lua::lua_dump;
using lua::lua_equal;
using lua::lua_gc;
using lua::lua_getallocf;
using lua::lua_getfenv;
using lua::lua_getfield;
#undef lua_getglobal
void lua_getglobal(lua_State *L, const char *name) {
  return lua_getfield(L, LUA_GLOBALSINDEX, name);
};
// using lua::lua_getglobal;
using lua::lua_getmetatable;
using lua::lua_gettable;
using lua::lua_gettop;
using lua::lua_insert;
using lua::lua_Integer;
#undef lua_isfunction
#undef lua_isfunction
#undef lua_islightuserdata
#undef lua_isnil
#undef lua_isnone
#undef lua_isnoneornil
#undef lua_isboolean
#undef lua_istable
#undef lua_isthread
bool lua_isfunction(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TFUNCTION;
};
bool lua_istable(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TTABLE;
};
bool lua_islightuserdata(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TLIGHTUSERDATA;
};
bool lua_isnil(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TNIL;
};
bool lua_isboolean(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TBOOLEAN;
};
bool lua_isthread(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TTHREAD;
};
bool lua_isnone(lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TNONE;
};
bool lua_isnoneornil(lua_State *L, int index) {
  return lua_type(L, (index)) <= 0;
};
// using lua::lua_isboolean;
using lua::lua_iscfunction;
// using lua::lua_isfunction;
// using lua::lua_islightuserdata;
// using lua::lua_isnil;
using lua::lua_isnumber;
using lua::lua_isstring;
// using lua::lua_istable;
// using lua::lua_isthread;
using lua::lua_isuserdata;
using lua::lua_lessthan;
using lua::lua_load;
using lua::lua_newstate;
#undef lua_newtable
void lua_newtable(lua_State *L) { return lua_createtable(L, 0, 0); };
// using lua::lua_newtable;
using lua::lua_newthread;
using lua::lua_newuserdata;
using lua::lua_next;
using lua::lua_Number;
using lua::lua_objlen;
using lua::lua_pcall;
#undef lua_pop
void lua_pop(lua_State *L, int n) { return lua_settop(L, -(n)-1); };
// using lua::lua_pop;
using lua::lua_pushboolean;
using lua::lua_pushcclosure;
#undef lua_pushcfunction
void lua_pushcfunction(lua_State *L, lua_CFunction f) {
  lua_pushcclosure(L, (f), 0);
};
// using lua::lua_pushcfunction;
using lua::lua_pushfstring;
using lua::lua_pushinteger;
using lua::lua_pushlightuserdata;
using lua::lua_pushlstring;
using lua::lua_pushnil;
using lua::lua_pushnumber;
using lua::lua_pushstring;
using lua::lua_pushthread;
using lua::lua_pushvalue;
using lua::lua_pushvfstring;
using lua::lua_rawequal;
using lua::lua_rawget;
using lua::lua_rawgeti;
using lua::lua_rawset;
using lua::lua_rawseti;
using lua::lua_Reader;
using lua::lua_remove;
using lua::lua_replace;
using lua::lua_resume;
using lua::lua_setallocf;
using lua::lua_setfenv;
using lua::lua_setfield;
#undef lua_setglobal
void lua_setglobal(lua_State *L, const char *name) {
  lua_setfield(L, LUA_GLOBALSINDEX, name);
};
// using lua::lua_setglobal;
using lua::lua_setmetatable;
using lua::lua_settable;
using lua::lua_settop;
using lua::lua_State;
using lua::lua_status;
using lua::lua_toboolean;
using lua::lua_tocfunction;
using lua::lua_tointeger;
using lua::lua_tolstring;
using lua::lua_tonumber;
using lua::lua_topointer;
#undef lua_tostring
const char *lua_tostring(lua_State *L, int i) {
  return lua_tolstring(L, i, NULL);
};
// using lua::lua_tostring;
using lua::lua_tothread;
using lua::lua_touserdata;
using lua::lua_type;
using lua::lua_typename;
using lua::lua_Writer;
using lua::lua_xmove;
using lua::lua_yield;
using lua::luaL_register;

using lua::lua_Debug;
using lua::lua_gethook;
using lua::lua_gethookcount;
using lua::lua_gethookmask;
using lua::lua_getinfo;
using lua::lua_getlocal;
using lua::lua_getupvalue;
using lua::lua_Hook;
using lua::lua_sethook;
using lua::lua_setlocal;
using lua::lua_setupvalue;

#undef luaL_addchar
#undef luaL_addsize
#undef luaL_argcheck
char luaL_addchar(lua::luaL_Buffer *B, char c) {
  return (
      (void)((B)->p < ((B)->buffer + LUAL_BUFFERSIZE) || luaL_prepbuffer(B)),
      (*(B)->p++ = (char)(c)));
};
// using lua::luaL_addchar;
using lua::luaL_addlstring;
char *luaL_addsize(lua::luaL_Buffer *B, size_t n) { return ((B)->p += (n)); };
// using lua::luaL_addsize;
using lua::luaL_addstring;
using lua::luaL_addvalue;
void luaL_argcheck(lua_State *L, int cond, int numarg, const char *extramsg) {
  return ((void)((cond) || luaL_argerror(L, (numarg), (extramsg))));
};
// using lua::luaL_argcheck;
using lua::luaL_argerror;
using lua::luaL_Buffer;
using lua::luaL_buffinit;
using lua::luaL_callmeta;
using lua::luaL_checkany;
#undef luaL_checkint
int luaL_checkint(lua_State *L, int n) {
  return ((int)luaL_checkinteger(L, (n)));
}
#undef luaL_checklong
long luaL_checklong(lua_State *L, int n) {
  return ((long)luaL_checkinteger(L, (n)));
};
// using lua::luaL_checkint;
using lua::luaL_checkinteger;
// using lua::luaL_checklong;
using lua::luaL_checklstring;
using lua::luaL_checknumber;
using lua::luaL_checkoption;
using lua::luaL_checkstack;
#undef luaL_checkstring
const char *luaL_checkstring(lua_State *L, int n) {
  return (luaL_checklstring(L, (n), NULL));
};
// using lua::luaL_checkstring;
using lua::luaL_checktype;
using lua::luaL_checkudata;
#undef luaL_dofile
bool luaL_dofile(lua_State *L, const char *fn) {
  return (luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0));
};
#undef luaL_dostring
bool luaL_dostring(lua_State *L, const char *s) {
  return (luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0));
};
// using lua::luaL_dofile;
// using lua::luaL_dostring;
using lua::luaL_error;
using lua::luaL_getmetafield;
using lua::luaL_gsub;
using lua::luaL_loadbuffer;
using lua::luaL_loadfile;
using lua::luaL_loadstring;
using lua::luaL_newmetatable;
#undef luaL_getmetatable
void luaL_getmetatable(lua_State *L, const char *n) {
  return (lua_getfield(L, LUA_REGISTRYINDEX, (n)));
};
using lua::luaL_newstate;
using lua::luaL_openlib;
using lua::luaL_openlibs;
#undef luaL_optint
int luaL_optint(lua_State *L, int n, lua_Integer d) {
  return ((int)luaL_optinteger(L, (n), (d)));
};
#undef luaL_optlong
long luaL_optlong(lua_State *L, int n, long d) {
  return ((long)luaL_optinteger(L, (n), (d)));
};
// using lua::luaL_optint;
using lua::luaL_optinteger;
// using lua::luaL_optlong;
using lua::luaL_optlstring;
using lua::luaL_optnumber;
#undef luaL_optstring
const char *luaL_optstring(lua_State *L, int n, const char *d) {
  return (luaL_optlstring(L, (n), (d), NULL));
};
// using lua::luaL_optstring;
using lua::luaL_prepbuffer;
using lua::luaL_pushresult;
using lua::luaL_ref;
using lua::luaL_Reg;
using lua::luaL_register;
#undef luaL_typename
const char *luaL_typename(lua_State *L, int i) {
  return lua_typename(L, lua_type(L, (i)));
};
// using lua::luaL_typename;
using lua::luaL_typerror;
using lua::luaL_unref;
using lua::luaL_where;

using lua::luaopen_base;
using lua::luaopen_debug;
using lua::luaopen_io;
using lua::luaopen_math;
using lua::luaopen_os;
using lua::luaopen_package;
using lua::luaopen_string;
using lua::luaopen_table;

} // namespace lua
//
export namespace lua {
namespace debug {

char *get_val(lua_State *L, int idx) {

  static char sData[32];
  sData[0] = '\0';

  int type = lua_type(L, idx);
  switch (type) {
  case 0: // nil
  {
    snprintf(sData, sizeof(sData), "%s", "nil");
    break;
  }
  case 1: // bool
  {
    int val = lua_toboolean(L, idx);
    snprintf(sData, sizeof(sData), "%s", val == 1 ? "true" : "false");
    break;
  }
  case 3: // number
  {
    double val = lua_tonumber(L, idx);
    snprintf(sData, sizeof(sData), "%f", val);
    break;
  }
  case 4: // string
  {
    const char *val = lua_tostring(L, idx);
    snprintf(sData, sizeof(sData), "%s", val);
    break;
  }
  case 2:
  case 5:
  case 6:
  case 7:
  case 8:
  default: {
    const void *val = lua_topointer(L, idx);
    snprintf(sData, sizeof(sData), "%p", val);
    break;
  }
  }

  return sData;
}

int print_stack(lua_State *L) {
  int iNum = lua_gettop(L);
  std::cout << "==========Total:" << iNum << "==========" << std::endl;
  for (int i = iNum; i >= 1; i--) {
    int idx = i - iNum - 1;
    int type = lua_type(L, i);
    const char *type_name = lua_typename(L, type);
    std::cout << "idx:" << idx << " type:" << type << "(" << type_name << ") "
              << get_val(L, i) << std::endl;
  }
  std::cout << "===========================" << std::endl;
  return 0;
}

}; // namespace debug

namespace utils {

template <typename _T> _T **lua_GetUserData(lua_State *L, const char *name) {
  _T **s = static_cast<_T **>(luaL_checkudata(L, 1, name));
  return s;
}

int tryGetNumber(lua_State *L, const char *valueName) {
  lua_getglobal(L, valueName);
  if (!lua_isnumber(L, -1)) {
    lua_error(L);
  }
  return lua_tointeger(L, -1);
}

int luaL_setfunc(lua_State *L, const luaL_Reg reg) {

  lua_pushcfunction(L, reg.func); // push cfunction to top
  lua_setfield(L, -2, reg.name);
  return 0;
}

}; // namespace utils

}; // namespace lua
