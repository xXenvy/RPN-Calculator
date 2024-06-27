#include "calculator.h"
#include <stack>
#include <stdexcept>
#include <cmath>

float RPNCalculator::calculate(const std::vector<Token>& tokens) const {
    // Calculates the final result based on RPN notation.
    std::stack<Token> stack;

    for (const Token& token : tokens) {
        if (!token.is_operator()) {
            stack.push(token); // Add a number to stack.
            continue;
        }

        // Adds the result of the operator and the last two numbers from the stack.
        const float a_value = std::stof(stack.top().value);
        stack.pop();

        const float b_value = std::stof(stack.top().value);
        stack.pop();

        const float result = get_equation_result(token.value_as_char, b_value, a_value);
        stack.push(Token{ std::to_string(result) });
    }
    if (stack.empty()) return 0.0;
    return std::stof(stack.top().value);
}

float RPNCalculator::get_equation_result(const char& _operator, const float a, const float b) const {
    switch (_operator) {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '/':
            if (b == 0) throw std::runtime_error("Division by zero.");
            return a / b;
        case '*':
            return a * b;
        case '^':
            return std::pow(a, b);
        case '%':
            if (static_cast<int>(b) == 0) throw std::runtime_error("Modulo by zero.");
            return static_cast<float>(static_cast<int>(a) % static_cast<int>(b));
        default:
            throw std::runtime_error("Invalid operator.");
    }
}

float RPNCalculator::process(const std::string& input) const {
    // Calculates the result from the String input.
    return process_from_tokens(parser.read_tokens(input));
}

float RPNCalculator::process_from_tokens(const std::vector<Token>& tokens) const {
    // Calculates the result from non-parsed tokens.
    return calculate(parser.parse(tokens));
}
