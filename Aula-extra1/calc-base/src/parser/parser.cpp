#include "parser.hpp"

#include <algorithm>
#include <optional>
#include <string>

#include "operations.hpp"

using namespace calc;
using namespace calc::parser;
using namespace calc::operations;

namespace {
	enum class AdditiveOperator {
		ADD,
		SUB,
	};

	enum class MultiplicativeOperator {
		MUL,
		DIV,
	};

    struct Continuation {
        Expression expr;
        std::string_view remainder;
    };

	Continuation additive(std::string_view);

	std::string_view remove_prefix(std::string_view v, std::string_view::size_type pos) {
		v.remove_prefix(std::min(pos, v.size()));
		return v;
	}

	std::string_view skip_whitespace(std::string_view v) {
		auto pos = v.find_first_not_of(" \n\t\r");
		return remove_prefix(v, pos);
	}

	std::optional<AdditiveOperator> check_additive(std::string_view v) {
		v = skip_whitespace(v);

		if (v.empty()) {
			return std::nullopt;
		}

		switch (v.front()) {
		case '+':
			return AdditiveOperator::ADD;
		case '-':
			return AdditiveOperator::SUB;
		default:
			return std::nullopt;
		}
	}

	std::optional<MultiplicativeOperator> check_multiplicative(std::string_view v) {
		v = skip_whitespace(v);

		if (v.empty()) {
			return std::nullopt;
		}

		switch (v.front()) {
		case '*':
			return MultiplicativeOperator::MUL;
		case '/':
			return MultiplicativeOperator::DIV;
		default:
			return std::nullopt;
		}
	}

	bool check_parenthesis(std::string_view v) {
		v = skip_whitespace(v);
		return v.front() == '(';
	}

	std::string_view skip_until(char c, std::string_view v) {
		v = skip_whitespace(v);

		if (v.front() != c) {
            // TODO: Use fmt.
			throw UnexpectedCharacter{""};
		}

		return remove_prefix(v, 1);
	}

	Continuation number(std::string_view v) {
		v = skip_whitespace(v);
		auto end = v.find_first_not_of("0123456789.");
		auto number_text = std::string(v.substr(0, end));
		return { Number{std::stod(number_text)}, remove_prefix(v, end) };
	}

	Continuation expression(std::string_view v) {
		auto parenthesis = check_parenthesis(v);

		if (parenthesis) {
			v = skip_until('(', v);
			auto[a, v2] = additive(v);
			v2 = skip_until(')', v2);
			return { std::move(a), v2 };
		}

		auto [n, v2] = number(v);
		return { std::move(n), v2 };
	}

	Continuation multiplicative(std::string_view v) {
		auto [e, v2] = expression(v);
		auto operation = check_multiplicative(v2);

		if (!operation) {
			return { std::move(e), v2 };
		}

		switch (*operation) {
		case MultiplicativeOperator::MUL: {
			v2 = skip_until('*', v2);
			auto [a, v3] = multiplicative(v2);
			return { Mul{ std::move(e), std::move(a) }, v3 };
		}
		case MultiplicativeOperator::DIV:
			v2 = skip_until('/', v2);
			auto [a, v3] = multiplicative(v2);
			return { Div{ std::move(e), std::move(a) }, v3 };
		}

        __builtin_unreachable();
	}

	Continuation additive(std::string_view v) {
		auto [e, v2] = multiplicative(v);
		auto operation = check_additive(v2);

		if (!operation) {
			return { std::move(e), v2 };
		}

		switch (*operation) {
            case AdditiveOperator::ADD: {
                auto remainder = skip_until('+', v2);
                auto [a, v3] = additive(remainder);
                return { Add{ std::move(e), std::move(a) }, v3 };
            }
            case AdditiveOperator::SUB: {
                auto remainder = skip_until('-', v2);
                auto [a, v3] = additive(remainder);
                return { Sub{ std::move(e), std::move(a) }, v3 };
            }
		}

        __builtin_unreachable();
	}
}

namespace calc::parser {
	Expression parse(std::string_view v) {
		auto [expr, v2] = additive(v);

		v2 = skip_whitespace(v2);

		if (!v2.empty()) {
			throw UnexpectedCharacter{""};
		}

		return expr;
	}

}
