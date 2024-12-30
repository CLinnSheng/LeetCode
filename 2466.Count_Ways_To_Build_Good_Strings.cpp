
/*
 * Goal: Return the number of different good strings that can be constructed statisfying these properties.
 *
 * Constraint:
 * 1. Length of the strings bust in between low & high (Inclusive)
 * 2. Can only add '1' or '0' to the strings.
 * 3. Every time add '1' can only add one times and same goes to '0'
 *
 * Intuition:
 * This is actually a decision tree problem where at every stage we can choose to
 * append '0' or '1'
 * Important Observation: The string build up from different branch is distinct
 * So we can just naively use dfs & backtracking to find the number of diff string we can build
 * On top of that, we dont actually need to build the string, we can just check whether is it a valid string through it
 * length However, by brute force the time limit will exceed and thus we can make use of caching or dp to improve the
 * time complexity Another important observation for dp is the number of diff string that can be build from x length is
 * the same so we dont have to compute again Time Complexity: O(high) Space Complexity: O(high)
 * */
#include <cmath>
#include <functional>
#include <unordered_map>
#include <vector>
class Solution
{
  private:
    const int MOD{1000000007};

  public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        // top-down approach

        // // dfs & backtracking function
        // std::function<int(const int &)> dfs_backtracking = [&](const int &length) {
        //     if (length > high)
        //         return 0;
        //
        //     // memoziation
        //     if (dp[length] != -1)
        //         return dp[length];
        //
        //     dp[length] = (length >= low) ? 1 : 0;
        //     // 2 branches: Add '1' or '0'
        //     dp[length] += (dfs_backtracking(length + zero) + dfs_backtracking(length + one)) % MOD;
        //
        //     // caching
        //     return dp[length] % MOD;
        // };
        // return dfs_backtracking(0);

        // bottom-up approach
        // dp[i] means that at length of i how many possible combinations of string is there
        std::unordered_map<int, int> dp;
        dp[0] = 1;

        for (int i{1}; i <= high; i++)
            dp[i] = ((dp.count(i - zero) ? dp[i - zero] : 0) + (dp.count(i - one) ? dp[i - one] : 0)) % MOD;

        int ans{};
        for (int i{low}; i <= high; i++)
            ans = (ans + (dp.count(i) ? dp[i] : 0)) % MOD;
        return ans;
    }
};
