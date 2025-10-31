#include <numeric>
#include <vector>
/*
 * Goal: find the number of ways to assign coins to get a total of target
 *
 * Intuition:
 * This is a tree decision at every index we can choose to either add or minus
 * So the brute force way will just simply use recursive to solve this problem
 * Time Complexity: O(2^N)
 *
 * Actually if we observe from the brute force, we can see we actually doing some repetition computation
 * We can use cache to optimize it which reduce it to O(n^2)
 * 2 information is passed to the recursive function so the array will be 2d
 * */
class Solution
{
  private:
    int ttlSum;
    int dfs(std::vector<int> &nums, int target, int index, int currSum, std::vector<std::vector<int>> &cache)
    {
        if (index == nums.size())
        {
            return target == currSum;
        }

        // ttlSum + currSum instead of currSum to avoid negative number
        if (cache[index][ttlSum + currSum] != -1)
        {
            return cache[index][ttlSum + currSum];
        }

        return cache[index][ttlSum + currSum] = dfs(nums, target, index + 1, currSum + nums[index], cache) +
                                                dfs(nums, target, index + 1, currSum - nums[index], cache);
    }

  public:
    int findTargetSumWays(std::vector<int> &nums, int target)
    {
        ttlSum = std::accumulate(nums.begin(), nums.end(), 0);
        std::vector<std::vector<int>> cache(nums.size() + 1, std::vector<int>(ttlSum * 2 + 1, -1));
        return dfs(nums, target, 0, 0, cache);
    }
};
