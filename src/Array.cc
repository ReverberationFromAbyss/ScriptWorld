module;

export module ManyUtilsLibrary:Array;

import :IObject;
import :IEnumerable;
import std;

namespace mul_std {
namespace IEnumerable {

template <unsigned int Operatee, unsigned int... RestOperatee>
constexpr unsigned int Sigma(void) {
  if constexpr (sizeof...(RestOperatee) > 0) {
    return Operatee * Sigma<RestOperatee...>();
  }
  return Operatee;
}

template <unsigned int _Dim, unsigned int... _RestDims>
struct __Dimersion_ final {
  /// Variable & Type
  constexpr static const decltype(sizeof...(_RestDims)) sc_Dimensions_{
      sizeof...(_RestDims) + 1};
  constexpr static const decltype(_Dim)
      sc_DimensionInfo_[sizeof...(_RestDims) + 1]{_Dim, _RestDims...};
  constexpr static const decltype(Sigma<_Dim, _RestDims...>()) sc_VectorLength_{
      Sigma<_Dim, _RestDims...>()};
};

template <typename _Type, typename _DimInfo,
          class _Alloc = std::allocator<_Type>>
class __Array_Primary_ : public IEnumerable::__I_Enumerable_<_Type> {
  /// Variable & Type
protected:
  // Struct __Assistant_DimExpander_

  using dimensionInfo = _DimInfo;

  using type = _Type;
  using pointer = _Type *;
  using reference = _Type &;

  using size = decltype(sizeof(_Type *));

  class __Impl_Array_ {
    /// Variable & Type
  protected:
  private:
    type m_obj_[dimensionInfo::sc_VectorLength_];
    size m_memLength_{dimensionInfo::sc_VectorLength_ * sizeof(type)};
    size m_objNum_{dimensionInfo::sc_VectorLength_};

  public:
    /// Methods
  protected:
  private:
  public:
    // constexpr _Base &_GetRest() noexcept { return *this; }
    // constexpr const _Base &_GetRest() const noexcept { return *this; }

    __Impl_Array_() {
      // size tmp{1};
      // for (auto var : dimensionInfo::sc_DimensionInfo_) {
      //   tmp *= var;
      // }
      // m_objNum_ = tmp;
      // m_memLength_ = tmp * sizeof(type);
      // m_obj_ = new _Type[m_objNum_];
    }
    ~__Impl_Array_() {
      // delete[] m_obj_;
    }

    __Impl_Array_(__Impl_Array_ &&obj) = delete;
    __Impl_Array_(const __Impl_Array_ &obj) = delete;

    __Impl_Array_ &operator=(__Impl_Array_ &&obj) = delete;
    __Impl_Array_ &operator=(const __Impl_Array_ &obj) = delete;

    std::size_t GetSize(void) const noexcept { return m_objNum_; }
    std::size_t GetCapacity(void) const noexcept { return m_objNum_; };

    type At(std::initializer_list<int> args) {
      // assert(elepos.size() < dimensionInfo::sc_Dimensions_, "");
      int tmp{0};
      auto p{args.begin()};
      for (int i = 0; i < args.size(); i++) {
        auto dim = (dimensionInfo::sc_Dimensions_ - i - 1) > 0
                       ? dimensionInfo::sc_DimensionInfo_
                             [dimensionInfo::sc_Dimensions_ - i - 1]
                       : 1;
        tmp += dim * static_cast<decltype(dim)>(*(p + i));
      }
      if (tmp >= m_objNum_) {
        throw "Error: stack overflow";
      } else {
        return m_obj_[tmp];
      }
    }

    template <unsigned int Operatee, unsigned int... RestOperatee>
    type At(void) {
      auto ref = Sigma<Operatee, RestOperatee...>();
      if constexpr (ref > m_objNum_) {
        throw "Error:stack overflow";
      }
      return m_obj_[ref];
    }

    reference Ref(std::initializer_list<int> args) {
      // assert(elepos.size() < dimensionInfo::sc_Dimensions_, "");
      int tmp{0};
      auto p{args.begin()};
      for (int i = 0; i < args.size(); i++) {
        auto dim = (dimensionInfo::sc_Dimensions_ - i - 1) > 0
                       ? dimensionInfo::sc_DimensionInfo_
                             [dimensionInfo::sc_Dimensions_ - i - 1]
                       : 1;
        tmp += dim * static_cast<decltype(dim)>(*(p + i));
      }
      if (tmp >= m_objNum_) {
        throw "Error: stack overflow";
      } else {
        return m_obj_[tmp];
      }
      return m_obj_[tmp];
    }

    template <unsigned int Operatee, unsigned int... RestOperatee>
    reference Ref(void) {
      auto ref = Sigma<Operatee, RestOperatee...>();
      if constexpr (ref > m_objNum_) {
        throw "Error:stack overflow";
      }
      return m_obj_[ref];
    }
  };

private:
  __Impl_Array_ m_pImpl_Array_;

public:
  /// Methods
protected:
private:
public:
  bool Init(void) override { return true; };

  std::size_t GetSize(void) const noexcept override {
    return m_pImpl_Array_.GetSize();
  }
  std::size_t GetCapacity(void) const noexcept override {
    return m_pImpl_Array_.GetCapacity();
  };

  type At(std::initializer_list<int> args) override {
    return m_pImpl_Array_.At(args);
  }

  type &Ref(std::initializer_list<int> args) override {
    return m_pImpl_Array_.Ref(args);
  }
};

export template <typename T, int Dims, int... Args>
class Array : public __Array_Primary_<T, __Dimersion_<Dims, Args...>> {
  /// Variable & Type
protected:
private:
public:
  /// Methods
protected:
private:
public:
};

}; // namespace IEnumerable
}; // namespace mul_std
