#include <iostream>

int main()
{
    for (auto i= 1; i <= 100; ++i) {
        if (i % 3 == 0 and i % 5 == 0) {
            std::cout << "fizzbuzz\n";
        } else if (i % 3 == 0) {
            std::cout << "fizz\n";
        } else if (i % 5 == 0) {
            std::cout << "buzz\n";
        } else {
            std::cout << "\n";
        }
    }
}