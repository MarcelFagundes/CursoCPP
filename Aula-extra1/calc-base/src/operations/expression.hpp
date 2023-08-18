#ifndef CALC_EXPRESSION_H
#define CALC_EXPRESSION_H

#include <concepts>
#include <memory>

namespace calc {

template <typename T>
concept Evaluable = requires(T const& t) {
    { t.eval() } -> std::same_as<double>;
};


class Expression {
public:
    template <Evaluable T>
    Expression(T t):
        inner{std::make_shared<InnerImpl<T>>(std::move(t))}
    {}

    double eval() const {
        return inner->eval();
    }

private:
    struct Inner {
        virtual ~Inner() = default;
        virtual double eval() const = 0;
    };

    template <Evaluable T>
    struct InnerImpl: Inner {
        InnerImpl(T t):
            t_{std::move(t)}
        {}

        double eval() const override
        {
            return t_.eval();
        }

        T t_;
    };

    std::shared_ptr<Inner const> inner;
};

}

#endif
