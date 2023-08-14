#include <algorithm>
#include <iostream>
#include <vector>

#include "vector.hpp"


class Bomb {
public:
  Bomb():
      number{total_bomb_count}
  {
    std::cout << "Creating a bomb with number " << number << "...\n";
    if (current_bomb_count == 4) {
      std::cout << "Oh no.\n";
      throw std::runtime_error("Bomb exploded.");
    }       
    ++current_bomb_count;
    ++total_bomb_count;
  }
  Bomb(Bomb const& other):
    number{total_bomb_count}
  {  
    std::cout << "Copying a bomb number " << other.number << " into " << number << "...\n";
    if (current_bomb_count == 4) {
      std::cout << "Oh no.\n";
      throw std::runtime_error("Bomb exploded.");
    }
    ++current_bomb_count;
    ++total_bomb_count;
  }

  Bomb(Bomb&& other):
    number{other.number}
  {
    other.number = -1;
  }

  ~Bomb() {

    if (number != -1) {
      --current_bomb_count;
      std::cout << "Bomb " << number << " never exploded.\n";
    }
  }  

private:
  static int current_bomb_count;
  static int total_bomb_count;
  int number;
};

int Bomb::current_bomb_count = 0;
int Bomb::total_bomb_count = 0;

int main()
try {
  std::cout << "vector test. \n";

  using namespace data_structures;
  // auto bombs = std::vector<Bomb{5};
  // auto bombs = Vector<Bomb>{2};
  // auto bombs2 = std::move(bombs);

  // auto bombs3 = Vector<Bomb>{0};
  // bombs3 = std::move(bombs2);

  //auto bombs = Vector<Bomb>{2};
  //bombs.push_back(Bomb{});
  //bombs.push_back(Bomb{});

  //auto bombs2 = bombs;

  //std::cout << "I survived!\n";
 
  //std::cout << bombs.size() << '\n';
  
  auto v = Vector<int>{0};

  v.push_back(4);
  v.push_back(3);
  v.push_back(2);
  v.push_back(1);

  // for (auto i = 0; i < v.size(); ++i) {
  //   std::cout << v[i] << '\n';  
  // }

  for (auto i: v) {
    std::cout << i << '\n';
  }

  // std::cout <<"Sorting ... \n";


  // std::sort(v.begin(),v.end());

  // for (auto i: v) {
  //   std::cout << i << '\n';
  // }

  std::cout <<"Sorting partial... \n";

  auto half = v.begin() + 2; 

  std::sort(v.begin(),half);

  for (auto i: v) {
      std::cout << i << '\n';
  } 

  

} catch (...) {

}
