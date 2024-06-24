#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_unordered_multiset(TypeWrapper1& unordered_multiset)
{
  unordered_multiset.apply<std::unordered_multiset<bool>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<double>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<float>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<wchar_t>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<void*>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<std::string>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<std::wstring>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<jl_value_t*>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<char>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<unsigned char>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<short>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<unsigned short>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<int>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<unsigned int>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<long>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<unsigned long>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<long long>>(stl::WrapMultisetType());
  unordered_multiset.apply<std::unordered_multiset<unsigned long long>>(stl::WrapMultisetType());
}

}

}