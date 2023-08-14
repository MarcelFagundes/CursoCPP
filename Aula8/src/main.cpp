#include "fixed_length_vector.hpp"

#include <algorithm>
#include <iostream>

template<typename T>
T&& my_move(T& obj)
{
  return static_cast<T&&>(obj);
}


int main ()
{
  using namespace data_structures;

  auto flv = FLV<int>{7};

  flv[5] = 3;

  auto flv2 = flv;
  flv2 = flv;

  flv2[5] = 5;

  std::cout << flv[5] << "\n";

  auto flv_s = FLV<std::string>{7};

  flv_s[5] = "abc";

  std::cout << flv_s[5] << "\n";

  flv_s = flv_s;

  std::cout << flv_s[5] << "\n";

//  auto flv_s2 = my_move(flv_s);

  auto flv_s2 = std::move(flv_s);
    
}
