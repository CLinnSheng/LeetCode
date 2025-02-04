#include <algorithm>
#include <vector>

/*
 * Goal: Find the maximum possible sum of an ascending subarray in nums.
 *
 * Intuition:
 * Since we are finding a subarray & in a particular order
 * therefor, we can use sliding window.
 * Keep moving the right pointer whenever it is still in ascending order and keep updating the maximum sum.
 * Move the left pointer to the right when it is out of order
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int maxAscendingSum(std::vector<int> &nums)
    {
        int n(nums.size());
        if (n == 1)
            return nums[0];

        int left{}, right{1};
        int currSum{nums[left]}, answer{nums[left]};

        while (left < right && left < n && right < n)
        {
            // Out of order (not in ascending anymore)
            if (nums[right - 1] >= nums[right])
            {
                // move the left pointer
                left = right;
                currSum = nums[left];
            }
            else
            {
                currSum += nums[right];
            }

            right++;
            answer = std::max(answer, currSum);
        }
        return answer;
    }
};
