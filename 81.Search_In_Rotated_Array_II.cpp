#include <vector>
class Solution
{
  public:
    bool search(std::vector<int> &nums, int target)
    {
        // The array is sorted but in a rotated manner
        // Goal: Find whether is it target inside the array
        // How can we make use of the sorted manner but in rotated?
        // Since we know sorted --> Make use of binary search
        // O(lgn)

        int left{}, right(nums.size() - 1);

        // Need to consider the middle element as well
        while (left <= right)
        {
            int middle = left + (right - left) / 2;

            if (nums[middle] == target)
            {
                return true;
            }

            // Edge Case
            // We need to handle duplicate element because when the element compares are same, we cannot confirm
            // that section is it sorted or not
            if (nums[middle] == nums[right])
            {
                right--;
            }
            // Find the part which is sorted, so is either the first half or the second half
            else if (nums[middle] < nums[right])
            {
                // Check is it within the range
                if (nums[middle] <= target && nums[right] >= target)
                {
                    left = middle + 1;
                }
                else
                {
                    right = middle - 1;
                }
            }
            else
            {
                if (nums[left] <= target && nums[middle] >= target)
                {
                    right = middle - 1;
                }
                else
                {
                    left = middle + 1;
                }
            }
        }
        return false;
    }
};
