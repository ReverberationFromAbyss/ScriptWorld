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

  lua_pushstring(L, "Hello, Lua;");
  lua_pushnumber(L, 20);
  if (lua_isstring(L, 1)) {
    cout << lua_tostring(L, 1) << endl;
  }
  if (lua_isnumber(L, 2)) {
    cout << lua_tonumber(L, 2);
  }

  lua_close(L);

  return 0;
}
