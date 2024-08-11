/**
 * @file Defination.cc
 * @author dot
 * @version
 * @date 2024-08-09
 * @brief
 */
module;
export module ScriptingWorld:Defination;
import std;
import std.compat;
import Utils;
import ManyUtilsLibrary;

using namespace std;

namespace ScriptingWorld {

export class World;
export class Unit;
export struct Position;

struct Position {
  using position_x_t = int;
  using position_y_t = int;
  position_x_t x;
  position_y_t y;

  Position(position_x_t x, position_y_t y) : x(x), y(y) {}
  Position(void) : x(0), y(0) {}
};

class Unit final : public mul_std::IObject::__I_Object_ {
  /// Variable & Type
protected:
private:
  Position m_pos_{};

public:
  /// Methods
protected:
private:
public:
  Unit();
  ~Unit();

  Unit(Unit &&obj);
  Unit(const Unit &obj);
  Unit &operator=(Unit &&obj);
  Unit &operator=(const Unit &obj);

  static Unit *Create(void);
  bool Init(void) override;
};

class World final : public mul_std::IObject::__I_Object_ {
  /// Variable & Type
protected:
private:
  mul_std::IEnumerable::Array<Unit, 50, 50> m_map_;

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
};

} // namespace ScriptingWorld
