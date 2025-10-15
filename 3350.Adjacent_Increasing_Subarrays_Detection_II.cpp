#include <algorithm>
#include <vector>

/*
 * Same as the version I.
 * But the goal now is to find the maximum length of the increasing subarray.
 *
 * Intuition:
 * The approach will be basically the same but this time we will try to find the maximum length unlike
 * previous 1 find until it reach k.
 * Time Complexity: O(n)
 * */
class Solution

{
  public:
    int maxIncreasingSubarrays(std::vector<int> &nums)
    {
        int prevCnt{}, currCnt{1}, ans{};

        for (int i{1}; i < nums.size(); i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currCnt++;
            }
            else
            {
                prevCnt = currCnt;
                currCnt = 1;
            }

            // Account for 2 cases
            // 1. The entire subarray is increasing
            ans = std::max(ans, currCnt / 2);
            // 2. The entire subarray is not increasing then compare with the previous subarray
            ans = std::max(ans, std::min(currCnt, prevCnt));
        }
        return ans;
    }
};
