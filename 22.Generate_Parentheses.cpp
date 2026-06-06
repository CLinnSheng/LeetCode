#include <functional>
#include <string>
#include <vector>

/*
 * Generate all possible combination of parenthesis
 * So at any point we can either place a ')' or '(' & since we
 * want to find out all possible combination of parenthesis. Backtracking algo will be suitable because of trying all
 * possible path
 * But what is the base case?
 * Only when the number of open and close parenthesis is equal to n.
 * And also we need to handle which parenthesis to put at any point because we dont want to produce invalid parenthesis
 * like this '())('
 * So what we can do is keep track of the open & close. And determine which parenthesis to put based on the number
 * */

class Solution
{
  public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::string> ans;
        std::string str{};

        std::function<void(const int, const int)> backtracking = [&](const int open, const int close) {
            if (str.length() == 2 * n && open == close)
            {
                ans.emplace_back(str);
                return;
            }

            // We always want to have the open at the front, so if when close equal to open then we push open
            // **Try all possible way** so just if
            if (open < n)
            {
                str.push_back('(');
                backtracking(open + 1, close);
                str.pop_back();
            }

            if (open > close)
            {
                str.push_back(')');
                backtracking(open, close + 1);
                str.pop_back();
            }
        };

        backtracking(0, 0);
        return ans;
    }
};
