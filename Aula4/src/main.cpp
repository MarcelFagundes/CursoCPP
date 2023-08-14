#include <iostream>
#include <string>
#include <vector>

#include "student.hpp"
#include "functions.hpp"

int main()
{
    using namespace std::string_literals;
    using school::Student;

    // TODO: initialize a vector called `students` here
    auto students = std::vector<Student>{
        Student{"Aluno 1", 2010, {9.5, 7.5, 8.0}},
        Student{"Aluno 2", 2017, {4.0, 3.0, 5.0}},
        Student{"Aluno 3", 2018, {8.0, 9.0, 7.0}}
    };


    for (auto s: school::approved(students)) {
        std::cout << s.name()
                  << " is approved by grade with average "
                  << s.averange() << ".\n";
    }

    for (auto s: school::dismissed_by_time(students, 2019)) {
        std::cout << s.name()
                  << " was dismissed for being in the course for too long: "
                  << s.years_enrolled(2019) << " years.\n";
    }
}
