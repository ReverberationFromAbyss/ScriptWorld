import LuaWrapper;
import std;
using namespace std;
using namespace lua;

int main(int argc, const char *argv[]) {
  lua_State *L;
  if (nullptr == (L = luaL_newstate())) {
    perror("luaL_newstate failed");
    return -1;
  }

  return 0;
}
