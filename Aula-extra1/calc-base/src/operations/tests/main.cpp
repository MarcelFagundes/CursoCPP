#include<catch2/catch.hpp>

#include "operations.hpp"

TEST_CASE("Add property", "[operations]")
{
    using namespace calc::operations;

    REQUIRE((Add{Number{3.0},Number{6.0}}.eval() == 9.0));
}


TEST_CASE("Mul property", "[operations]") 
{
    using namespace calc::operations;

    REQUIRE((Mul{Number{3.0},Number{6.0}}.eval() == 18.0));
}

TEST_CASE("Sub property", "[operations]") 
{
    using namespace calc::operations;

    REQUIRE((Sub{Number{3.0},Number{6.0}}.eval() == -3.0));
}

TEST_CASE("Div property", "[operations]") 
{
    using namespace calc::operations;

    REQUIRE((Div{Number{3.0},Number{6.0}}.eval() == 0.3));
}

// assert_true(Add{Number{3.0},Number{6.0}}.eval() == 9.0);
//     assert_true(Mul{Number{3.0},Number{6.0}}.eval() == 18.0);
//     assert_true(Sub{Number{3.0},Number{6.0}}.eval() == -3.0);
//     assert_true(Div{Number{3.0},Number{6.0}}.eval() == 0.3);


