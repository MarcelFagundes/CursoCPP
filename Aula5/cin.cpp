#include <iostream>
#include <fstream>
#include <optional>
#include <string>
#include <istream>
#include <sstream>
#include <iostream>

std::optional<int> get_int(std::istream& in)
{
  using namespace std::string_literals;

  auto buf = ""s;
  std::getline(in, buf);

  auto sstr = std::stringstream{buf};
  auto result = 0;
  sstr >> result;

  if (not sstr.fail()) {
    return result;
  }
  return{};
}

int ensure_get_int(std::istream& in, std::string const& reprompt_text)
{
  auto result = get_int(in);

  while (not result) {
    std::cout << reprompt_text;
    result = get_int(in);
  }
  return *result;
}

int main_(std::istream& input)
{
  std::cout << "Enter the current year: ";
  auto year = ensure_get_int(input, "Please reenter the current year: ");

  std::cout << "Enter your age: ";
  auto age = ensure_get_int(input, "Please reenter your age: ");

  std::cout << "Hello! I see you were born in "
        << year - age << "!\n";

  return 0;
}

int main(int argc, char **argv) 
{
  if (argc < 2) {
    std::cout << "Please give a file as an argument.\n";
    return 1;
  } 

  auto filename = std::string{argv[1]};
  auto is_stdin = filename == "-";

  if (is_stdin) {
    return main_(std::cin);             
  }

  auto file = std::fstream{filename};
  return main_(file);
}
