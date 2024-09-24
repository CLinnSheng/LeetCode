#include <functional>
#include <ios>
#include <iostream>
#include <queue>
#include <vector>

/*
 * Goal: return the kth largest element in the arrray
 * Constraint: Solve it without sorting
 *
 * Intuition: Since we cannot sort the array, what we gonna do is put the
 * elements into a minHeap, when ever the heap size greater than k we pop it
 * Time Complexity: O(nlgk)
 * Space Complexity: O(k)
 * */

class Solution {
public:
  int findKthLargest(std::vector<int> &nums, int k) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;

    for (const auto &num : nums) {
      if (minHeap.size() > k)
        minHeap.pop();
      minHeap.emplace(num);
    }
    if (minHeap.size() > k)
      minHeap.pop();
    return minHeap.top();
  }
};
