module;
export module ScriptWorld:World;
import std;
import Utils;
import :Defination;

using namespace std;

namespace ScriptWorld {

class World;
class Unit;

World::World() {
  cout << "World constructed" << endl; // DEBUG:
}

bool World::Init(void) {
  for (int i = 0; i < m_mapScale_.x; i++) {
    for (int j = 0; j < m_mapScale_.y; j++) {
      m_map_.Ref({i, j}) = Unit::Create(this, Position(i, j));
    }
  }

  return true;
}

World *World::Create(void) {

  auto tmp = new World();
  if (!tmp->Init()) {
    delete tmp;
    return nullptr;
  }
  return tmp;
}

Unit &World::GetUnit(Position pos) { return *m_map_.Ref({pos.x, pos.y}); }

} // namespace ScriptWorld
