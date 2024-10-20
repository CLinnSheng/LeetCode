#include <deque>
#include <string>

/*
 * Parse the string 'boolean' expression and return the evaluation of the string
 * Intuition: Have a stack to store the char of expression
 * So we will keep store until we meet a ')' and then pop the stack until '(' &
 * 1 more operator and then do the operation and pass back into the stack again
 * and then continue until the stack only left with 1 element
 *
 * Time Complexity: O(n) Iterate through teh array & even though the operation
 * for AND and OR is O(n) but we are not doing it for every sinlge character and
 * only dealing with it when we encounter closing parenthesis ')'. Space
 * Complexity: O(n)
 * */
class Solution {
public:
  bool parseBoolExpr(std::string expression) {
    std::deque<char> stack;

    int len(expression.length());
    for (int i = 0; i < len; i++) {
      char currentChar = expression[i];

      if (currentChar == ',')
        continue;
      else if (stack.empty())
        stack.emplace_back(currentChar);
      else {
        if (currentChar == ')') {
          std::string temp{};

          while (stack.back() != '(') {
            temp += stack.back();
            stack.pop_back();
          }

          // pop the '('
          stack.pop_back();
          char logical = stack.back();
          stack.pop_back();

          switch (logical) {
          case '&':
            stack.emplace_back(parseAND(temp) ? 't' : 'f');
            break;
          case '|':
            stack.emplace_back(parseOR(temp) ? 't' : 'f');
            break;
          case '!':
            stack.emplace_back(temp[0] == 't' ? 'f' : 't');
            break;
          }

        } else
          stack.emplace_back(currentChar);
      }
    }
    return stack.back() == 't' ? true : false;
  }

  bool parseAND(const std::string &s) {
    for (const char &c : s)
      if (c == 'f')
        return false;

    return true;
  }

  bool parseOR(const std::string &s) {
    for (const char &c : s)
      if (c == 't')
        return true;

    return false;
  }
};
