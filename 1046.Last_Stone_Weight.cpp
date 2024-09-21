/*
 * Given: Array of integers stones where stones[i] is the weight of the ith
 * stones Each turn we choose the heaviest 2 stones and smash them tgt. suppose
 * 2 stone weights x & y where x <= y 2 possibilites:
 * 1. x == y, both stones are destroyed
 * ii/ x != y, x is destroyed & y has new weight of y - x
 * At the end, at most 1 stone left
 * Goal: Return the weight of the last remianing stone else return 0 if no stone
 * left
 *
 * Intuition: We always choose the heaveist 2 stone therefore we need a data
 * structure that is easy to pick the 2 heaviest and need to put back into the
 * basket Ans is by using a maxHeap where the top is the heaveist
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 *
 * */
#include <cstdlib>
#include <ios>
#include <queue>
class Solution {
public:
  int lastStoneWeight(vector<int> &stones) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::priority_queue<int, std::vector<int>> maxHeap;

    for (const auto &stone : stones)
      maxHeap.emplace(stone);

    while (maxHeap.size() > 1) {

      // Take out the 2 heaviest stone
      auto stone1 = maxHeap.top();
      maxHeap.pop();
      auto stone2 = maxHeap.top();
      maxHeap.pop();

      if (stone1 == stone2)
        continue;
      else
        maxHeap.emplace(std::abs(stone1 - stone2));
    }

    return maxHeap.empty() ? 0 : maxHeap.top();
  }
};
