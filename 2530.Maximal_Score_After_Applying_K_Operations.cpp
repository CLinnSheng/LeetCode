#include <cmath>
#include <functional>
#include <queue>
#include <vector>

/*
 * Operation:
 * 1. Choose an index i such that 0 <= i <= nums.length
 * 2. increase your score by nums[i]
 * 3. replace nums[i] with ceil(nums[i] / 3)
 *
 * Goal: Return the maximum possible score you can attain after applying exactly
 * k operations.
 *
 * Intuition: We need to choose which index or value to undergoes the operation
 * and the chosen value must able to produce the maximum possible score So
 * everytime we only choose the highest element in the array, so that after the
 * operation it will produce the biggest possible score as if you choose any
 * value lower than the maximum the score definitely lesser than 1 that maximum
 * value undergoes operation We will be using maxHeap, so that every time we can
 * pop the largest element in the array in logn
 *
 * Time Complexity: O(klgn)
 * Space Complexity: O(n)
 *
 * */
class Solution {
public:
  long long maxKelements(std::vector<int> &nums, int k) {
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap(
        nums.begin(), nums.end());

    long long ans{};

    while (k > 0) {
      auto currMax = maxHeap.top();
      maxHeap.pop();
      ans += currMax;
      maxHeap.emplace(std::ceil(currMax / 3.0));
      k--;
    }
    return ans;
  }
};
