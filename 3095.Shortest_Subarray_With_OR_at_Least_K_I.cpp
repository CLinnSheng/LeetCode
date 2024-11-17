#include <functional>
#include <vector>

/*
 * Goal: Return the length of the shortest spcial non empty subarray of nums or
 * return -1 if no special subarray exists Special Array: If the bitwise OR of
 * all of its element is at least k.
 *
 * Intuition: when we OR a number the result will gonna be at least equal or
 * greater than the maximum element in the subarray. So we can use a sliding
 * window when it reach equal or greater than k then we try to move the left
 * window to find the minimum length
 *
 * Time Complexity: O(32 * n)
 * Space Complexity: O(1)
 * */
class Solution {
public:
  int minimumSubarrayLength(std::vector<int> &nums, int k) {
    int ans{INT_MAX};
    std::vector<int> bits(32, 0);

    int currSum{};

    std::function<void(const int &, int)> updateBits = [&](const int &action,
                                                           int val) {
      for (int i{}; i < 32; i++)
        if ((val >> i) & 1)
          bits[i] += action;
    };

    std::function<int()> checkValue = [&]() {
      int sum{};
      for (int i{}; i < 32; i++)
        if (bits[i])
          sum |= 1 << i;
      return sum;
    };

    int left{}, right{};
    while (right < nums.size()) {
      updateBits(1, nums[right]);

      // moving the left ptr if already get at least k
      while (left <= right && checkValue() >= k) {
        ans = std::min(ans, right - left + 1);
        // moving the left ptr
        updateBits(-1, nums[left++]);
      }

      right++;
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
