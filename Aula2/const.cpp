#include <iostream>
#include <numeric>  // std::accumulate
#include <vector>

// Mecanismo de passagem por valor

namespace value {

double average_squares(std::vector<double> values)
{
    for (auto& i: values) {
        i *= i;
    }

    return std::accumulate(begin(values), end(values), 0.0)/values.size();
}

}


int main()
{
    auto values = std::vector<double>(1000000);

    std::iota(begin(values), end(values), 1.0);

    std::cout << value::average_squares(values) << '\n';
}
