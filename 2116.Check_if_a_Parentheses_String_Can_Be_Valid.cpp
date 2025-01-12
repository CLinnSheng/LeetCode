#include <deque>
#include <string>
using std::string;

/*
 * Goal: Check can make s a valid parenthesis string or not.
 *
 * Given a a string locked where locked[i] can be either 0 or 1
 * 0: Can change to either '(' or ')'
 * 1: Cannot change s[i]
 *
 * Intuition:
 * This is a checking parenthesis problem, so the first thing that comes in mind is by using check stack.
 * Because we want to match the most recent '(' with the next encounter ')'
 * Note that here we have a wild card which is lock[i] = '0'
 * so our focus in just on how to close the '(' with ')' because the wild card can be either of it
 * So we need 2 stack, one holds for the '(' and another holds for the wild card.
 * We only use the wild card when we have no chocie
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    bool canBeValid(string s, string locked)
    {
        // base case
        if (s.length() % 2)
            return false;
        if (s[0] == ')' && locked[0] == '1')
            return false;

        std::deque<int> wildCard, leftParenthesis;

        for (int i{}; i < locked.length(); i++)
        {
            if (locked[i] == '0')
                wildCard.emplace_back(i);
            else if (s[i] == '(')
                leftParenthesis.emplace_back(i);
            else
            {
                if (!leftParenthesis.empty())
                    leftParenthesis.pop_back();
                else if (!wildCard.empty())
                    wildCard.pop_back();
                else
                    return false;
            }
        }

        // make sure all the left parenthesis is mapped
        while (!leftParenthesis.empty() && !wildCard.empty())
        {
            if (leftParenthesis.back() < wildCard.back())
            {
                leftParenthesis.pop_back();
                wildCard.pop_back();
            }
            else
                return false;
        }

        if (!leftParenthesis.empty())
            return false;

        return wildCard.size() % 2 ? false : true;
    }
};
