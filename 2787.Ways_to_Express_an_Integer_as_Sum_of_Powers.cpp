/*
 * Goal: REturn the number of ways n can be expressed as the sum of the xth power of unique integers or in another words
 * the nubmer of set of unqiue integers [n1, n2, ..., nk] where n = n1x + n2x + ... + nkx
 *
 * Intuition:
 * This is actually a little bit similar to k-snapsack problem, where we need to determine the number of ways to form a
 * specific number with the available number we have SO dp[i][j] --> where simply be the number of sets of unique
 * integers to get j from 1 to i
 * */
#include <cmath>
#include <vector>
class Solution
{
  public:
    int numberOfWays(int n, int x)
    {
        std::vector<std::vector<long long>> dp(n + 1, std::vector<long long>(n + 1, 0));
        const long long MOD = 1e9 + 7;
        dp[0][0] = 1;

        for (int i{1}; i <= n; i++)
        {
            long long val = std::pow(i, x);
            for (int j{}; j <= n; j++)
            {
                // It should be at least the same as i - 1 elements
                dp[i][j] = dp[i - 1][j];
                if (val <= j)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - val]) % MOD;
            }
        }
        return dp[n][n];
    }
};
