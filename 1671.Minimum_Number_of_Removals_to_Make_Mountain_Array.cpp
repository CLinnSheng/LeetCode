#include <algorithm>
#include <climits>
#include <vector>

/*
 * An array is a mountain array if and only if:
 * -length >= 3
 * -arr[0] < arr[1] < ... < arr[i]
 *  -arr[i] > aarr[i + 1] > arr[i + 2] > ... > arr[length - 1]
 *
 *  Goal: Return the minimum number of elements to remove to make nums a
 * mountian array.
 *
 *  Intuition:
 *  Try to solve it using brute force first and then find way to optimize it.
 *  First, we toj test every single index as the peak and then find the number
 * of elements need to remove for the left & right This will cost O(n^3)
 *  Actually we can see it has overlapping subproblem when finding the number of
 * elmeents to remove from either side. For example at index [2] how can i
 * arraange it inorder to have increasing order. So this can be optimize it by
 * using d have 2 dp 1 dimensional array LIS & LDS.
 * with this algorithm it reduce the time complexity to O(n^2) which is the time
 * to compute the dynamic programming
 * */
class Solution {
public:
  int minimumMountainRemovals(std::vector<int> &nums) {

    int n = nums.size();
    std::vector<int> LIS(n, 1);
    std::vector<int> LDS(n, 1);

    for (int i{}; i < n; i++)
      for (int j{}; j < i; j++) {
        if (nums[j] < nums[i])
          LIS[i] = std::max(LIS[i], LIS[j] + 1);
      }

    for (int i{n - 1}; i >= 0; i--)
      for (int j{i}; j < n; j++) {
        if (nums[j] < nums[i])
          LDS[i] = std::max(LDS[i], LDS[j] + 1);
      }

    int ans{n};

    for (int i{1}; i < n; i++) {
      if (LIS[i] == 1 || LDS[i] == 1)
        continue;
      else
        ans = std::min(ans, n - LDS[i] - LIS[i] + 1);
    }

    return std::move(ans);
  }
};
