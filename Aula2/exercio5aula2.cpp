#include <iostream>
#include <vector>

void remove_duplicates(std::vector<int>& v)
{
   auto last_unique = 0;

   for (auto i = 1; i < v.size(); ++i) {
    std::cout << "last_unique: " << last_unique << '\n';
    if (v[last_unique] != v[i]) {
        v[++last_unique] = v[i];
    }
   }
   v.resize(last_unique +1);
}

int main()
{
    auto ints = std::vector<int>{1, 1, 1, 2, 3, 3, 4, 1, 1} ;

    remove_duplicates(ints);

    for (auto i: ints) {
        std::cout << i << '\n';
    }
}