/**
 * @file Defination.cc
 * @author dot
 * @version
 * @date 2024-08-09
 * @brief
 */
module;
export module ScriptWorld:Defination;
import std;
import std.compat;
import Utils;
import LuaWrapper;
import ManyUtilsLibrary;

using namespace std;

namespace ScriptWorld {

export struct Position;
export class World;
export class Unit;

struct Position {
  using position_x_t = int;
  using position_y_t = int;
  position_x_t x;
  position_y_t y;

  Position(position_x_t x, position_y_t y) : x(x), y(y) {}
  Position(void) : x(0), y(0) {}
};

/**
 * @class Unit
 * @brief Units on the world
 *
 */
class Unit final : public mul_std::IObject::__I_Object_ {
  /// Variable & Type
protected:
private:
  World *m_parent_{};
  Position m_pos_{};

  static lua::lua_State *s_luaVM_;

  int m_currentStatus_{0};
  int m_nextStatus{0};

public:
  /// Methods
protected:
private:
public:
  Unit();
  ~Unit();

  Unit(Unit &&obj) = default;
  Unit(const Unit &obj) = default;
  Unit &operator=(Unit &&obj) = default;
  Unit &operator=(const Unit &obj) = default;

  static Unit *Create(World *parent, Position pos);

  bool Init(void) override;
  bool Init(World *parent, Position pos, int status = 0);
  static bool InitLuaVM(void);

  int GetCurrentStatus(void);
  void SetCurrentStatus(int livingStatus);
  Position GetPosition(void);

  void EvaluateLua(void);

  void EvaluateNextStatus(void);
  void ForwardStatus(void);

  World *GetParent(void);
};

class World final : public mul_std::IObject::__I_Object_ {
  /// Variable & Type
protected:
private:
  mul_std::IEnumerable::Array<Unit, 10, 10> m_map_;
  Position m_mapScale_{};

public:
  /// Methods
protected:
private:
public:
  World();
  ~World();

  World(World &&obj);
  World(const World &obj);
  World &operator=(World &&obj);
  World &operator=(const World &obj);

  static World *Create(void);
  bool Init(void) override;

  Position GetMapScale(void);

  void SetUnit(Position pos, Unit *unit);
  void Update(void);
  Unit &GetUnit(Position pos);

  string ExportToString(void);
  mul_std::IEnumerable::Array<Unit, 10, 10> &ExportMap(void);
};

} // namespace ScriptWorld
