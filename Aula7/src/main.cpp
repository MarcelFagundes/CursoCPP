#include <iostream>
#include <memory>
#include "linked_list.hpp"

int main()
{
    using namespace strutures;

  auto l = LinkedList<int>{};

  l.push_front(3);
  l.push_front(2);
  l.push_front(1);

  for (auto i = 0u; i < l.size(); ++i) {
    std::cout << l.nth(i) << '\n';
  }
  auto l2 = l;

  for (auto i = 0u; i < l2.size(); ++i) {
    std::cout << l2.nth(i) << '\n';
  }

  auto ls = LinkedList<std::string>{};

  ls.push_front("World");
  ls.push_front("Hello");
  
  for (auto i = 0u; i < ls.size(); ++i) {
    std::cout << ls.nth(i) << '\n';
  }
    
  auto li = LinkedList<std::unique_ptr<int>>{};

  li.push_front(std::make_unique<int>(3));
  li.push_front(std::make_unique<int>(2));
  li.push_front(std::make_unique<int>(1));
  

  for (auto i = 0u; i < li.size(); ++i) {
    std::cout << *(li.nth(i)) << '\n';
  } 
}
