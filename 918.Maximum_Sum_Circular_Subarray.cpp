#include <algorithm>
#include <vector>
/*
 * Circular integer array
 * Goal: Return the maximum possible sum of a non-empty subarray
 *
 * Intuition:
 * This is quite similar to Maximum sum subarray problem but this 1 is in circular
 * How do we deal with it such that the maximum sum is included both the end and the front?
 * Ok think about how we do it without circular. Through Kadene algo we will keep a globalMax and a currMax/currSum
 * value.
 * But how do we deal with circular? We can actually also keep a currMin & globalMin. So the total can either globalMax
 * or TotalSum - globalMin (which is the subarray constitute to the minSum)
 Time Complexity: O(n)
 * */
class Solution
{
  public:
    int maxSubarraySumCircular(std::vector<int> &nums)
    {
        int globalMax{nums[0]}, globalMin{nums[0]};
        int currMax{}, currMin{}, ttl{};

        for (const auto num : nums)
        {
            ttl += num;

            currMax = std::max(num, currMax + num);
            globalMax = std::max(globalMax, currMax);

            currMin = std::min(num, currMin + num);
            globalMin = std::min(globalMin, currMin);
        }

        // Deal with edge cases where all number is positive
        return globalMax > 0 ? std::max(globalMax, ttl - globalMin) : globalMax;
    }
};
