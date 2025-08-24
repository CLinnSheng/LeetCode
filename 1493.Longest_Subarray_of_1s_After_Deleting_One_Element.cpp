#include <algorithm>
#include <vector>
/*
 * Given a binary array, delete one element from it
 * Goal: Return the size of the longest non-empty subarray containing only 1's otherwise return 0
 *
 * Intuition:
 * We can use a sliding window algorithm where we always make sure there is only one 0 inside
 * otherwise move the left pointer
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int longestSubarray(std::vector<int> &nums)
    {
        // Base Case
        if (std::find(nums.begin(), nums.end(), 1) == nums.end())
            return 0;

        int left{}, right{};
        int answer{};
        bool containZero{false};

        while (right < nums.size())
        {
            if (nums[right] == 0)
            {
                // If dont have zero, then include it
                if (containZero == false)
                    containZero = !containZero;
                else
                {
                    // Move to the left pointer until it doesnt include the old zero
                    while (nums[left] != 0)
                        left++;

                    left++;
                }
            }
            answer = std::max(answer, right - left + 1);
            right++;
        }

        // Must remove one element no matter what
        return answer - 1;
    }
};
