#include <functional>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using std::vector;

/*
 * times[i] = (ui, vi, ti)
 * ui - source source node
 * vi - target node
 * ti - time taken for a signal travel from source to target node
 *
 * Goal: Return the minimum time it takes for all of the n nodes to receive the signal otherwise return 0 if impossible
 *
 * Intuition:
 * Question asking for the "minimum time" to reach and is also a graph problem.
 * First intuition is use  dijkstra algorithm
 * Time Complexity: O(ElgE)
 * */
class Solution
{
  public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k)
    {
        // Build adjList
        vector<vector<std::pair<int, int>>> adjList(n, vector<std::pair<int, int>>());
        for (const auto &time : times)
            adjList[time[0] - 1].emplace_back(time[1] - 1, time[2]);

        // Visited set to prevent cycle
        std::unordered_set<int> visited;

        std::priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            minHeap;
        minHeap.emplace(0, k - 1);

        int answer{};

        while (!minHeap.empty())
        {
            auto [currWeight, currNode]{minHeap.top()};
            minHeap.pop();

            if (visited.count(currNode))
                continue;

            // Put over here because the last node we visit will change this value
            answer = currWeight;
            visited.insert(currNode);

            for (const auto &[neighNode, neighWeight] : adjList[currNode])
                if (!visited.count(neighNode))
                    minHeap.emplace(neighWeight + currWeight, neighNode);
        }

        return visited.size() == n ? answer : -1;
    }
};
