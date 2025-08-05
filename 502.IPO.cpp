#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * Can only finish at most 'k' distinct projects before the IPO
 * profits[i] -> pure profit of ith project
 * capital[i] -> minimum capital to start it
 * Initially have w capital
 *
 * Goal: Design the best way to maximize its total capital after finishing at most 'k' distinct projects
 *
 * Intuition:
 * We initially has 'w' capital, so we actually can have 2 heaps that store the project with minCapital & project with
 * maxProfit. So we will first push whatever project that are within our capital to the project we can do, then only pop
 * the maximum profit project from the heap.
 * */
class Solution
{
  public:
    int findMaximizedCapital(int k, int w, std::vector<int> &profits, std::vector<int> &capital)
    {
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            minHeapCapital;
        std::priority_queue<int, std::vector<int>, std::less<int>> maxHeapProfit;

        for (int i{}; i < capital.size(); i++)
            minHeapCapital.emplace(capital[i], profits[i]);

        // Up to K project
        for (int i{}; i < k; i++)
        {
            // First check which project we have enough capital to start
            // push it into the heap of project we can start
            while (!minHeapCapital.empty() && minHeapCapital.top().first <= w)
            {
                maxHeapProfit.emplace(minHeapCapital.top().second);
                minHeapCapital.pop();
            }

            // Base Case no project
            if (maxHeapProfit.empty())
                break;

            // Then take the maximum project from the heap
            w += maxHeapProfit.top();
            maxHeapProfit.pop();
        }
        return w;
    }
};
