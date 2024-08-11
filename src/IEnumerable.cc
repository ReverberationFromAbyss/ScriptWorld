module;

export module ManyUtilsLibrary:IEnumerable;

import std;
import :IObject;

namespace mul_std {
namespace IEnumerable {

export template <typename T>
class __I_Enumerable_ : public IObject::__I_Object_ {
  /// Variable & Type
protected:
private:
public:
  /// Methods
protected:
private:
public:
  virtual std::size_t GetSize(void) const noexcept;
  virtual std::size_t GetCapacity(void) const noexcept;

  virtual __I_Enumerable_<IObject::__I_Object_> &
  Foreach(std::function<IObject::__I_Object_(T &)> &&);
  virtual __I_Enumerable_<IObject::__I_Object_> &
  Select(std::function<IObject::__I_Object_(T *)> &&);
  virtual __I_Enumerable_<T> &Match(std::function<bool(T &)> &&);

  virtual T At(std::initializer_list<int>);
  virtual T &Ref(std::initializer_list<int>);
};

}; // namespace IEnumerable
}; // namespace mul_std
