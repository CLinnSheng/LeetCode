#include <vector>
/*
 * Goal: Find the number of possible combinations that add up to the target
 *
 * Intuition:
 * Same element can be use more than once, so this is a tree decision problem at every index we can either invovle it or
 * not.
 * So we can just dfs and check whether it reach the target. We return 1 if reach otherwise 0 if exceed the target.
 * We can use caching to reduce the time complexity.
 * Time Complexity: O(n * T)
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &nums, const int target, int currSum, std::vector<int> &caching)
    {
        if (currSum == target)
            return 1;
        if (currSum > target)
            return 0;

        if (caching[currSum] != -1)
            return caching[currSum];

        int res = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            currSum += nums[i];
            res += dfs(nums, target, currSum, caching);
            currSum -= nums[i];
        }
        return caching[currSum] = res;
    }

  public:
    int combinationSum4(std::vector<int> &nums, int target)
    {
        std::vector<int> caching(target + 1, -1);
        return dfs(nums, target, 0, caching);
    }
};
