#include "jlcxx/stl.hpp"

namespace jlcxx
{

namespace stl
{

void apply_valarray(TypeWrapper1& valarray)
{
  valarray.apply<std::valarray<bool>>(stl::WrapValArray());
  valarray.apply<std::valarray<double>>(stl::WrapValArray());
  valarray.apply<std::valarray<float>>(stl::WrapValArray());
  valarray.apply<std::valarray<wchar_t>>(stl::WrapValArray());
  valarray.apply<std::valarray<void*>>(stl::WrapValArray());
  valarray.apply<std::valarray<std::string>>(stl::WrapValArray());
  valarray.apply<std::valarray<std::wstring>>(stl::WrapValArray());
  valarray.apply<std::valarray<jl_value_t*>>(stl::WrapValArray());
  valarray.apply<std::valarray<char>>(stl::WrapValArray());
  valarray.apply<std::valarray<unsigned char>>(stl::WrapValArray());
  valarray.apply<std::valarray<short>>(stl::WrapValArray());
  valarray.apply<std::valarray<unsigned short>>(stl::WrapValArray());
  valarray.apply<std::valarray<int>>(stl::WrapValArray());
  valarray.apply<std::valarray<unsigned int>>(stl::WrapValArray());
  valarray.apply<std::valarray<long>>(stl::WrapValArray());
  valarray.apply<std::valarray<unsigned long>>(stl::WrapValArray());
  valarray.apply<std::valarray<long long>>(stl::WrapValArray());
  valarray.apply<std::valarray<unsigned long long>>(stl::WrapValArray());
}

}

}