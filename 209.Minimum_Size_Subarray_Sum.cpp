#include <algorithm>
#include <climits>
#include <vector>

/*
 * Given an array of "positive" integers nums and a positive integer target
 *
 * Goal: Return the minimal length of a subarray whose sum is greater than or equal to the target
 *
 * Subarray: Contiguous non empty
 * Intuition:
 * First the array only consists of positive integer
 * Subarray --> dp / sliding window
 * In this question, will be more likely is sliding window because we finding the sum of a subarray
 * So how do we maintain the window? We will be keep moving the right pointer until >= the target
 * once it reach, then we will move the left pointer again until it is less than the target
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int minSubArrayLen(int target, std::vector<int> &nums)
    {
        int left{}, right{};
        int currSum{};
        int len{INT_MAX};

        while (right < nums.size())
        {
            currSum += nums[right];

            while (left <= right && currSum >= target)
            {
                len = std::min(len, right - left + 1);
                currSum -= nums[left++];
            }

            right++;
        }
        return len == INT_MAX ? 0 : len;
    }
};
