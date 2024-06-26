#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

constexpr char operators[8] = { '+', '-', '*', '/', '(', ')', '^', '%' };

struct Token {
    const std::string value;
    const char value_as_char = *value.c_str();

    bool is_operator() const;
    int get_priority() const;
};

class RPNParser {
public:
    std::vector<Token> parse(const std::vector<Token>& tokens) const;
    std::vector<Token> read_tokens(const std::string& text) const;
};

#endif // PARSER_H
