#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_multiset(TypeWrapper1& multiset)
{
  multiset.apply<std::multiset<bool>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<double>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<float>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<wchar_t>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<void*>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<std::string>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<std::wstring>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<jl_value_t*>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<char>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<unsigned char>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<short>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<unsigned short>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<int>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<unsigned int>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<long>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<unsigned long>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<long long>>(stl::WrapMultisetType());
  multiset.apply<std::multiset<unsigned long long>>(stl::WrapMultisetType());
}

}

}