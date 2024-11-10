#include <climits>
#include <functional>
#include <vector>

/*
 * Given an array nums and an integer k
 * An array is special if bitwise OR of all its element is at least K.
 * Goal: Get the shortest lenght of subarray or return -1 if no special subarray
 *
 * Intuition: Finding subarray is either we can use dp or sliding window
 * Since we will be using bitwise OR & finding the number at least k, so if curr
 * number is x then we OR with any number will produce number equal or greater
 * than x From this observation, come up with solution of sliding window. When
 * ever we found the special array we just move the left pointer, since we just
 * want to find minimum, so no point on keep moving the right pointer. Only move
 * the right pointer, if still not yet reach at least k. Since int is 4 bytes so
 * at maximum we will have 32bits
 * Time Complexity: O(32 * n) -> O(32)
 * Space Complexity: O(32) -> O(1)
 * */
class Solution {
public:
  int minimumSubarrayLength(std::vector<int> &nums, int k) {
    int ans{INT_MAX};
    int left_window{}, right_window{};
    int size(nums.size());
    std::vector<int> bits(32, 0);

    if (size == 1 && nums[0] >= k)
      return 1;

    std::function<void(const int &, int)> updateBits = [&](const int &action,
                                                           int currNumber) {
      for (int i{}; i < 32; i++)
        if ((currNumber >> i) & 1)
          bits[i] += action;
    };

    std::function<int()> convertBitToNum = [&]() {
      int val{};
      for (int i{}; i < 32; i++)
        if (bits[i])
          val |= 1 << i;
      return std::move(val);
    };

    while (right_window < size) {
      updateBits(1, nums[right_window]);

      while (left_window <= right_window && convertBitToNum() >= k) {
        ans = std::min(ans, right_window - left_window + 1);
        updateBits(-1, nums[left_window++]);
      }
      right_window++;
    }

    return ans == INT_MAX ? -1 : ans;
  }
};
