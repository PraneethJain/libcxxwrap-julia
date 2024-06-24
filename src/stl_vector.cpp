#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_vector(TypeWrapper1& vector)
{
  vector.apply<std::vector<bool>>(stl::WrapVector());
  vector.apply<std::vector<double>>(stl::WrapVector());
  vector.apply<std::vector<float>>(stl::WrapVector());
  vector.apply<std::vector<wchar_t>>(stl::WrapVector());
  vector.apply<std::vector<void*>>(stl::WrapVector());
  vector.apply<std::vector<std::string>>(stl::WrapVector());
  vector.apply<std::vector<std::wstring>>(stl::WrapVector());
  vector.apply<std::vector<jl_value_t*>>(stl::WrapVector());
  vector.apply<std::vector<char>>(stl::WrapVector());
  vector.apply<std::vector<unsigned char>>(stl::WrapVector());
  vector.apply<std::vector<short>>(stl::WrapVector());
  vector.apply<std::vector<unsigned short>>(stl::WrapVector());
  vector.apply<std::vector<int>>(stl::WrapVector());
  vector.apply<std::vector<unsigned int>>(stl::WrapVector());
  vector.apply<std::vector<long>>(stl::WrapVector());
  vector.apply<std::vector<unsigned long>>(stl::WrapVector());
  vector.apply<std::vector<long long>>(stl::WrapVector());
  vector.apply<std::vector<unsigned long long>>(stl::WrapVector());
}

}

}