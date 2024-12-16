#include <queue>
#include <utility>
#include <vector>

/*
 * Given an array, k & a multiplier
 * Perform k operations on the array.
 * Operation:
 * Find the minimum value x in the array, nums. If there are multiple
 * occurrences of the minimum value, select the one that appears first. Replace
 * the selected minimum value x with x * multiplier
 *
 * Goal: Return an integer array denoting the final state of nums after
 * performing all k operations.
 *
 * Intuition: Since every operation we will be choosing the eleemnt with the
 * least value Then we can use a heap data structure that store this data
 * structure (value, index) because we might face some of the number in the
 * array hold the same value then we need to choose the 1 that come first Time
 * Complexity: O(nlgn) Space Complexity: O(n)
 * */

struct comparator {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.first != b.first)
      return a.first > b.first;
    return a.second > b.second;
  }
};

class Solution {
public:
  std::vector<int> getFinalState(std::vector<int> &nums, int k,
                                 int multiplier) {
    int n(nums.size());

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comparator>
        minHeap;

    for (int i{}; i < n; i++)
      minHeap.emplace(std::make_pair(nums[i], i));

    while (k) {
      auto [val, index] = minHeap.top();
      minHeap.pop();

      val = val * multiplier;
      minHeap.emplace(std::make_pair(val, index));

      k--;
    }

    std::vector<int> ans(n);

    while (!minHeap.empty()) {
      auto [val, index] = minHeap.top();
      minHeap.pop();

      ans[index] = val;
    }
    return std::move(ans);
  }
};
