#include <queue>
#include <utility>
#include <vector>
using ll = long long;

/*
 * Given an array of positive integers
 * Score starting with 0
 * Opeartion:
 * 1. Choose the smallest integer of the array that is not marked. If there is a
 * tie choose the one with the smallest tie
 * 2. Add the value of the chosen to the score
 * 3. Mark the chosen element and its two adjacent element if they existed
 * 3. Repeat until all the array elemetns are marked.
 *
 * Goal: Return the score after applying the above algorithm
 *
 * Intuition:
 * Can use a heap data structure because we need to choose the smallest integer
 * that is not marked. The heap will store the value and also the index And then
 * another array data structure keep track of the marked index
 *
 * Time Compleixty: O(nlgn)
 * Space Complexity: O(n)
 * */

struct comparator {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    // compare value by default
    // if same only compare index
    if (a.first != b.first)
      return a.first > b.first;

    // Comparing the index
    return a.second > b.second;
  }
};

class Solution {
public:
  ll findScore(std::vector<int> &nums) {
    ll ans{};

    int size(nums.size());
    if (size == 1)
      return nums[0];

    std::vector<bool> marked(size, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comparator>
        minHeap;

    for (int i{}; i < size; i++)
      minHeap.emplace(std::make_pair(nums[i], i));

    while (!minHeap.empty()) {
      auto &[val, index] = minHeap.top();
      minHeap.pop();

      if (marked[index])
        continue;

      ans += val;

      // marked the index
      marked[index] = true;
      if (index - 1 >= 0)
        marked[index - 1] = true;
      if (index + 1 < size)
        marked[index + 1] = true;
    }
    return ans;
  }
};
