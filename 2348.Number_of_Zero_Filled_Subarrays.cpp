#include <algorithm>
#include <vector>

/*
 * Goal: Return the number of subarrays filled with 0.
 * Subarray: Contiguous non empty space
 *
 * Intuition:
 * An element itself also consider a subarray.
 * First base case we will check whether is 0 exists in the array or not
 * The first thing can be just inlcude all 0 length of 1 subarray
 *
 * For subarray more than one we can simply just use sliding window.
 * so we will try to expand as right as possible then the number of subarray of 0 for will just simply be sum the
 * current length for every index
 *
 * Time Complexity: O(n)
 *
 * */
class Solution
{
  public:
    long long zeroFilledSubarray(std::vector<int> &nums)
    {
        if (std::find(nums.begin(), nums.end(), 0) == nums.end())
            return {};

        long long ans{};

        for (int i{}; i < nums.size(); i++)
        {
            int left{i};
            while (i < nums.size() && nums[i] == 0)
            {
                ans += i - left + 1;
                i++;
            }
        }
        return ans;
    }
};
