#ifndef CALC_OPERATIONS_H
#define CALC_OPERATIONS_H

#include "expression.hpp"

namespace calc::operations {

class Number {
public:
    Number(double value):
        value_{value}
    {}

    double eval() const
    {
        return value_;
    }

private:
    double value_;
};


class Add {
public:
    Add(Expression lhs, Expression rhs):
        lhs_{std::move(lhs)},
        rhs_{std::move(rhs)}
    {}

    double eval() const
    {
        return lhs_.eval() + rhs_.eval();
    }

private:
    Expression lhs_, rhs_;
};


class Sub {
public:
    Sub(Expression lhs, Expression rhs):
        lhs_{std::move(lhs)},
        rhs_{std::move(rhs)}
    {}

    double eval() const
    {
        return lhs_.eval() - rhs_.eval();
    }

private:
    Expression lhs_, rhs_;
};


class Mul {
public:
    Mul(Expression lhs, Expression rhs):
        lhs_{std::move(lhs)},
        rhs_{std::move(rhs)}
    {}

    double eval() const
    {
        return lhs_.eval() * rhs_.eval();
    }

private:
    Expression lhs_, rhs_;
};


class Div {
public:
    Div(Expression lhs, Expression rhs):
        lhs_{std::move(lhs)},
        rhs_{std::move(rhs)}
    {}

    double eval() const
    {
        return lhs_.eval() / rhs_.eval();
    }

private:
    Expression lhs_, rhs_;
};

}


#endif
