#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_forward_list(TypeWrapper1& forward_list)
{
  forward_list.apply<std::forward_list<bool>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<double>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<float>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<wchar_t>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<void*>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<std::string>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<std::wstring>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<jl_value_t*>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<char>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<unsigned char>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<short>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<unsigned short>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<int>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<unsigned int>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<long>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<unsigned long>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<long long>>(stl::WrapForwardList());
  forward_list.apply<std::forward_list<unsigned long long>>(stl::WrapForwardList());
}

}

}