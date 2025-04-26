#include <algorithm>
#include <vector>
using ll = long long;

/*
 * Goal: Find the number of subarray that with lowest element equal to minK and largest element equal to maxK
 *
 * Intuition:
 * The brute force way will just simply be double looping the nums array.
 *
 * From the brute force appraoch, we observe that we are checking overlapping subarray.
 * And another key observation is find a subarray that fullfill a condition.
 * This lead me to think about using sliding window.
 * Eg: 3,4,2,4,3,5 where minK = 2 & maxK = 5
 * subarray: [3,4,2,4,3,5] & [4,2,4,3,5] & [2,4,3,5]
 * We can observe that range that included in all subarray is from [2,5].
 * This lead me to think about maybe we need to find the index where both maxK and minK is statisfy first.
 * Then the number of subarray that included the range will just simply be the min(maxKIndex, minKIndex) -
 * lastInvalidIndex to prevent included any previous index that out of the range.
 * Time Complexity: O(N)
 * */
class Solution
{
  public:
    ll countSubarrays(std::vector<int> &nums, int minK, int maxK)
    {
        ll minIndex{-1}, maxIndex{-1}, lastInvalidIndex{-1};
        ll cnt{};

        for (int i{}; i < nums.size(); i++)
        {
            // finding the invalid index
            if (nums[i] < minK || nums[i] > maxK)
                lastInvalidIndex = i;

            if (nums[i] == minK)
                minIndex = i;
            if (nums[i] == maxK)
                maxIndex = i;

            // prevent negative number
            cnt += std::max(0LL, std::min(minIndex, maxIndex) - lastInvalidIndex);
        }
        return cnt;
    }
};
