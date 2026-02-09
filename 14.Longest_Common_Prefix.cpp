#include <algorithm>
#include <string>
#include <vector>

/*
 * Goal: Need to find the longest common prefix among all the string in the arrays
 * If there is no common prefix return ""
 *
 * Intuition:
 * All the string in the array doesnt have the same length and since we need to find the common prefix
 * If we observe the maximum length of common prefix is actually the shortest length in the strs array
 * So what we need to compare is just the longest str and shortest str

 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    std::string longestCommonPrefix(std::vector<std::string> &strs)
    {
        if (strs.size() == 1)
            return strs[0];

        int n(strs.size());

        std::sort(strs.begin(), strs.end());
        std::string prefix{};

        for (int i{}; i < strs[0].length(); i++)
            if (strs[0][i] != strs[n - 1][i])
                break;
            else
                prefix += strs[0][i];

        return prefix;
    }
};
