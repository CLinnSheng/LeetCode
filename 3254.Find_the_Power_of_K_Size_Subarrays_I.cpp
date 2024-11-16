#include <deque>
#include <vector>

/*
 * Given an array of integer nums of length n & a postiive integer k.
 * The power of an array is defined as:
 *  -Maximum element if alll of its elements are consecutive and sorted in
 * ascending order.
 *  --1 otherwise
 *
 * Goal: Return an array of results of size n - k + 1
 *
 * Intuition:
 * The most simplest way is just brute force it by loop through the array nums
 * and then an inner loop of k times to check whether is it in ascending order &
 * consecutive Time Complexity: O(n*k) Space Complexity: O(n - k + 1)
 *
 * Since we are checking an equal range of subarray throughout the array, we can
 * actually use sliding window. we can use a deque data structure to store the
 * current window elements. Time Complexity: O(n) Space Complexity: O(n)
 * */
class Solution {
public:
  std::vector<int> resultsArray(std::vector<int> &nums, int k) {
    std::vector<int> ans;
    std::deque<int> window;

    for (int i{}; i < nums.size(); i++) {
      // check the current window size
      if (!window.empty() && i - k + 1 > window.front())
        window.pop_front();

      // check whether is it in ascending order
      if (!window.empty() && nums[i - 1] != nums[i] - 1)
        window.clear();

      window.emplace_back(i);

      // only start checking if the index already equal or exceed the size
      if (i >= k - 1)
        ans.emplace_back(window.size() == k ? nums[window.back()] : -1);
    }
    return ans;
  }
};
