#include <iostream>

void fib_up_to(int n){
    auto current = 0;
    auto next =1;
    
    for (auto i = 0; i < n; ++i ) {
        std::cout << current << "\n";
        auto aux = current;
        current = next;
        next += aux;
    }
}

void fib_less_than(int x){
    auto current = 0;
    auto next = 1;
    
    while (current <= x) {
        std::cout << current << "\n";
        auto aux = current;
        current = next;
        next += aux;
    }
}

int main()
{
    fib_up_to(10);
    fib_less_than(987);
    
}