#include <vector>

/*
 * Operation: CHoose any 3 consecutive and flip all of them
 * Goal: Return the minimum number of operations to make all elements equal to 1 or else -1
 *
 * Intuition:
 * By naive approach, we can just scan through the array and flip it when we encounter a 0 element
 * This is more a greedy appraoch, we just flip whenever we face a 0
 * So all elements except the last 2 might not be 0
 * Time Complexity: O(n)
 * */

class Solution
{
  public:
    int minOperations(std::vector<int> &nums)
    {
        int cnt{};

        for (int i{}; i < nums.size() - 2; i++)
            if (!nums[i])
            {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                cnt++;
            }
        return (nums[nums.size() - 1] == nums[nums.size() - 2] && nums[nums.size() - 1]) ? cnt : -1;
    }
};
