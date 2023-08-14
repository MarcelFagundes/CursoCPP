#include "student.hpp"

namespace school {

int Student::years_enrolled(int current_year) const
{
    return current_year - entrance_year;
}

double Student::averange() const
{
    auto total = 0.0;

    for (auto g: grades) {
        total += g;
    }
    return total / grades.size();
}

}