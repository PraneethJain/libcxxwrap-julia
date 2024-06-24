#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_list(TypeWrapper1& list)
{
  list.apply<std::list<bool>>(stl::WrapList());
  list.apply<std::list<double>>(stl::WrapList());
  list.apply<std::list<float>>(stl::WrapList());
  list.apply<std::list<wchar_t>>(stl::WrapList());
  list.apply<std::list<void*>>(stl::WrapList());
  list.apply<std::list<std::string>>(stl::WrapList());
  list.apply<std::list<std::wstring>>(stl::WrapList());
  list.apply<std::list<jl_value_t*>>(stl::WrapList());
  list.apply<std::list<char>>(stl::WrapList());
  list.apply<std::list<unsigned char>>(stl::WrapList());
  list.apply<std::list<short>>(stl::WrapList());
  list.apply<std::list<unsigned short>>(stl::WrapList());
  list.apply<std::list<int>>(stl::WrapList());
  list.apply<std::list<unsigned int>>(stl::WrapList());
  list.apply<std::list<long>>(stl::WrapList());
  list.apply<std::list<unsigned long>>(stl::WrapList());
  list.apply<std::list<long long>>(stl::WrapList());
  list.apply<std::list<unsigned long long>>(stl::WrapList());
}

}

}