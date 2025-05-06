/*
 * Given 2 types of tiles.
 * i. 2 * 1 domino shape
 * ii. Tromino shape
 *
 * Can rotate these tiles
 * Given an integer n
 *
 * Goal: Return the number of ways to tile an 2 * n board.
 *
 * Intuition:
 * The first thought come in mind is this might be a dp problem.
 * Because we can break it into smaller problem, for example if we want to solve 2 * 5
 * we can use information from 2 * 4
 *
 * n = 1, 1
 * n = 2, 2
 * n = 3, 5 (3 also made up of 2 n = 2)
 * n = 4, we can actually see is made up of 2 possible combination of  n = 3, where the first 1 is the first 3 col and
 * the seoncd 1 is the lsat 3 col.
 * Actually more exact is by col, where f(n) is the number of ways for n column
 * Through derivation in the end we get this formula dp[n] = dp[n - 1] * 2 + dp[n - 3];
 * Time Complexity: O(n)
 * */
#include <vector>
class Solution
{
  private:
    const int MOD = 1e9 + 7;

  public:
    int numTilings(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        std::vector<int> dp(n + 1);
        dp[0] = 1, dp[1] = 1, dp[2] = 2, dp[3] = 5;
        for (int i{4}; i <= n; i++)
            dp[i] = (dp[i - 1] * 2 + dp[i - 3]) % MOD;

        return dp[n];
    }
};
