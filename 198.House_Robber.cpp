/*
Given an array of nums where nums[i] has a certain amount of money.
We need to return the maximum amount of money we can get from the array

Constraint: We cannot visit adjacent Houses were broken on the same night
eg: 1 2 3 4
if we first broke index 1 then we cannot broke into index 2, we can only choose
either 3 or 4 for the next 1

Intuition: Try to maximize the amount of val from an array but with constraint,
this will lead us to think that this is a dp problem We can either use bottom up
or top down approach

Time Complexity: O(n) because we just go through the array
Space Complexity: O(n)
*/
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>
class Solution {
public:
  int rob(std::vector<int> &nums) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // Bottom-up appraoch
    if (nums.size() == 0)
      return 0;
    if (nums.size() == 1)
      return nums[0];

    // Determining the second house
    nums[1] = std::max(nums[0], nums[1]);

    for (int i = 2; i < nums.size(); i++)
      // Now we have to make use of dp, decide whether whether on this index
      // visit it + previously 2 days or just visiting this house
      nums[i] = std::max(nums[i - 1], nums[i - 2] + nums[i]);

    return nums[nums.size() - 1];
  }
};

/*
 * Top Down approach
 * int rob(std::vector<int> &nums) {
 *
 *  std::ios_base::sync_with_stdio(false);
 *  std::cin.tie(nullptr);
 *  std::cout.tie(nullptr);
 *
 *  std::vector<int> dp(nums.size() - 1, -1);
 *
 *  std::function<int(int)> helper = [&](int index) {
 *
 *    Reaching index 0 & we dont have any extra element that can compare, so
 * just return if (index == 0) return nums[0]; if (index < -1) return 0; if
 * (dp[index] != -1) return dp[index];
 *
 *    dp[index] = std::max(helper(index - 1), helper(index - 2) + nums[index]);
 *
 *    return dp[index];
 *  }
 *
 *  From the back because this is a top down approach
 *  return helper(nums.size() - 1);
 * }
 */
