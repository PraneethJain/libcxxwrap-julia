#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_queue(TypeWrapper1& queue)
{
  queue.apply<std::queue<bool>>(stl::WrapQueue());
  queue.apply<std::queue<double>>(stl::WrapQueue());
  queue.apply<std::queue<float>>(stl::WrapQueue());
  queue.apply<std::queue<wchar_t>>(stl::WrapQueue());
  queue.apply<std::queue<void*>>(stl::WrapQueue());
  queue.apply<std::queue<std::string>>(stl::WrapQueue());
  queue.apply<std::queue<std::wstring>>(stl::WrapQueue());
  queue.apply<std::queue<jl_value_t*>>(stl::WrapQueue());
  queue.apply<std::queue<char>>(stl::WrapQueue());
  queue.apply<std::queue<unsigned char>>(stl::WrapQueue());
  queue.apply<std::queue<short>>(stl::WrapQueue());
  queue.apply<std::queue<unsigned short>>(stl::WrapQueue());
  queue.apply<std::queue<int>>(stl::WrapQueue());
  queue.apply<std::queue<unsigned int>>(stl::WrapQueue());
  queue.apply<std::queue<long>>(stl::WrapQueue());
  queue.apply<std::queue<unsigned long>>(stl::WrapQueue());
  queue.apply<std::queue<long long>>(stl::WrapQueue());
  queue.apply<std::queue<unsigned long long>>(stl::WrapQueue());
}

}

}