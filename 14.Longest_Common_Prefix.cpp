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
        std::sort(strs.begin(), strs.end());

        int shortestLen(strs[0].length()), longestLen(strs[strs.size() - 1].length());
        int minLen(std::min(shortestLen, longestLen));

        std::string ans{};

        for (int index{}; index < minLen; index++)
            if (strs[0][index] != strs[strs.size() - 1][index])
                break;
            else
                ans += strs[0][index];

        return ans;
    }
};
