#include <algorithm>
#include <vector>

/*
 * Derived from the House Robber Question
 * Constraint: The housese are in a circle that means the first house and the
 * last house is connected So we cannot visit the first and last house So now
 * our choice is limited either we visit choose from n[1] to n[n - 1] or from
 * n[2] to n[n]
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  private:
    int helper(const std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        dp[1] = std::max(nums[0],
                         nums[1]); // Because we might skip the third house, so is better to rob 2nd house if larger

        for (int i{2}; i < nums.size(); i++)
            dp[i] = std::max(dp[i - 1], nums[i] + dp[i - 2]);

        return dp[nums.size() - 1];
    }

  public:
    int rob(std::vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];

        // 1st Approach
        // Recursive --> Caching
        // 2nd Appraoch
        // Bottom Up
        return std::max(helper(std::vector<int>(nums.begin(), nums.end() - 1)),
                        helper(std::vector<int>(nums.begin() + 1, nums.end())));
    }
};
