#include <iostream>
#include <stdexcept>
#include "operations.hpp"


struct AssertionError: std::runtime_error {
    using std::runtime_error::runtime_error;
};

void assert_true(bool value)
{
        if (not value) {
            throw AssertionError("Test failed");
        }
}


int main()
try {
    using namespace calc::operations;

    assert_true(Add{Number{3.0},Number{6.0}}.eval() == 9.0);
    assert_true(Mul{Number{3.0},Number{6.0}}.eval() == 18.0);
    assert_true(Sub{Number{3.0},Number{6.0}}.eval() == -3.0);
    assert_true(Div{Number{3.0},Number{6.0}}.eval() == 0.3);

} catch (AssertionError const& e) {
    std::clog << e.what() << '\n';
    return 1;
} catch (...){
    return 2;
}