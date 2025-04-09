/*
Given a string s which represents an expression, evaluate this expression and return its value. 

The integer division should truncate toward zero.

You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3/5 / 2 "
Output: 5
 
Constraints:

1 <= s.length <= 3 * 105
s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
s represents a valid expression.
All the integers in the expression are non-negative integers in the range [0, 231 - 1].
The answer is guaranteed to fit in a 32-bit integer.

*/

#include <iostream>
#include <stack>
using namespace std;

// 3+2*2

// operator  +,*
//operand    3 2 2

int mathaction(int x, int y, char oper) {

  switch (oper) {
  
    case '+' :
      return x+y;
      break;

    case '-' :
      return x-y;
      break;

    case '*' :
      return x*y;
      break;

    case '/' :
      return x/y;
      break;

    default:
      return 0;
      break;

  }

}


int calculate(string s) {

stack<char> oper;
stack<int> operands;

for(char c : s) {

  if(c >= '0' and c <='9') {
    operands.push(c*1-'0');
  } else {
    
    switch (c) {
    
      case '+' : 
      case '-' : 
      case '*' : 
      case '/' :
          oper.push(c);
          break;
    }
  }
}
 

int totalsum = 0;
while (!oper.empty()) {

  char op = oper.top();
  if(totalsum == 0) {

    int int1 = operands.top();operands.pop();
    int int2 = operands.top();operands.pop();

    totalsum = totalsum + mathaction(int2,int1,op); 
  } else {
 
    int int2 = operands.top();operands.pop();
    totalsum = mathaction(int2,totalsum,op); 

  }
  oper.pop();

}

return totalsum;

}

// To execute C++, please define "int main()"
int main() {
  cout << " calculcat " << calculate("3+2*2");
}


/*



#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int calculate(const std::string &s) {
    std::stack<int> operands;
    std::stack<char> operators;
    int num = 0;
    char prevOp = '+';

    for (size_t i = 0; i < s.length(); ++i) {
        if (std::isdigit(s[i])) {
            num = num * 10 + (s[i] - '0');
        }
        if (!std::isdigit(s[i]) && !std::isspace(s[i]) || i == s.length() - 1) {
            if (prevOp == '+') {
                operands.push(num);
            } else if (prevOp == '-') {
                operands.push(-num);
            } else if (prevOp == '*') {
                int top = operands.top();
                operands.pop();
                operands.push(top * num);
            } else if (prevOp == '/') {
                int top = operands.top();
                operands.pop();
                operands.push(top / num);
            }
            prevOp = s[i];
            num = 0;
        }
    }

    int result = 0;
    while (!operands.empty()) {
        result += operands.top();
        operands.pop();
    }
    return result;
}

int main() {
    std::string expression;
    std::cout << "Enter a mathematical expression: ";
    std::getline(std::cin, expression);

    int result = calculate(expression);
    std::cout << "Result: " << result << std::endl;

    return 0;
}

*/