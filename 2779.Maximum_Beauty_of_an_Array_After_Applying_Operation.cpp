#include <algorithm>
#include <vector>

/*
 * Goal: Return the maximum possible 'beauty' of the array after applying the
 * operation any number of times Beauty: Length of the longest sbusequence
 * consisting of equal elements where subsequence means that an array is a new
 * array generated from the original array by deleting some elements or none
 * without changing the order of the remaining elements eg: [4,4,1,4] -> [4,4,4]
 *
 * Operation:
 * Choose an index i that hasn't been chosen before
 * replace nums[i] with any integer from the range [nums[i] - k, nums[i] + k]
 *
 * Intuition:
 * Theres an edge case where the orignal array is already beauty
 * Compute the range for every single index & then try from 1 to the largest
 * possible range then another loop through the range This brute force way is
 * O(n^2)
 *
 * The more optimized way is instead of keep checking for every single possilbe
 * number in the range we can actually tell whether the 2 range intercept or not
 * through this equation nums[a] - nums[b] <= k So this greatly reduced the time
 * complexity we can use sliding window to determine the range of numbers that
 * it will intersect
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int maximumBeauty(std::vector<int> &nums, int k) {

    bool beauty{true};
    int n(nums.size());

    // Handle cases where the length is 1
    if (n == 1)
      return n;

    // Handle cases where the original array is beauty
    for (int i{1}; i < n; i++)
      if (nums[i] != nums[i - 1]) {
        beauty = false;
        break;
      }

    if (beauty)
      return n;

    int ans{1};
    // O(nlgn)
    std::sort(nums.begin(), nums.end());
    int left{}, right{};
    // O(n)
    for (; left < n; left++) {
      // Sliding Window
      while (right < n && nums[right] - nums[left] <= 2 * k)
        right++;

      ans = std::max(ans, right - left);
    }

    return ans;
  }
};
