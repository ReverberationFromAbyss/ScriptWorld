import LuaWrapper;
import ManyUtilsLibrary;
import std;
using namespace std;
using namespace lua;

int main(int argc, const char *argv[]) {
  mul_std::IEnumerable::Array<int, 5, 2> val;
  val.Ref({4, 0}) = 4;
  std::cout << val.At<4, 0>();

  lua_State *L;
  if (nullptr == (L = luaL_newstate())) {
    perror("luaL_newstate failed");
    return -1;
  }

  return 0;
}
