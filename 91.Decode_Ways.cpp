#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Message is decoded through the following mapping:
 * 1 -> 'A'
 * ... 26 - > 'Z'
 *
 * While decoding the message, there are many different way to decode it\
 * eg: 121 --> 1 21 or 12 1
 * Goal: Return the number of ways to decode it
 *
 * Intuition:
 * At every index there is 2 ways to decode it is either 1 digit or 2 digit
 *      121
 *      / \
 *     1  12
 *    / \   \
 *  2  21    1
 * /
 *1
 * Therefore by brute force dfs down the string.
 * The time complexity will be O(2^n)
 *
 * We can further optimize this by using dynamic programming
 * because we can see overlapping subproblem
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int numDecodings(std::string s) {
    if (s[0] == '0')
      return 0;
    // top-down approach
    // std::unordered_map<int, int> dp;
    // std::function<int(const int &)> dfs = [&](const int &index) {
    //   // memoziation
    //   if (dp.count(index))
    //     return dp[index];
    //
    //   // base-case
    //   if (index == s.length())
    //     return 1;
    //   // return 0 because cannot start with 0 but can end with 0 for 10 & 20
    //   if (s[index] == '0')
    //     return 0;
    //
    //   // first decision
    //   int res{dfs(index + 1)};
    //   if (index + 1 < s.length() &&
    //       (s[index] == '1' || s[index] == '2' && s[index + 1] < '7'))
    //     res += dfs(index + 2);
    //   dp[index] = res;
    //   return res;
    // };
    // return dfs(0);

    // bottom up approach
    std::vector<int> dp(s.size() + 1);
    dp[s.size()] = 1;

    // same concept with top down approach (2 branch, choosing 1 or 2 digit)
    // and then at every new index it will depends on the preivous 2 or 1
    for (int i(s.size() - 1); i >= 0; i--)
      if (s[i] == '0')
        dp[i] = 0;
      else {
        dp[i] = dp[i + 1];
        if (i + 1 < s.size() && (s[i] == '1' || s[i] == '2' && s[i] < '7'))
          dp[i] += dp[i + 2];
      }
    return dp[0];
  }
};
