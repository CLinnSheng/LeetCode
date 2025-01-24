#include <algorithm>
#include <vector>

/*
 * Goal: Find the contiguous subarray with an array (at least contain one element) which has the largest product
 * nums[i] can be negative / positive
 *
 * Intuition:
 * The brute force way will just simply loop through every single index to find all the possible subarray.
 * This will have a triple loop O(n^3)
 *
 * We can optimze this to O(N^2)
 * by having a value to store all the product before the jth product (outer loop is ith and then to jth)
 *
 * Can we further optimize this to maybe linear time or in log
 * since nums[i] can be negative / positive so we need to come out with an algo / solution to deal with
 * negative element. If the array only contain positive element, we need to include as much as possible.
 * In the other hand, we try to minimize the number of negative elmeent in our subarray but this is not always the case
 * because a negative element * negative element --> positive element. How do we deal with this
 * eg: [-1, -2, -3]
 * -1 -> 2 -> -6 (traverse from the left)
 *  but the maximum we can find here is -2 * -3 -> 6, how can we get this??
 *  we can solve this problem by keeping track by the min and max element at every index ith, so that when we encounter
 * nums[i] which is a negative element when it times with negative element it will become positive which is much greater
 * than max * nums[i]
 * Time Complexity: O(n)
 *
 * Another approach is actually by using prefix & suffix because both go in different direction
 * because we can try out more diff possibilities.
 * NOTE: IS BETTER TO INCLUDE MORE ELEMENTS
 * */
class Solution
{
  public:
    int maxProduct(std::vector<int> &nums)
    {
        int maxProduct{}, n(nums.size());
        if (n == 1)
            return nums[0];

        // int prefix{}, suffix{};
        //
        // for (int i{}; i < n; i++)
        // {
        //     prefix = nums[i] * (prefix == 0 ? 1 : prefix);
        //     suffix = nums[n - i - 1] * (suffix == 0 ? 1 : suffix);
        //
        //     maxProduct = std::max(maxProduct, std::max(prefix, suffix));
        // }

        // approach 2
        int curMin{1}, curMax{1};
        for (int i{}; i < n; i++)
        {
            int temp{curMax * nums[i]};
            curMax = std::max(nums[i] * curMin, std::max(curMax * nums[i], nums[i]));
            curMin = std::min(temp, std::min(curMin * nums[i], nums[i]));

            maxProduct = std::max(curMax, maxProduct);
        }
        return maxProduct;
    }
};
