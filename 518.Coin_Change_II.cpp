#include <algorithm>
#include <functional>
#include <vector>

/*
 * Given an array of coins of different denominiations and an integer amount representing a total amount of money
 * Goal: Return the number of combinations that make up that amount. If that amount of money cannot be make up by any
 * combinations return 0
 *
 * ASSUMPTION: INFIINITE number of each kind of coin
 *
 * Intution:
 * This is actually a decision problem where at every amount we can choose to go with the same coin or try the next coin
 * So we can solve it naively through dfs & backtracking
 * However this will exceed the time limit & we can solve this by using caching or dp
 * so we can skip some of the amount that we already computed
 *
 *
 * */
class Solution
{
  public:
    int change(int amount, std::vector<int> &coins)
    {
        std::sort(coins.begin(), coins.end());
        int n(coins.size());

        // Top-down approach
        // std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, -1));
        // std::function<int(const int &, const int &)> dfs = [&](const int &coin_index, const int &amount) {
        //     if (amount == 0)
        //         return 1;
        //     if (coin_index >= coins.size())
        //         return 0;
        //     if (dp[coin_index][amount] != -1)
        //         return dp[coin_index][amount];
        //
        //     int res{};
        //     // check whether can allocate the current coin or not
        //     if (amount >= coins[coin_index])
        //     {
        //         // Choosing other coin
        //         res = dfs(coin_index + 1, amount);
        //         // Keep adding the same coin
        //         res += dfs(coin_index, amount - coins[coin_index]);
        //     }
        //
        //     dp[coin_index][amount] = res;
        //     return res;
        // };
        // return dfs(0, amount);

        // Bottom-up approach
        // dp[i][j] means for the amount of combination to get j amount while just use until ith coin
        std::vector<std::vector<int>> dp(n + 1, std::vector<int>(amount + 1, 0));
        for (int i{}; i <= n; i++)
            // for amount 0 we only have 1 way to get it
            dp[i][0] = 1;

        for (int i{n - 1}; i >= 0; i--)
            for (int a{}; a <= amount; a++)
                // check whether is enough to allocate the coin or not
                if (a >= coins[i])
                {
                    // using the other coin
                    dp[i][a] = dp[i + 1][a];
                    // using the current coin
                    dp[i][a] += dp[i][a - coins[i]];
                }

        return dp[0][amount];
    }
};
