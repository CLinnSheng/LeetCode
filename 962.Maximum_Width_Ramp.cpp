#include <algorithm>
#include <vector>

/*
 * A ramp is an integer array nums in pair (i, j) for which i < j and nums[i] <=
 * nums[j]. The wdith of ramp is j - i Goal: Return the maximum width of a ramp
 * in nums.
 *
 * Intuition:
 * 1. We can solve it buy using naive approach through double loop iterate
 * through the array. This is very costly which is O(n^2)
 * 2. We need to try the optimize it to be lesser than n^2. On top of that, we
 * kinda trying to find the maximum subarray. So this led us to thinking of
 * using an algorithm which is sliding window. At the first thought on how to
 * moving the window is when nums[i] < nums[j] then we move the left pointer but
 * this doesnt always pass because thinking of there might be a number that is
 * equal or greater than the element the left pointer pointed to and which has
 * the maximum length of subarray So, I come up with a solution on how to move
 * the pointer. We initialize an array to indicate the maximum value on the
 * right hand side of the current index. So that when we comapre nums[i] and
 * nums[j] we can know that how far can we move the right pointer.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * */
class Solution {
public:
  int maxWidthRamp(std::vector<int> &nums) {
    int maxWidth = 0;

    int n = nums.size();
    std::vector<int> maxValueRight(n, 0);
    maxValueRight[n - 1] = nums[n - 1];

    for (int i = n - 2; i >= 0; i--)
      maxValueRight[i] = std::max(maxValueRight[i + 1], nums[i]);

    int left = 0, right = 0;
    while (right < n) {
      if (nums[left] <= maxValueRight[right]) {
        if (nums[left] <= nums[right])
          maxWidth = std::max(maxWidth, right - left);
        right++;
      } else
        left++;
    }

    return std::move(maxWidth);
  }
};
