#include <iostream>
#include <vector>

std::vector<int> remove_duplicates(std::vector<int> const& v)
{
    auto deduped = std::vector<int>();

    for (auto i: v) {
        if (deduped.empty() or deduped.back() != i) {
            deduped.push_back(i);
        }
    }
    return deduped;
}

int main()
{
    for (auto i: remove_duplicates({1, 1, 1, 2, 3, 3, 4, 1, 1})) {
        std::cout << i << '\n';
    }
}
