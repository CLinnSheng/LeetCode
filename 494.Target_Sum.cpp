#include <functional>
#include <unordered_map>
#include <vector>

/*
 * Build an expression out of nums by adding of the symbols '+' & '-' before each integer in nums and then concatenate
 * all the integers Goal: Return the number of different expression that you can build, which evaluates to target
 *
 *
 * Intuition:
 * The brute force way is by using dfs & backtracking to try every single possible combinations
 * Time Complexity: O(2^n)
 * Space Complexity: O(n)
 *
 * We can optimize this by using dynamic programming instead of using recursion method
 * We will be using a 2d array for memoziation and thus the time complexity is reduced to O(m*n)
 * Space Complexity: O(m*n)
 * the dp[i][j] means that the number of ways to get sum of j value and with i number of element from nums
 * */
class Solution
{
  public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        if (nums.size() == 1 & nums[0] == target)
            return 1;

        // dfs
        // std::function<int(const int &, const int &)> dfs = [&](const int &sum, const int &index) {
        //     if (index == nums.size())
        //         return target == sum ? 1 : 0;
        //     return dfs(sum + nums[index], index + 1) + dfs(sum - nums[index], index + 1);
        // };
        //
        // return dfs(0, 0);

        int n(nums.size());
        std::vector<std::unordered_map<int, int>> dp(n + 1);
        dp[0][0] = 1;

        for (int i{}; i < nums.size(); i++)
            // Iterate through all the possible sum from all the elements before ith element
            for (const auto &sum : dp[i])
            {
                // 2 diff ways which is + & -
                dp[i + 1][sum.first + nums[i]] += sum.second;
                dp[i + 1][sum.first - nums[i]] += sum.second;
            }
        return dp[n][target];
    }
};
