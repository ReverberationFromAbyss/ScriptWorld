
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

using lua::luaL_loadbuffer;
using lua::luaL_loadfile;
using lua::luaL_loadstring;
using lua::luaL_openlib;
using lua::luaL_openlibs;

using lua::lua_close;
using lua::luaL_newstate;

using lua::lua_call;
using lua::lua_cpcall;
using lua::lua_load;
using lua::lua_pcall;

using lua::lua_getfield;
using lua::lua_setfield;

::std::function<void(lua_State *L, const char *name)> lua_getglobal =
    [](lua_State *L, const char *name) {
      lua_getfield(L, LUA_GLOBALSINDEX, name);
    };
::std::function<void(lua_State *L, const char *name)> lua_setglobal =
    [](lua_State *L, const char *name) {
      lua_setfield(L, LUA_GLOBALSINDEX, name);
    };

using lua::lua_gettop;
using lua::lua_settop;

using lua::lua_insert;
using lua::lua_pushvalue;
using lua::lua_remove;
using lua::lua_replace;

using lua::lua_gettable;
using lua::lua_settable;

using lua::lua_concat;

using lua::lua_type;
using lua::lua_typename;

using lua::lua_checkstack;

using lua::lua_iscfunction;
using lua::lua_isnumber;
using lua::lua_isstring;
using lua::lua_isuserdata;

auto lua_isfunction = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TFUNCTION;
};
auto lua_istable = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TTABLE;
};
auto lua_islightuserdata = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TLIGHTUSERDATA;
};
auto lua_isnil = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TNIL;
};
auto lua_isboolean = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TBOOLEAN;
};
auto lua_isthread = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TTHREAD;
};
auto lua_isnone = [](lua_State *L, int index) {
  return lua_type(L, (index)) == LUA_TNONE;
};
auto lua_isnoneornil = [](lua_State *L, int index) {
  return lua_type(L, (index)) <= 0;
};

using lua::lua_equal;
using lua::lua_lessthan;
using lua::lua_rawequal;

using lua::lua_toboolean;
using lua::lua_tocfunction;
using lua::lua_tointeger;
using lua::lua_tolstring;
using lua::lua_tonumber;
using lua::lua_topointer;
using lua::lua_tothread;
auto lua_tostring = [](lua_State *L, int i) {
  return lua_tolstring(L, i, NULL);
};

using lua::lua_pushboolean;
using lua::lua_pushcclosure;
auto lua_pushcfunction = [](lua_State *L, lua_CFunction f) {
  lua_pushcclosure(L, (f), 0);
};
using lua::lua_pushfstring;
using lua::lua_pushinteger;
auto lua_pushliteral = [](lua_State *L, const char *s) {
  return lua_pushlstring(L, s, ::std::string(s).size() - 1);
};
using lua::lua_pushlstring;
using lua::lua_pushnil;
using lua::lua_pushnumber;
using lua::lua_pushstring;
using lua::lua_pushvfstring;

using lua::luaL_register;
auto lua_register = [](lua_State *L, const char *n, lua_CFunction f) {
  return (lua_pushcfunction(L, (f)), lua_setglobal(L, (n)));
};

using lua::luaL_Reg;

using lua::luaopen_base;
using lua::luaopen_debug;
using lua::luaopen_io;
using lua::luaopen_math;
using lua::luaopen_os;
using lua::luaopen_package;
using lua::luaopen_string;
using lua::luaopen_table;

using lua::luaL_addlstring;
using lua::luaL_addstring;
using lua::luaL_addvalue;
using lua::luaL_argerror;
using lua::luaL_buffinit;
using lua::luaL_callmeta;
using lua::luaL_checkany;
using lua::luaL_checkstack;
using lua::luaL_checktype;
using lua::luaL_checkudata;
using lua::luaL_error;
using lua::luaL_findtable;
using lua::luaL_gsub;
using lua::luaL_optnumber;
using lua::luaL_ref;
using lua::luaL_register;
using lua::luaL_typerror;
using lua::luaL_unref;
using lua::luaL_where;
auto luaL_addchar = [](lua::luaL_Buffer *B, char c) {
  ((void)((B)->p < ((B)->buffer + LUAL_BUFFERSIZE) || luaL_prepbuffer(B)),
   (*(B)->p++ = (char)(c)));
};
using lua::luaL_addlstring;
auto luaL_addsize = [](lua::luaL_Buffer *B, size_t n) {
  return ((B)->p += (n));
};
using lua::luaL_addstring;
using lua::luaL_addvalue;
auto luaL_argcheck = [](lua_State *L, int cond, int numarg,
                        const char *extramsg) {
  return ((void)((cond) || luaL_argerror(L, (numarg), (extramsg))));
};
using lua::luaL_argerror;
using lua::luaL_Buffer;
using lua::luaL_buffinit;
using lua::luaL_callmeta;
using lua::luaL_checkany;
using lua::luaL_checkinteger;
auto luaL_checkint = [](lua_State *L, int n) {
  return ((int)luaL_checkinteger(L, (n)));
};
auto luaL_checklong = [](lua_State *L, int n) {
  return ((long)luaL_checkinteger(L, (n)));
};
using lua::luaL_checklstring;
using lua::luaL_checknumber;
using lua::luaL_checkoption;
using lua::luaL_checkstack;
auto luaL_checkstring = [](lua_State *L, int n) {
  return (luaL_checklstring(L, (n), NULL));
};
using lua::luaL_checktype;
using lua::luaL_checkudata;
auto luaL_dofile = [](lua_State *L, const char *fn) {
  return (luaL_loadfile(L, fn) || lua_pcall(L, 0, LUA_MULTRET, 0));
};
auto luaL_dostring = [](lua_State *L, const char *s) {
  return (luaL_loadstring(L, s) || lua_pcall(L, 0, LUA_MULTRET, 0));
};
using lua::lua_getmetatable;
using lua::luaL_error;
using lua::luaL_getmetafield;
using lua::luaL_gsub;
using lua::luaL_loadbuffer;
using lua::luaL_loadfile;
using lua::luaL_loadstring;
using lua::luaL_newmetatable;
using lua::luaL_optinteger;
auto luaL_optint = [](lua_State *L, int n, lua_Integer d) {
  return ((int)luaL_optinteger(L, (n), (d)));
};
auto luaL_optlong = [](lua_State *L, int n, long d) {
  return ((long)luaL_optinteger(L, (n), (d)));
};
using lua::luaL_optlstring;
using lua::luaL_optnumber;
auto luaL_optstring = [](lua_State *L, int n, const char *d) {
  return (luaL_optlstring(L, (n), (d), NULL));
};
using lua::luaL_prepbuffer;
using lua::luaL_pushresult;
using lua::luaL_ref;
using lua::luaL_Reg;
using lua::luaL_register;
auto luaL_typename = [](lua_State *L, int i) {
  return lua_typename(L, lua_type(L, (i)));
};
using lua::luaL_typerror;
using lua::luaL_unref;
using lua::luaL_where;

} // namespace lua
