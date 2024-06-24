#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_set(TypeWrapper1& set)
{
  set.apply<std::set<bool>>(stl::WrapSetType());
  set.apply<std::set<double>>(stl::WrapSetType());
  set.apply<std::set<float>>(stl::WrapSetType());
  set.apply<std::set<wchar_t>>(stl::WrapSetType());
  set.apply<std::set<void*>>(stl::WrapSetType());
  set.apply<std::set<std::string>>(stl::WrapSetType());
  set.apply<std::set<std::wstring>>(stl::WrapSetType());
  set.apply<std::set<jl_value_t*>>(stl::WrapSetType());
  set.apply<std::set<char>>(stl::WrapSetType());
  set.apply<std::set<unsigned char>>(stl::WrapSetType());
  set.apply<std::set<short>>(stl::WrapSetType());
  set.apply<std::set<unsigned short>>(stl::WrapSetType());
  set.apply<std::set<int>>(stl::WrapSetType());
  set.apply<std::set<unsigned int>>(stl::WrapSetType());
  set.apply<std::set<long>>(stl::WrapSetType());
  set.apply<std::set<unsigned long>>(stl::WrapSetType());
  set.apply<std::set<long long>>(stl::WrapSetType());
  set.apply<std::set<unsigned long long>>(stl::WrapSetType());
}

}

}