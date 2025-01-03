#include <vector>

/*
 * Goal: Return the number of valid splits
 * Valid Splits:
 * i. Sum of the first i + 1 element is greater than or equal to the sum of the last n - i - i elements
 * ii. There is at least one element to the right of i.
 *
 * Intuition:
 * The naive approach way is just having double inner loop by comparing the sum from the left and from the right
 * The time complexity will be O(n^2)
 *
 * How we can optimize this?
 * Are we able to make the comparing of sum in O(1)?
 * Yes we can make it if we knew the sum at the right hand side straight away
 * We can done this by preprocessing the sum of the right at every ith position
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 *
 * */
class Solution
{
  public:
    int waysToSplitArray(std::vector<int> &nums)
    {
        int ans;
        int n(nums.size());
        std::vector<long long> prefixSum(n);
        prefixSum[0] = nums[0];

        // precompute the prefixSum
        for (int i{1}; i < n; i++)
            prefixSum[i] = prefixSum[i - 1] + nums[i];

        for (int i{}; i < n; i++)
        {
            long long rightSum{prefixSum[n - 1] - prefixSum[i]};
            if (prefixSum[i] >= rightSum)
                ans++;
        }
        return ans;
    }
};
