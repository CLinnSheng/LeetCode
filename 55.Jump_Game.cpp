#include <vector>

/*
 * Given an integer array nums. Each element in the array represents your
 * maximum jump length at that position
 * Goal: Return true if able to reach the last index
 *
 * Intuition:
 * 1. Naive approach by keep trying from [1, nums[i]] and each index
 * 2. Second way is more clever since we want to know are we able to reach the
 * final index or not why note we just straight away start from final index - 1,
 * check from final index - 1 are we able to reach the last index (keep
 * updating) This will reduce the time complexity to O(n) Space complexity: O(1)
 * */
class Solution
{
  public:
    bool canJump(std::vector<int> &nums)
    {
        int goal(nums.size() - 1);

        for (int index(nums.size() - 2); index >= 0; index--)
            // Check whether the current index + nums[i] can reach the previous index or not
            if (index + nums[index] >= goal)
                goal = index;

        // Check whether can we reach index 0
        return goal == 0;
    }
};
