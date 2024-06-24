#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_deque(TypeWrapper1& deque)
{
  deque.apply<std::deque<bool>>(stl::WrapDeque());
  deque.apply<std::deque<double>>(stl::WrapDeque());
  deque.apply<std::deque<float>>(stl::WrapDeque());
  deque.apply<std::deque<wchar_t>>(stl::WrapDeque());
  deque.apply<std::deque<void*>>(stl::WrapDeque());
  deque.apply<std::deque<std::string>>(stl::WrapDeque());
  deque.apply<std::deque<std::wstring>>(stl::WrapDeque());
  deque.apply<std::deque<jl_value_t*>>(stl::WrapDeque());
  deque.apply<std::deque<char>>(stl::WrapDeque());
  deque.apply<std::deque<unsigned char>>(stl::WrapDeque());
  deque.apply<std::deque<short>>(stl::WrapDeque());
  deque.apply<std::deque<unsigned short>>(stl::WrapDeque());
  deque.apply<std::deque<int>>(stl::WrapDeque());
  deque.apply<std::deque<unsigned int>>(stl::WrapDeque());
  deque.apply<std::deque<long>>(stl::WrapDeque());
  deque.apply<std::deque<unsigned long>>(stl::WrapDeque());
  deque.apply<std::deque<long long>>(stl::WrapDeque());
  deque.apply<std::deque<unsigned long long>>(stl::WrapDeque());
}

}

}