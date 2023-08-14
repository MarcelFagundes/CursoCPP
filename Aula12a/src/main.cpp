#include <iostream>

#include "linked_list.hpp"

int main()
{
  using namespace strutures;

  auto l = LinkedList<int>{};

  l.push_front(3);
  l.push_front(2);
  l.push_front(1);

for (auto i: l) {
  std::cout << i << '\n';
}
}