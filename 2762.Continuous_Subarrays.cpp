#include <algorithm>
#include <climits>
#include <cstdlib>
#include <vector>
using ll = long long;

/*
 * Given an integer array. A subarray of nums is called continuous if:
 * Constraint:
 * Let i, i + 1, ..., j, be the indices in the subarray. Then for each pair of
 * indices i <= i1, i2 <= j 0 <= | nums[i1] - nums[i2] | <= 2
 *
 * Goal: Return the total number of continuous array
 *
 * Intuitoin:
 * We can use brute force with double looping
 * But this is very costly
 *
 * We can optimize this by using a sliding window because it trying to find a
 * subarray We will be keep moving the right pointer of the window and the left
 * pointer whenever it the subarray didnt meet the constraint Theres a clever
 * way to check whether the subarray meet the constraint or not by checking the
 * difference of the maximum value and the minimum value in the subarray is <= 2
 * or not
 *
 * Formula of finding the number of subarray of size n is n*(n + 1) / 2
 * */
class Solution {
public:
  ll continuousSubarrays(std::vector<int> &nums) {

    int size(nums.size());
    if (size == 1)
      return 1;

    ll ans{}, windowSize{};
    int left{}, right{};
    int maxVal{INT_MIN}, minVal{INT_MAX};

    for (; right < size; right++) {
      maxVal = std::max(maxVal, nums[right]);
      minVal = std::min(minVal, nums[right]);

      // Check constraint
      if (maxVal - minVal > 2) {
        windowSize = right - left;

        ans += (windowSize * (windowSize + 1)) / 2;

        // move the left pointer
        left = right;

        // Expand the current window to the left as much as possible
        maxVal = minVal = nums[right];
        while (std::abs(nums[right] - nums[left - 1]) <= 2) {
          left--;
          maxVal = std::max(maxVal, nums[left]);
          minVal = std::min(minVal, nums[left]);
        }

        // Subtract overcount subarray
        if (left < right) {
          windowSize = right - left;
          ans -= (windowSize * (windowSize + 1)) / 2;
        }
      }
    }

    windowSize = right - left;
    ans += (windowSize * (windowSize + 1)) / 2;

    return ans;
  }
};
