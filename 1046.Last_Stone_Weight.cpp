#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
/*
 * Each turn choose the heaviest two stones and smash them together.
 * 2 result:
 * 1. x == y, both destroyed
 * 2. x != y, store the remaining weight
 *
 * Goal: Return the last stone left or 0
 *
 * Intuition:
 * At every single time we need to get the 2 heaviest stones, so we need to a data structure
 * that can easily access. Max heap will be a good choice
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    int lastStoneWeight(std::vector<int> &stones)
    {
        std::priority_queue<int, std::vector<int>, std::less<int>> max_heap;
        for (int i = 0; i < stones.size(); i++)
        {
            max_heap.push(stones[i]);
        }

        while (!max_heap.empty() && max_heap.size() > 1)
        {
            int x = max_heap.top();
            max_heap.pop();
            int y = max_heap.top();
            max_heap.pop();

            // 2 possibilities
            if (x != y)
            {
                int diff = std::abs(x - y);
                max_heap.push(diff);
            }
        }
        return max_heap.empty() ? 0 : max_heap.top();
    }
};
