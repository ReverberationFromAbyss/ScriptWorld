module;

#ifdef __cplusplus
extern "C" {
#endif // ! __cplusplus
namespace lua {

#include "lauxlib.h"
#include "lualib.h"

#include "lua.h"

} // namespace lua

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

std::function<void(lua_State *L, const char *name)> lua_getglobal =
    [](lua_State *L, const char *name) {
      lua_getfield(L, LUA_GLOBALSINDEX, name);
    };
std::function<void(lua_State *L, const char *name)> lua_setglobal =
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
  return lua_pushlstring(L, s, std::string(s).size() - 1);
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

} // namespace lua
