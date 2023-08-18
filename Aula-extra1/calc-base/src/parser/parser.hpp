#ifndef CALC_LOGIC_CALC_LOGIC_H
#define CALC_LOGIC_CALC_LOGIC_H

#include <string_view>
#include <stdexcept>

#include "expression.hpp"

namespace calc::parser {

struct SyntaxError: std::runtime_error {
    using runtime_error::runtime_error;
};

struct UnexpectedCharacter : SyntaxError {
    using SyntaxError::SyntaxError;
};

Expression parse(std::string_view v);

}

#endif

