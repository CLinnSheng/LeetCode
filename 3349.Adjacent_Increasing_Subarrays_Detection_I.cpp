#include <algorithm>
#include <vector>
/*
 * Goal: Check whether are there 2 adjacent subarray of size k that are increasing
 * Intuition:
 * There are 2 type of subarray which are the right 1.
 * One is subarray of size >= 2*k
 * Another 1 is 2 subarray of size >= k. for instance 1 2 3 1 2 3
 * So we have to keep track of the longest subarray we can form and the prev size of subarray
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool hasIncreasingSubarrays(std::vector<int> &nums, int k)
    {
        int prevSize{0}, currSize{1};
        for (int i{1}; i < nums.size() && std::max(currSize / 2, std::min(prevSize, currSize)) < k; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                currSize++;
            }
            else
            {
                prevSize = currSize;
                currSize = 1;
            }
        }
        return std::max(currSize / 2, std::min(prevSize, currSize)) >= k;
    }
};
