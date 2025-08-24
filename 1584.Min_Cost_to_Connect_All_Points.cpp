#include <cstdlib>
#include <functional>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * points[i] = [xi, yi]
 * Cost of connecting 2 points is |xi - xj| + |yi - yj|
 * Goal: Find the minimum cost connecting all the points
 *
 * Intuition:
 * We can treat every single point as a node.
 * Then the weight will just simply be the cost
 * Then we can apply prims algorithm to connect the dots.
 * Time Complexity: O(E^2 + E^2lgV)
 * */
class Solution
{
  public:
    int minCostConnectPoints(std::vector<std::vector<int>> &points)
    {
        int n(points.size());

        // building the adjList
        // O(E^2)
        std::vector<std::vector<std::pair<int, int>>> adjList(n, std::vector<std::pair<int, int>>());
        for (int i{}; i < n; i++)
        {
            int x1{points[i][0]}, y1{points[i][1]};

            for (int j{}; j < n; j++)
            {
                if (i == j)
                    continue;

                int x2{points[j][0]}, y2{points[j][1]};
                int weight{std::abs(x1 - x2) + std::abs(y1 - y2)};

                adjList[i].emplace_back(j, weight);
                adjList[j].emplace_back(i, weight);
            }
        }

        int answer{};
        std::unordered_set<int> visited;
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
            minHeap;
        minHeap.emplace(0, 0);

        // O(E^2 lg V)
        while (!minHeap.empty())
        {
            auto [currCost, currNode]{minHeap.top()};
            minHeap.pop();

            if (visited.count(currNode))
                continue;

            visited.insert(currNode);
            answer += currCost;

            for (const auto &[neighNode, neighCost] : adjList[currNode])
                if (!visited.count(neighNode))
                    minHeap.emplace(neighCost, neighNode);
        }
        return answer;
    }
};
