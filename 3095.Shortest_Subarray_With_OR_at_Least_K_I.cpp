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
 * Constraint: The elements come be a negative number, so we can solve this by
 * having a prefix and we use prioty queue to store the prefix Time Complexity:
 * O(nlgn) because of push & pop operation of heap Space Complexity: O(n)
 * Actually there is a more clever way, since we want to remove the prefix sum
 * that is the longest & with minSum
 * By using minHeap, it will automatically help us to get the min how about we
 * manually do it ourself we can use a monotomic increasing stack
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */

using ll = long long;

// struct comparator {
//   bool operator()(std::pair<ll, int> &a, std::pair<ll, int> &b) {
//     return a.first > b.first;
//   }
// };
class Solution {
public:
  int shortestSubarray(std::vector<int> &nums, int k) {
    int ans{INT_MAX};
    ll currSum{};

    int right{};

    // std::priority_queue<std::pair<ll, int>, std::vector<std::pair<ll, int>>,
    //                     comparator>
    //     minHeap;
    //
    // while (right < nums.size()) {
    //   currSum += nums[right];
    //
    //   // dealing with base case only 1 elements & nt revmoing any prefix
    //   if (currSum >= k)
    //     ans = std::min(ans, right + 1);
    //
    //   while (!minHeap.empty() && currSum - minHeap.top().first >= k) {
    //     ans = std::min(ans, right - minHeap.top().second);
    //     minHeap.pop();
    //   }
    //
    //   minHeap.emplace(currSum, right++);
    // }
    std::deque<std::pair<ll, int>> stack;

    while (right < nums.size()) {
      currSum += nums[right];

      if (currSum >= k)
        ans = std::min(ans, right + 1);

      // finding the minimum valid window
      while (!stack.empty() && currSum - stack.front().first >= k) {
        ans = std::min(ans, right - stack.front().second);
        stack.pop_front();
      }

      // making sure is a monotomic stack
      while (!stack.empty() && stack.back().first >= currSum)
        stack.pop_back();

      stack.emplace_back(currSum, right++);
    }
    return ans == INT_MAX ? -1 : ans;
  }
};
