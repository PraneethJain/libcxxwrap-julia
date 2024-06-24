#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_unordered_set(TypeWrapper1& unordered_set)
{
  unordered_set.apply<std::unordered_set<bool>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<double>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<float>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<wchar_t>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<void*>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<std::string>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<std::wstring>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<jl_value_t*>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<char>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<unsigned char>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<short>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<unsigned short>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<int>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<unsigned int>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<long>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<unsigned long>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<long long>>(stl::WrapSetType());
  unordered_set.apply<std::unordered_set<unsigned long long>>(stl::WrapSetType());
}

}

}