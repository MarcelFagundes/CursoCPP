#include <iostream>

#include "fixed_length_vector.hpp"

void f(data_structures::FLV<int> const& v) noexcept
{
  try {
  std::cout << v.at(1624364) << '\n';
} catch (data_structures::OutOfBoundsError const&) {
  }
}


int main() 
{
  using namespace data_structures;

  auto flv = FLV<int>{7};

  try {
    std::cout << flv.at(162436) << '\n';
    } catch (OutOfBoundsError const&) {
      std::clog << "Ooops. \n";
    }
}
