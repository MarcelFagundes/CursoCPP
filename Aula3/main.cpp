#include <iostream>
#include "vector2d.hpp"

void print(math::Vector2D const& v)
{
    std::cout << '{' << v.x() <<", " << v.y() << "}\n";
}

int main()
{
    auto v = math::Vector2D{2, 3};   
    print(v);
    v.invert() *= 5;
    print(v);

    auto u = v + v;
    print(u);

    u = v *5;
    print(u);
}