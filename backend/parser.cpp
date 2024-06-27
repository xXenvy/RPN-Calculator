#include "parser.h"
#include <stack>

bool Token::is_operator() const {
    // Whether the token is an operator.
    for (const char& op : operators) {
        if (value_as_char == op) {
            return true;
        }
    }
    return false;
}

int Token::get_priority() const {
    // Get the priority of the token, since each operator has a different one.
    switch (value_as_char) {
        case '+': case '-': case ')':
            return 1;
        case '*': case '/': case '%':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

std::vector<Token> RPNParser::parse(const std::vector<Token>& tokens) const {
    // Parses tokens into RPN annotation.
    // Example: "1", "+", "2" -> "1", "2", "+"
    std::vector<Token> output;
    output.reserve(tokens.capacity());
    std::stack<Token> stack;

    for (const Token& token : tokens) {
        if (!token.is_operator()) {
            // Not an operator. We can add a number to output.
            output.push_back(token);
            continue;
        }
        switch (token.value_as_char) {
            case '(':
                stack.push(token);
                break;
            case ')':
                while (stack.size()) {
                    const Token top_operator = stack.top();
                    stack.pop();
                    if (top_operator.value == "(") break; // Move all operators to output until '(' appears.
                    output.push_back(top_operator);
                }
                break;
            default: // Operators: +, −, ×, /, %, ^.
                while (stack.size()) {
                    // We have to move all higher-priority operators to output
                    // before adding a new operator to the stack.
                    const Token top_operator = stack.top();
                    if (top_operator.get_priority() < token.get_priority()) break;

                    output.push_back(top_operator);
                    stack.pop();
                }
                stack.push(token);
        }
    }
    // Move the rest of the crap from the stack to output.
    while (stack.size()) {
        output.push_back(stack.top());
        stack.pop();
    }
    return output;
}

std::vector<Token> RPNParser::read_tokens(const std::string& text) const {
    // Reads tokens from the string text.
    // Token is a single element, for example full number or an operator.
    std::vector<Token> tokens;
    tokens.reserve(text.size());
    std::string token_value;

    for (const char& ch : text) {
        if (std::isspace(ch)) continue;
        if (std::isdigit(ch) || ch == '.') {
            token_value += ch;
            continue;
        }
        if (!token_value.empty()) {
            tokens.push_back(Token{ token_value });
            token_value.clear();
        }
        tokens.push_back(Token{ std::string(1, ch) });
    }
    if (!token_value.empty()) {
        tokens.push_back(Token{ token_value });
    }
    return tokens;
}
