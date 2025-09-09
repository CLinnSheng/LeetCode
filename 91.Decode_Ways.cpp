#include <string>
#include <vector>
/*
 * 'A' -> 1
 * 'B' -> 2
 * 'Z' -> 26
 *
 * Goal: Decode the message and return the number of ways to decode it
 *
 * Intuition:
 * At every index we can either choose to decode as a single character or double character
 * eg: 1012 -> 10 12 or 10 1 2
 * So the brute force will just simply recursion.
 * We can optimize it by using caching.
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    int dfs(const std::string &s, const int index, std::vector<int> &caching)
    {
        // Base Case
        if (index == s.length())
            return 1;

        // No zero leading
        if (s[index] == '0')
            return 0;

        if (caching[index] != -1)
            return caching[index];
        // Only one character
        int cnt{dfs(s, index + 1, caching)};

        // Then check whether can do 2 character or not
        if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
            cnt += dfs(s, index + 2, caching);

        return caching[index] = cnt;
    }

  public:
    int numDecodings(std::string s)
    {
        // Improve by caching
        // caching[i] = number ways to decode at ith position to end of string
        std::vector<int> caching(s.length(), -1);
        return dfs(s, 0, caching);

        // Bottom up approach
        // std::vector<int> dp(s.length() + 1);
        // dp[s.length()] = 1;
        //
        // for (int index(s.length() - 1); index >= 0; index--)
        // {
        //      if (s[index] == '0')
        //          dp[index] = 0;
        //      else
        //      {
        //          dp[index] = dp[index + 1];
        //          // Check for can make it 2 characters or not
        // if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] < '7')))
        //          {
        //              dp[index] = dp[index + 2];
        //          }
        //      }
        // }
        // return dp[0];
    }
};
