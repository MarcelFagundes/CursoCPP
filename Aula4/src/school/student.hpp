#ifndef SCHOOL_STUDENT_HPP
#define SCHOOL_STUDENT_HPP

#include <string>
#include <vector>

namespace school {

class Student {
public:
    Student(std::string name, int entrace_year, std::vector<double> grades):
        name_{std::move(name)},
        entrance_year{entrace_year},
        grades{std::move(grades)}
    {}

    std::string const& name() const
    {
        return name_;
    }

    int years_enrolled(int current_year) const;

    double averange() const;

private:
    std::string name_;
    int entrance_year;
    std::vector<double> grades;

};

}

#endif

