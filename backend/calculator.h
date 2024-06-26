#ifndef CALCULATOR_H
#define CALCULATOR_H

#include "parser.h"

class RPNCalculator {
private:
    RPNParser parser;

    float calculate(const std::vector<Token>& tokens) const;
    float get_equation_result(const char& _operator, const float a, const float b) const;

public:
    float process(const std::string& input) const;
    float process_from_tokens(const std::vector<Token>& tokens) const;
};

#endif // CALCULATOR_H
