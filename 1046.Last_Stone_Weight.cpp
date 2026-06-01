/*
 * Each step choose the 2 heaviest stone --> Giving hint on using a heap to easily access heaviest stones
 * */
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
class Solution
{
    std::priority_queue<int, std::vector<int>, std::less<int>> maxHeap;

  public:
    int lastStoneWeight(std::vector<int> &stones)
    {
        // Populate the heap
        for (const auto &stone : stones)
        {
            maxHeap.push(stone);
        }

        // Run the simulation
        while (maxHeap.size() > 1)
        {
            // First Stone
            int firstStone = maxHeap.top();
            maxHeap.pop();

            // Second Stone
            int secondStone = maxHeap.top();
            maxHeap.pop();

            if (firstStone == secondStone)
            {
                continue;
            }
            else
            {
                maxHeap.push(std::abs(firstStone - secondStone));
            }
        }

        return maxHeap.empty() ? 0 : maxHeap.top();
    }
};
