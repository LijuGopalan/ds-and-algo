/*
    Basic Calculator II

    Problem Statement:
    Given a string `s` which represents an expression, evaluate this expression and
    return its value. The integer division should truncate toward zero. The expression
    contains only non-negative integers, '+', '-', '*', '/' operators, and empty spaces.

    Example 1:
    Input: s = "3+2*2"
    Output: 7

    Example 2:
    Input: s = " 3/2 "
    Output: 1

    Example 3:
    Input: s = " 3+5 / 2 "
    Output: 5

    Algorithm Description:
    This solution evaluates the expression in a single pass using a stack.
    1. Iterate through the string, parsing the current number (`currentNumber`).
    2. Keep track of the last seen operator (`lastOperator`), initialized to '+'.
    3. When we encounter a new operator (or reach the end of the string), we evaluate
       the `currentNumber` based on the `lastOperator`:
       - If `+`, push `currentNumber` onto the stack.
       - If `-`, push `-currentNumber` onto the stack.
       - If `*`, pop the top of the stack, multiply it by `currentNumber`, and push the result back.
       - If `/`, pop the top of the stack, divide it by `currentNumber`, and push the result back.
    4. After the loop, the stack contains only the terms to be added. Summing up all
       the numbers in the stack gives the final result. This approach correctly handles
       operator precedence because `*` and `/` are evaluated immediately, while `+` and `-`
       are deferred until the final summation.
*/

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype> // For isdigit and isspace

/**
 * @brief Evaluates a string expression with +,-,*,/ operators.
 *
 * @param s The input string expression.
 * @return The integer result of the evaluation.
 */
int calculate(const std::string& s) {
    std::stack<int> operands;
    long currentNumber = 0;
    char lastOperator = '+';

    for (size_t i = 0; i < s.length(); ++i) {
        char currentChar = s[i];
        if (std::isdigit(currentChar)) {
            currentNumber = currentNumber * 10 + (currentChar - '0');
        }
        // An operator is found, or we are at the end of the string
        if (!std::isdigit(currentChar) && !std::isspace(currentChar) || i == s.length() - 1) {
            if (lastOperator == '+') {
                operands.push(currentNumber);
            } else if (lastOperator == '-') {
                operands.push(-currentNumber);
            } else if (lastOperator == '*') {
                int top = operands.top();
                operands.pop();
                operands.push(top * currentNumber);
            } else if (lastOperator == '/') {
                int top = operands.top();
                operands.pop();
                operands.push(top / currentNumber);
            }
            // Update the last operator and reset the current number
            lastOperator = currentChar;
            currentNumber = 0;
        }
    }

    int result = 0;
    while (!operands.empty()) {
        result += operands.top();
        operands.pop();
    }
    return result;
}

/**
 * @brief Main function to test the calculate function.
 * @return 0 on successful execution.
 */
int main() {
    std::string s1 = "3+2*2";
    std::cout << "Expression: \"" << s1 << "\", Result: " << calculate(s1) << " (Expected: 7)" << std::endl;

    std::string s2 = " 3/2 ";
    std::cout << "Expression: \"" << s2 << "\", Result: " << calculate(s2) << " (Expected: 1)" << std::endl;

    std::string s3 = " 3+5 / 2 ";
    std::cout << "Expression: \"" << s3 << "\", Result: " << calculate(s3) << " (Expected: 5)" << std::endl;

    std::string s4 = "1-1+1";
    std::cout << "Expression: \"" << s4 << "\", Result: " << calculate(s4) << " (Expected: 1)" << std::endl;

    return 0;
}