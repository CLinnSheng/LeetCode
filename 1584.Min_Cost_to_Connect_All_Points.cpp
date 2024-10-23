#include <cstdlib>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Find the cheapest cost to make all points connected
 * Intuition: This is can be solved by Minimum Spannign Tree
 * We will just have to pick the least weight edges for connecting each edges
 * since we dont have the weight of connecting 2 nodes, we have to compute for
 * every single edges and then use minHeap for picking the minimum edges.
 *
 * Time Complexity: O(V^2) because the maximum number of edges is V(V - 1) / 2
 * Space Complexity: O(V) minHeap is bounded by the number of vertices
 * */

struct comparator {
  bool operator()(const std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.first > b.first;
  }
};

class Solution {
public:
  int minCostConnectPoints(std::vector<std::vector<int>> &points) {

    auto n_points{points.size()};
    std::unordered_map<int, std::vector<std::pair<int, int>>> adjList;

    for (int i{}; i < n_points; i++) {
      int x1{points[i][0]};
      int y1{points[i][1]};

      for (int j{i + 1}; j < n_points; j++) {
        int x2{points[j][0]};
        int y2{points[j][1]};

        int weight = std::abs(x1 - x2) + std::abs(y1 - y2);
        adjList[i].emplace_back(weight, j);
        adjList[j].emplace_back(weight, i);
      }
    }

    int res{};
    // To make sure no cycle in the graph
    std::unordered_set<int> visited;
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comparator>
        minHeap;

    minHeap.emplace(0, 0);
    while (!minHeap.empty()) {
      auto [weight, currNode] = minHeap.top();
      minHeap.pop();

      if (visited.count(currNode))
        continue;

      visited.insert(currNode);
      res += weight;

      for (const auto &neighs : adjList[currNode])
        if (!visited.count(neighs.second))
          minHeap.emplace(neighs.first, neighs.second);
    }
    return std::move(res);
  }
};
