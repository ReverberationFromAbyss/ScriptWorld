import LuaWrapper;
import ManyUtilsLibrary;
import ScriptWorld;
import std;
using namespace std;
using namespace lua;

int main(int argc, const char *argv[]) {

  lua_State *L;
  if (nullptr == (L = luaL_newstate())) {
    perror("luaL_newstate failed");
    return -1;
  }
  ScriptWorld::Unit::InitLuaVM(L);
  ScriptWorld::LuaBinding::luaopen_unit(L);

  auto world = ScriptWorld::World::Create();

  while (true) {
    string str;
    cin >> str;
    luaL_dostring(L, str.data());
  }

  lua_close(L);

  return 0;
}
