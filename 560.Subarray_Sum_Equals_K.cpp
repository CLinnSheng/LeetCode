#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: Return the total number of subarrays whose sum equals to k.
 * Subarray: Contiguous non-empty sequence of elements within an array.
 *
 * Intuition:
 * We can solve it naively by using double inner loop but this will have a time complexity of O(n^2)
 * How can we optimize it?
 * This first thought will be using sliding window but this doesnt work for negative number
 * becuase we will keep moving the right pointer until the cumulative sum is greater than k then
 * we will move the left pointer. But this doesnt work for negative element.
 *
 * From the dry run by using naive approach, we can actually see we have been computing the same subproblem.
 * We can skip all these repetive subproblem by storing it in a hash so we can access it in O(1).
 * for example when i = 3, then we will check the cumulative sum from i = 0 to 3 and minus it with k see whether we have
 * this subaray of  sum - k Time Complexity: O(n) Space Complexity: O(1)
 * */
class Solution
{
  public:
    int subarraySum(vector<int> &nums, int k)
    {
        int ans{};
        // key: SUM, value: count
        std::unordered_map<int, int> prefixSum;
        // theres only one way to have subarray sum of 0
        prefixSum[0] = 1;

        int currSum{};
        for (const auto &num : nums)
        {
            currSum += num;
            if (prefixSum.count(currSum - k))
                ans++;

            prefixSum[currSum]++;
        }
        return ans;
    }
};
