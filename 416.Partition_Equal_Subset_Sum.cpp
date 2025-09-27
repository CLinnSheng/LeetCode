#include <numeric>
#include <vector>

/*
 * Goal: Return true if you can partition the array into 2 subset such that the sum in both subsets s equal or false
 * otherwise
 *
 * Intuition:
 * Find "subset" immediately know is a tree decision problem. So at every index we can either choose or not choose.
 * And also another key observation is the 2 subset sum is equal so basically is the total sum divide by 2. If the total
 * sum is odd means cannot be partitioned equally
 * So by using brute force, we will just simply use dfs and at each point we can either include or not include, so when
 * the sum is equal to half of the ttlSum, that means we can form a subset as those not included also can make it sum.
 * But the time complexity will be O(2^n)
 *
 * we can optimize it by using caching. But how do we implement it?
 * Just cache the result, so whenever we face the same problem can straight away use it
 * So 2d or 1d? Based on the brute force dfs, so everytime we pass down the index and target so basically we need 2d
 * array Time Complexity: O(n * sum(nums)) Space Complexity: O(n * sum(nums)) --> MLE
 */
class Solution
{
  private:
    bool dfs(const int index, const std::vector<int> &nums, const int target, std::vector<std::vector<int>> &caching)
    {
        if (index == nums.size())
            return target == 0;

        if (target < 0)
            return false;

        if (caching[index][target] != -1)
            return caching[index][target];
        // Include Or not Include
        return caching[index][target] =
                   dfs(index + 1, nums, target, caching) || dfs(index + 1, nums, target - nums[index], caching);
    }

  public:
    bool canPartition(std::vector<int> &nums)
    {
        int sum{std::accumulate(nums.begin(), nums.end(), 0)};
        // Base Case
        if (sum % 2)
            return false;

        // Futher optimize
        // Use caching
        std::vector<std::vector<int>> caching(nums.size(), std::vector<int>(sum / 2, -1));
        return dfs(0, nums, sum / 2, caching);
    }
};
