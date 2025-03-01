#include <algorithm>
#include <string>
#include <vector>
using std::string;

/*
 * Goal: Return the shortest string that has both str1 & str2 as subsequences.
 * Supersequence: Let t as the supersequence. S is a subsequence of t if deleting some some number of characters from t
 *
 * Intuition:
 * This is actually a decision tree problem where at each index for str1 & str2 we choose whether we want to include it
 * into the sequecne or not So when str1[i] == str[j], means that we need to include the index. However when they are
 * not equal, how do we know which 1 to inlcude? By brute force we will try 2 different ways and get the shorter 1. We
 * can optimize it by using DP
 *
 * But actually can we use the information we have from the longest common subsequence use?
 * Yes, we can because dp[i][j] gives the informatoin of the longest common subsequence for str1 & str2
 * Whenever str1[i] != str2[j] we will consider the 1 with longer common subsequence, because we are needing to create
 * the shorter common supersequnce. Complexity: O(m*n)
 * */
class Solution
{
  public:
    string shortestCommonSupersequence(string str1, string str2)
    {
        string answer{};
        int len1(str1.length()), len2(str2.length());

        std::vector<std::vector<int>> dp(len1 + 1, std::vector<int>(len2 + 1, 0));
        for (int i{1}; i <= len1; i++)
            for (int j{1}; j <= len2; j++)
            {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
            }

        int i{len1}, j{len2};
        while (i > 0 && j > 0)
        {
            // both are equals
            if (str1[i - 1] == str2[j - 1])
            {
                answer += str1[i - 1];
                i--;
                j--;
            }
            else if (dp[i - 1][j] > dp[i][j - 1])
            {
                answer += str1[i - 1];
                i--;
            }
            else
            {
                answer += str2[j - 1];
                j--;
            }
        }

        // make sure it include all characters from str1 and str2
        while (i > 0)
            answer += str1[i-- - 1];

        while (j > 0)
            answer += str2[j-- - 1];

        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
