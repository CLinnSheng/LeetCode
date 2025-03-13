#include <algorithm>
#include <vector>
using std::vector;

/*
 * Given that the nums is in ascending order. 0 is neither positive nor negative
 * Goal: Return the maximum number of pos or neg
 *
 * Intuition:
 * The most easiest way is actually just scan through the array and then have variable to track the number of positive &
 * negative. Time Complexity: O(n)
 *
 * Actually right, given that the array is already sorted. We can actually use binary search.
 * So we need to find the final index or negative number and first positive index
 * Thus with binary search we can done it in O(lgn)
 * */
class Solution
{
  private:
    // finding the first index of greater than 0
    int findFirsPositive(const vector<int> &nums)
    {
        int left{}, right(nums.size() - 1);
        int index(nums.size());

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (nums[middle] > 0)
            {
                right = middle - 1;
                index = middle;
            }
            else
            {
                left = middle + 1;
            }
        }
        return index;
    }

    // finding the first index of 0 or greater than 0
    int findFirstZero(const vector<int> &nums)
    {
        int left{}, right(nums.size() - 1);
        int index(nums.size());

        while (left <= right)
        {
            int middle(left + (right - left) / 2);

            if (nums[middle] >= 0)
            {
                right = middle - 1;
                index = middle;
            }
            else
            {
                left = middle + 1;
            }
        }

        return index;
    }

  public:
    int maximumCount(vector<int> &nums)
    {
        // Approach 1.
        // int pos{}, neg{};
        //
        // for (const auto &num : nums)
        //     if (num > 0)
        //         pos++;
        //     else if (num < 0)
        //         neg++;
        //
        // return std::max(pos, neg);

        // Approach 2.
        // For positive we need to find the first index greater than 0.
        // While negative we need to find the first index which is 0
        int pos = nums.size() - findFirsPositive(nums);
        int neg = findFirstZero(nums);

        return std::max(pos, neg);
    }
};
