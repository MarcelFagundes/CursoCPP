#include <iostream>

int main()
{
    for (auto i= 1; i <= 100; ++i) {
        if (i % 2 ==0) {
            std::cout << i << "\n";
        }
    }
}