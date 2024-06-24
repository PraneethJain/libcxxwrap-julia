#ifndef JLCXX_STL_HPP
#define JLCXX_STL_HPP

#include <type_traits>
#include <valarray>
#include <vector>
#include <deque>
#include <stack>

#include "module.hpp"
#include "smart_pointers.hpp"
#include "type_conversion.hpp"

namespace jlcxx
{

namespace detail
{

struct UnusedT {};

/// Replace T1 by UnusedT if T1 == T2, return T1 otherwise
template<typename T1, typename T2>
struct SkipIfSameAs
{
  using type = T1;
};

template<typename T>
struct SkipIfSameAs<T,T>
{
  using type = UnusedT;
};

template<typename T1, typename T2> using skip_if_same = typename SkipIfSameAs<T1,T2>::type;

}

namespace stl
{

class JLCXX_API StlWrappers
{
private:
  StlWrappers(Module& mod);
  static std::unique_ptr<StlWrappers> m_instance;
  Module& m_stl_mod;
public:
  TypeWrapper1 vector;
  TypeWrapper1 valarray;
  TypeWrapper1 deque;
  TypeWrapper1 stack;

  static void instantiate(Module& mod);
  static StlWrappers& instance();

  inline jl_module_t* module() const
  {
    return m_stl_mod.julia_module();
  }
};

// Separate per-container functions to split up the compilation over multiple C++ files
void apply_vector(TypeWrapper1& vector);
void apply_valarray(TypeWrapper1& valarray);
void apply_deque(TypeWrapper1& deque);
void apply_stack(TypeWrapper1& stack);
void apply_shared_ptr();
void apply_weak_ptr();
void apply_unique_ptr();

JLCXX_API StlWrappers& wrappers();

using stltypes = remove_duplicates<combine_parameterlists<combine_parameterlists<ParameterList
<
  bool,
  double,
  float,
  char,
  wchar_t,
  void*,
  std::string,
  std::wstring,
  jl_value_t*
>, fundamental_int_types>, fixed_int_types>>;

template<typename TypeWrapperT>
void wrap_range_based_algorithms([[maybe_unused]] TypeWrapperT& wrapped)
{
#ifdef JLCXX_HAS_RANGES
  using WrappedT = typename TypeWrapperT::type;
  using T = typename WrappedT::value_type;
  wrapped.module().set_override_module(StlWrappers::instance().module());
  wrapped.method("StdFill", [] (WrappedT& v, const T& val) { std::ranges::fill(v, val); });
  wrapped.module().unset_override_module();
#endif
}

template<typename T>
struct WrapVectorImpl
{
  template<typename TypeWrapperT>
  static void wrap(TypeWrapperT&& wrapped)
  {
    using WrappedT = std::vector<T>;
    
    wrap_range_based_algorithms(wrapped);
    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("push_back", static_cast<void (WrappedT::*)(const T&)>(&WrappedT::push_back));
    wrapped.method("cxxgetindex", [] (const WrappedT& v, cxxint_t i) -> typename WrappedT::const_reference { return v[i-1]; });
    wrapped.method("cxxgetindex", [] (WrappedT& v, cxxint_t i) -> typename WrappedT::reference { return v[i-1]; });
    wrapped.method("cxxsetindex!", [] (WrappedT& v, const T& val, cxxint_t i) { v[i-1] = val; });
    wrapped.module().unset_override_module();
  }
};

template<>
struct WrapVectorImpl<bool>
{
  template<typename TypeWrapperT>
  static void wrap(TypeWrapperT&& wrapped)
  {
    using WrappedT = std::vector<bool>;

    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("push_back", [] (WrappedT& v, const bool val) { v.push_back(val); });
    wrapped.method("cxxgetindex", [] (const WrappedT& v, cxxint_t i) { return bool(v[i-1]); });
    wrapped.method("cxxsetindex!", [] (WrappedT& v, const bool val, cxxint_t i) { v[i-1] = val; });
    wrapped.module().unset_override_module();
  }
};

struct WrapVector
{
  template<typename TypeWrapperT>
  void operator()(TypeWrapperT&& wrapped)
  {
    using WrappedT = typename TypeWrapperT::type;
    using T = typename WrappedT::value_type;
    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("cppsize", &WrappedT::size);
    wrapped.method("resize", [] (WrappedT& v, const cxxint_t s) { v.resize(s); });
    wrapped.method("append", [] (WrappedT& v, jlcxx::ArrayRef<T> arr)
    {
      const std::size_t addedlen = arr.size();
      v.reserve(v.size() + addedlen);
      for(size_t i = 0; i != addedlen; ++i)
      {
        v.push_back(arr[i]);
      }
    });
    wrapped.module().unset_override_module();
    WrapVectorImpl<T>::wrap(wrapped);
  }
};

struct WrapValArray
{
  template<typename TypeWrapperT>
  void operator()(TypeWrapperT&& wrapped)
  {
    using WrappedT = typename TypeWrapperT::type;
    using T = typename WrappedT::value_type;

    wrap_range_based_algorithms(wrapped); 
    wrapped.template constructor<std::size_t>();
    wrapped.template constructor<const T&, std::size_t>();
    wrapped.template constructor<const T*, std::size_t>();
    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("cppsize", &WrappedT::size);
    wrapped.method("resize", [] (WrappedT& v, const cxxint_t s) { v.resize(s); });
    wrapped.method("cxxgetindex", [] (const WrappedT& v, cxxint_t i) -> const T& { return v[i-1]; });
    wrapped.method("cxxgetindex", [] (WrappedT& v, cxxint_t i) -> T& { return v[i-1]; });
    wrapped.method("cxxsetindex!", [] (WrappedT& v, const T& val, cxxint_t i) { v[i-1] = val; });
    wrapped.module().unset_override_module();
  }
};

struct WrapDeque
{
  template<typename TypeWrapperT>
  void operator()(TypeWrapperT&& wrapped)
  {
    using WrappedT = typename TypeWrapperT::type;
    using T = typename WrappedT::value_type;

    wrap_range_based_algorithms(wrapped);
    wrapped.template constructor<std::size_t>();
    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("cppsize", &WrappedT::size);
    wrapped.method("resize", [](WrappedT &v, const cxxint_t s) { v.resize(s); });
    wrapped.method("cxxgetindex", [](const WrappedT& v, cxxint_t i) -> const T& { return v[i - 1]; });
    wrapped.method("cxxsetindex!", [](WrappedT& v, const T& val, cxxint_t i) { v[i - 1] = val; });
    wrapped.method("push_back!", [] (WrappedT& v, const T& val) { v.push_back(val); });
    wrapped.method("push_front!", [] (WrappedT& v, const T& val) { v.push_front(val); });
    wrapped.method("pop_back!", [] (WrappedT& v) { v.pop_back(); });
    wrapped.method("pop_front!", [] (WrappedT& v) { v.pop_front(); });
    wrapped.module().unset_override_module();
  }
};

struct WrapStack
{
  template<typename TypeWrapperT>
  void operator()(TypeWrapperT&& wrapped)
  {
    using WrappedT = typename TypeWrapperT::type;
    using T = typename WrappedT::value_type;

    wrapped.template constructor<>();
    wrapped.module().set_override_module(StlWrappers::instance().module());
    wrapped.method("cppsize", &WrappedT::size);
    wrapped.method("stack_isempty", [] (WrappedT& v) { return v.empty(); });
    wrapped.method("stack_push!", [] (WrappedT& v, const T& val) { v.push(val); });
    wrapped.method("stack_top", [] (WrappedT& v) { return v.top(); });
    wrapped.method("stack_pop!", [] (WrappedT& v) { v.pop(); });
    wrapped.module().unset_override_module();
  }
};


template<typename T>
inline void apply_stl(jlcxx::Module& mod)
{
  TypeWrapper1(mod, StlWrappers::instance().vector).apply<std::vector<T>>(WrapVector());
  TypeWrapper1(mod, StlWrappers::instance().valarray).apply<std::valarray<T>>(WrapValArray());
  TypeWrapper1(mod, StlWrappers::instance().deque).apply<std::deque<T>>(WrapDeque());
  TypeWrapper1(mod, StlWrappers::instance().stack).apply<std::stack<T>>(WrapStack());
}

}

template<typename T>
struct julia_type_factory<std::vector<T>>
{
  using MappedT = std::vector<T>;

  static inline jl_datatype_t* julia_type()
  {
    create_if_not_exists<T>();
    assert(!has_julia_type<MappedT>());
    assert(registry().has_current_module());
    jl_datatype_t* jltype = ::jlcxx::julia_type<T>();
    Module& curmod = registry().current_module();
    stl::apply_stl<T>(curmod);
    assert(has_julia_type<MappedT>());
    return stored_type<MappedT>().get_dt();
  }
};

}

#endif
