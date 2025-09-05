/*
Given an array of nums where nums[i] has a certain amount of money.
We need to return the maximum amount of money we can get from the array

Constraint: We cannot visit adjacent Houses were broken on the same night
eg: 1 2 3 4
if we first broke index 1 then we cannot broke into index 2, we can only choose
either 3 or 4 for the next 1

Intuition:
This is actually a tree decision problem, at every index we can choose to rob or not. If we choose to rob then we will
choose again at i + 2 or else we can choose not to and try again at i + 1
Recursion --> Memoziation (topDown) --> DP (bottomUp)

Time Complexity: O(n) because we just go through the array
Space Complexity: O(n)
*/
#include <algorithm>
#include <vector>
class Solution
{
  private:
    int helper(const std::vector<int> &nums, std::vector<int> &dp, int index)
    {
        if (index >= nums.size())
            return 0;

        if (dp[index] != -1)
            return dp[index];

        // Choose or not choose to rob
        dp[index] = std::max(nums[index] + helper(nums, dp, index + 2), helper(nums, dp, index + 1));

        return dp[index];
    }

  public:
    int rob(std::vector<int> &nums)
    {
        int n(nums.size());
        // first approach brute force Recursion
        // then optimize with caching
        // so the information we need to pass down is just the index
        // dp[i] is the maximum amount of money we can get from 0 to ith
        // std::vector<int> dp(n, -1);
        // helper(nums, dp, 0);
        //
        // // return by comparing first and second because we might start from second house
        // return std::max(dp[0], dp[1]);

        // Second Approach bottom up
        if (n == 1)
            return nums[0];
        if (n == 2)
            return std::max(nums[0], nums[1]);

        std::vector<int> dp(n, 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i{2}; i < n; i++)
            dp[i] = std::max(nums[i] + dp[i - 2], dp[i - 1]);

        return dp[n - 1];
    }
};
