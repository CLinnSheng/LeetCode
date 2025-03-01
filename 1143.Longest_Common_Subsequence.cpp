#include <string>
#include <vector>
using std::string;

/*
 * Goal: Return the longest common subsequence
 *
 * Intuition:
 * First thought is this a decision tree problem because at each index i can choose to include it or not
 * So this lead me to think of i can solve it by using dp?
 * Yes, dp[i][j] stands for text1[0-i] & text2[0-j] longest common subsequence
 * So when text1[i] == text2[j] we just need to take the previous index longest common subsequence and add by 1
 * If they are not equal, we need to choose whether we want to skip the current character of text1 or text2
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int len1(text1.length()), len2(text2.length());
        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));

        for (int i{1}; i <= len1; i++)
            for (int j{1}; j <= len2; j++)
            {
                // equal character then we just take the previous index longest common subsequence and add 1 to it
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    // not equal then we need to decide whether to skip this character of text 1 or text 2
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }

        return dp[len1][len2];
    }
};
