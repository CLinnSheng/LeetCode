#include <functional>
#include <string>
#include <vector>

/*
 * Given a string s, split s into substring where every substring is a palindrome
 * Find out all the possible list of palindrome substrings
 *
 * So basically at each index, we can either partition it or not --> O(2^n)
 * We can use backtracking to try all possible partition
 * At each index we can only partition if the substring from i to j is a partition or choose to not partition
 * - If partiiton we need to update the i --> j + 1
 * - Then keep repeating until i == str.length()
 *
 * Time Complexity: O(n * 2^n) 2^n possible permutation and each permutation has a O(n) of checkPalindrome
 * Space Complexity: O(n)
 * */

class Solution
{
  private:
    bool isPalindrome(const std::string &str)
    {
        int left{}, right(str.length() - 1);

        while (left <= right)
        {
            if (str[left] != str[right])
            {
                return false;
            }

            left++;
            right--;
        }

        return true;
    }

  public:
    std::vector<std::vector<std::string>> partition(std::string s)
    {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> subset;

        std::function<void(const int)> backtracking = [&](const int index) {
            // Base Case
            if (index == s.length())
            {
                ans.emplace_back(subset);
                return;
            }

            for (int right{index}; right < s.length(); right++)
            {
                // If from index to right is palindrome, then parition it and go down the tree
                if (isPalindrome(s.substr(index, right - index + 1)))
                {
                    subset.emplace_back(s.substr(index, right - index + 1));
                    backtracking(right + 1);
                    subset.pop_back();
                }
            }
        };

        backtracking(0);
        return ans;
    }
};
