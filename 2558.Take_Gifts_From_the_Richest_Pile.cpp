#include <cmath>
#include <queue>
#include <vector>
using ll = long long;

/*
 * Given an integer array gifts denoting the number of gifts in each piles
 * Every second we can choose the pile with the maximum number of gifts & leave
 * behind thr square root of the number of gifts in the pile. If there is more
 * than one pile with the maximum number of gifts choose any
 *
 * Goal: Return the number of gifts remaining after k seconds
 *
 * Intuition:
 * Since every seconds we need to the take gifts with the pile that has the most
 * gifts We dont have any constraint on choosing the pile & we only need to
 * choose the 1 with most gifts So we can use a heap to track the pile with the
 * most gifts
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  ll pickGifts(std::vector<int> &gifts, int k) {
    ll ans{};

    std::priority_queue<int, std::vector<int>> maxHeap(gifts.begin(),
                                                       gifts.end());

    while (k) {
      auto gift = maxHeap.top();
      maxHeap.pop();
      gift = std::sqrt(gift);
      maxHeap.emplace(gift);
      k--;
    }

    while (!maxHeap.empty()) {
      auto top = maxHeap.top();
      maxHeap.pop();
      ans += top;
    }

    return ans;
  }
};
