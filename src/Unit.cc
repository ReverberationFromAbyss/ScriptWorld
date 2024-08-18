
export module ScriptWorld:Cell;
import std;
import Utils;
import :Defination;
import LuaWrapper;

using namespace std;
using namespace lua;

namespace ScriptWorld {

class Unit;
class World;

lua_State *Unit::s_luaVM_{nullptr};

Unit::Unit() {
  cout << "Unit constructed" << endl; // DEBUG:
}

bool Unit::Init(void) { return true; }

bool Unit::Init(World *parent, Position pos, int status) {
  m_parent_ = parent;
  m_pos_ = pos;
  m_currentStatus_ = status;
  return true;
}

Unit **Unit::Create(World *parent, Position pos) {
  auto tmp = (Unit **)lua::lua_newuserdata(s_luaVM_, sizeof(Unit));
  *tmp = new Unit();
  if (!(*tmp)->Init(parent, pos)) {
    delete *tmp;
    return nullptr;
  }

  cout << "position: x: " << pos.x << "/y: " << pos.y << endl; // DEBUG:

  luaL_getmetafield(s_luaVM_, Lua_Globalsindex, "scriptWorld.unit");
  lua_setmetatable(s_luaVM_, -2);
  return tmp;
}

/**
 * @brief Initialize Lua vm for all units
 *
 * @return bool
 */
bool Unit::InitLuaVM(lua_State *L) {
  s_luaVM_ = L;
  luaL_openlibs(s_luaVM_);

  static const luaL_Reg lualibs[] = {
      {nullptr, nullptr},
  };
  const luaL_Reg *lib = lualibs;

  for (; lib->func != nullptr; lib++) {
    utils::luaL_setfunc(s_luaVM_, *lib);
    lua_settop(s_luaVM_, 0);
  }
  return true;
}

int Unit::GetCurrentStatus(void) { return m_currentStatus_; }
void Unit::SetCurrentStatus(int status) { m_currentStatus_ = status; }
Position Unit::GetPosition(void) { return m_pos_; }
World *Unit::GetParent(void) { return m_parent_; }

void EvaluateLua(void);

void Unit::EvaluateNextStatus(void) {
  lua_getglobal(s_luaVM_, "nextStatus");
  lua_pcall(s_luaVM_, 1, 1, 0);
  auto status = lua_tonumber(s_luaVM_, -1);
  lua_pop(s_luaVM_, 1);
  m_nextStatus_ = status;

  return;
}

void Unit::ForwardStatus(void) {
  m_currentStatus_ = m_nextStatus_;
  m_nextStatus_ = 0;

  return;
}

export namespace LuaBinding {

int lua_SetCurrentStatus(lua_State *L) {
  // two arguments, first one is object
  // second one is the number refers to status
  Unit **s = static_cast<Unit **>(lua_touserdata(L, 1));
  luaL_argcheck(L, s != nullptr, 1, "invalid  user data");

  luaL_checktype(L, -1, Lua_Tnumber);
  // check wether the value on top is a number
  int currentStatus = lua_tointeger(L, -1);
  (*s)->SetCurrentStatus(currentStatus);
  lua_settop(L, 0); // clear

  return 0;
}

int lua_GetCurrentStatus(lua_State *L) {
  // one argument, which is the object
  Unit **s = static_cast<Unit **>(lua_touserdata(L, 1));
  luaL_argcheck(L, s != nullptr, 1, "invalid user data");

  lua_settop(L, 0); // clear
  lua_pushnumber(L, (*s)->GetCurrentStatus());

  return 0;
}

int lua_GetParent(lua_State *L) {
  // one argument, which is the object
  Unit **s = static_cast<Unit **>(lua_touserdata(L, 1));
  luaL_argcheck(L, s != nullptr, 1, "invalid user data");

  lua_settop(L, 0); // clear
  lua_pushlightuserdata(L, (*s)->GetParent());
  return 1;
}

int lua_GetPositionX(lua_State *L) {
  auto s = utils::lua_GetUserData<Unit>(L, "scriptWorld.unit");
  luaL_argcheck(L, s != nullptr, 1, "invalid user data");
  lua_settop(L, 0);
  lua_pushnumber(L, (*s)->GetPosition().x);
  return 1;
}

int lua_GetPositionY(lua_State *L) {
  auto s = utils::lua_GetUserData<Unit>(L, "scriptWorld.unit");
  luaL_argcheck(L, s != nullptr, 1, "invalid user data");

  lua_settop(L, 0);
  lua_pushnumber(L, (*s)->GetPosition().y);
  return 1;
}

int lua_GetUnitStatus(lua_State *L) {
  auto s = utils::lua_GetUserData<Unit>(L, "scriptWorld.unit");
  luaL_argcheck(L, s != nullptr, 3, "invalid user data");

  auto arg1 = (lua_isnumber(L, -2) ? lua_tointeger(L, -2) : 0);
  auto arg2 = (lua_isnumber(L, -2) ? lua_tointeger(L, -2) : 0);

  lua_settop(L, 0);
  lua_pushnumber(
      L, (*s)->GetParent()->GetUnit(Position(arg1, arg2)).GetCurrentStatus());

  return 1;
}

const struct luaL_Reg lib_f[] = {
    //{"create", Unit::Create},
    {"getStatus", lua_GetCurrentStatus},
    {"setStatus", lua_SetCurrentStatus},
    {"getParent", lua_GetParent},
    {"getPositionX", lua_GetPositionX},
    {"getPositionY", lua_GetPositionY},
    {"getUnitStatus", lua_GetUnitStatus},
    {nullptr, nullptr},

};
int luaopen_unit(lua_State *L) {

  luaL_newmetatable(L, "scriptWorld.unit"); // new metatable, top
  lua_pushvalue(L, -1);                     // copy top to top
  lua_setfield(L, -2, "__index"); // set metatable, let __index be it self

  auto *p = lib_f;
  for (; p->func != nullptr; p++) {
    utils::luaL_setfunc(L, *p);
  }
  lua_setfield(L, Lua_Globalsindex, "scriptworld.unit");

  luaL_register(L, "scriptWorld", lib_f);

  return 1;
}

}; // namespace LuaBinding
}; // namespace ScriptWorld
