#include <functional>
#include <string>
#include <vector>

/*
 * 's' can be split int osubstrings where every substring is a palindrome
 * Goal: Return all possible lists of palindromic substrings
 *
 * Intuition:
 * We need a helper function to check Palindrome, and then we can just use dfs and backtracking to try all possible
 * palindrome substring Time Complexity: O(n * 2^n)
 *
 * */
class Solution
{
  private:
    bool checkPalindrome(const std::string &str)
    {
        int left{}, right(str.length() - 1);

        while (left < right)
        {
            if (str[left] != str[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

  public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        if (s.length() == 0)
            return {};

        std::vector<std::vector<std::string>> answer;
        std::vector<std::string> currSubset;

        std::function<void(const int &)> dfs_backtracking = [&](const int &index) {
            // Base Case
            if (index == s.length())
            {
                answer.emplace_back(currSubset);
                return;
            }

            for (int i{index}; i < s.length(); i++)
            {
                std::string subStr{s.substr(index, i - index + 1)};
                if (checkPalindrome(subStr))
                {
                    currSubset.emplace_back(subStr);
                    dfs_backtracking(i + 1);

                    // backtracking
                    currSubset.pop_back();
                }
            }
        };
        dfs_backtracking(0);
        return answer;
    }
};
