#include <iostream>
#include <vector>
#include <numeric>  // std::accumulate

//Evitando cópia no primeiro exemplo


namespace const_ref {

double average_squares(const std::vector<double>& values)
{
    auto total = 0.0;

    for (auto i: values) {
        total += i*i;
    }

    return total/values.size();
}

}

int main()
{
    auto values = std::vector<double>(1000000);

    std::iota(begin(values), end(values), 1.0);

    std::cout << const_ref::average_squares(values) << '\n';
}
