#include <algorithm>
#include <string>
#include <vector>

/*
 * Goal: Need to find the longest common prefix among all the string in the arrays
 * If there is no common prefix return ""
 *
 * Intuition:
 * All the string in the array doesnt have the same length and since we need to find the common prefix
 * so actually we just need to compare the shortest & the logest string
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        std::string ans;
        std::sort(strs.begin(), strs.end());

        int shortest_len(strs[0].length()), longest_len(strs[strs.size() - 1].length());
        int min_len{std::min(shortest_len, longest_len)};

        for (int i{}; i < min_len; i++)
        {
            if (strs[0][i] != strs[strs.size() - 1][i])
                break;
            ans += strs[0][i];
        }
        return ans;
    }
};
