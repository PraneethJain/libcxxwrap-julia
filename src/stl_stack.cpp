#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_stack(TypeWrapper1& stack)
{
  stack.apply<std::stack<bool>>(stl::WrapStack());
  stack.apply<std::stack<double>>(stl::WrapStack());
  stack.apply<std::stack<float>>(stl::WrapStack());
  stack.apply<std::stack<wchar_t>>(stl::WrapStack());
  stack.apply<std::stack<void*>>(stl::WrapStack());
  stack.apply<std::stack<std::string>>(stl::WrapStack());
  stack.apply<std::stack<std::wstring>>(stl::WrapStack());
  stack.apply<std::stack<jl_value_t*>>(stl::WrapStack());
  stack.apply<std::stack<char>>(stl::WrapStack());
  stack.apply<std::stack<unsigned char>>(stl::WrapStack());
  stack.apply<std::stack<short>>(stl::WrapStack());
  stack.apply<std::stack<unsigned short>>(stl::WrapStack());
  stack.apply<std::stack<int>>(stl::WrapStack());
  stack.apply<std::stack<unsigned int>>(stl::WrapStack());
  stack.apply<std::stack<long>>(stl::WrapStack());
  stack.apply<std::stack<unsigned long>>(stl::WrapStack());
  stack.apply<std::stack<long long>>(stl::WrapStack());
  stack.apply<std::stack<unsigned long long>>(stl::WrapStack());
}

}

}