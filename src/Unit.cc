
export module ScriptingWorld:Cell;
import std;
import Utils;
import :Defination;
import LuaWrapper;

using namespace std;

namespace ScriptingWorld {

class Unit;
class World;

Unit::Unit() {
  m_luaVM_ = lua::luaL_newstate();
  static const lua::luaL_Reg lualibs[] = {
      {"base", lua::luaopen_base},
      {"io", lua::luaopen_io},
      {nullptr, nullptr},
  };
  const lua::luaL_Reg *lib = lualibs;
  for (; lib->func != nullptr; lib++) {
    //  lua::luaL_requiref(m_luaVM_, lib->name, lib->func, 1);
    lua::lua_settop(m_luaVM_, 0);
  }
}

bool Unit::Init(void) { return false; }

bool Unit::Init(World *parent, Position pos, int status) {
  m_parent_ = parent;
  m_pos_ = pos;
  m_currentStatus_ = status;
  return true;
}

int Unit::GetCurrentStatus(void) { return m_currentStatus_; }

void Unit::SetCurrentStatus(int status) { m_currentStatus_ = status; }

void Unit::EvaluateNextStatus(void) { return; }

void Unit::ForwardStatus(void) { return; }
} // namespace ScriptingWorld
