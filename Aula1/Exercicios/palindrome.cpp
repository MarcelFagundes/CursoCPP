#include <iostream>
#include <string>

std::string check_palindrome(std::string text)
{
    auto size = text.size();

    for (auto i = 0; i < size/2; ++i) {
        if (text[i] != text[size-1 - i]){
            return "not a palindrome";
        }
    }
    return "palindrome";
}

int main()
{
    using namespace std::string_literals;

    std::cout << "arara is "s << check_palindrome("arara"s) << "\n";
    std::cout << "banana is "s << check_palindrome("banana"s) << "\n";
}