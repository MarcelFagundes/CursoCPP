#include <iostream>
#include <stdexcept>
#include <vector>

class C {
public:
  C() {
    std::cout << "C()!\n";
  }

  ~C() {
    std::cout << "~C()!\n";
  }
};

int main()
try {
  auto v = std::vector<int>{3, 2, 1};

  auto c = C{};

  try {
    std::cout << v.at(-3) << '\n' << std::flush;
    throw std::runtime_error("Generic error!");
  } catch (std::out_of_range const& e) {
    std::cout << e.what() << '\n'; //"Error, tried to access vector out of bounds!\n");
  } catch (std::exception const&) {
    std::cout << "Error! Somenthing happned!\n";
    throw;
  }

    std::cout << "Done.\s" << std::flush;
  } catch (...) {
}
