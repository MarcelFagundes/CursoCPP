#include <concepts>
#include <iostream>
#include <memory>
#include <sstream>

#include "expression.hpp"
//#include "operations.hpp"
#include "parser.hpp"


//int main()
// {
//     using namespace calc;
//     using namespace calc::operations;

//     Expression a = Add(Number{3.0}, Number{6.0});

//     std::cout << a.eval() << '\n';
// }

int main()
{
    using namespace calc::parser;

    auto expr = parse("3 + 6");

    std::cout << expr.eval() << '\n';
}