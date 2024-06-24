#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_priority_queue(TypeWrapper1& priority_queue)
{
  priority_queue.apply<std::priority_queue<bool>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<double>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<float>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<wchar_t>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<void*>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<std::string>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<std::wstring>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<jl_value_t*>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<char>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<unsigned char>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<short>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<unsigned short>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<int>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<unsigned int>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<long>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<unsigned long>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<long long>>(stl::WrapPriorityQueue());
  priority_queue.apply<std::priority_queue<unsigned long long>>(stl::WrapPriorityQueue());
}

}

}