#include <climits>
#include <vector>

/*
 * Given an integer array coins
 * Goal: Return the fewest number of coins that you need to make up that amount.
 *
 * Intuition: At amount we will try different number of coin first, and then
 * keep going down using naive approach will be O(2^n) Actually we can see
 * theres a lot of overlapping problem for example if we already have the answer
 * for choosing 'x' amount, we dont have to recompute, just use the existing
 * solution This leads us to dp. Since the number of coins is infinite, we only
 * need 1D array
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(m)
 * */
class Solution
{
  public:
    int coinChange(std::vector<int> &coins, int amount)
    {
        std::vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;

        // bottom up approach
        for (int i{1}; i <= amount; i++)
            // try every single coin, to see which 1 is the minimum
            for (const auto &coin : coins)
                if (i >= coin && dp[i - coin] != INT_MAX)
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);

        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
};
