#include <climits>
#include <functional>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>

/*
 * Goal: Find the minimum time where all the nodes receive signal
 * Intuition: We can use dijkstra algorithm and try to use every single node as
 * the starting source node. And then check whether the size of set
 * datastructure is equivalent to the nubmer of nodes exists in the graph
 * Time Complexity: O(ElgV) because at worst we will have V^2 of edges and it
 * each operation takes logV^2 which can be reduce to logV and the at worst we
 * do the operation E times. Space Compleixty: O(V + E)
 * */

struct comparator {
  bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    return a.first > b.first;
  }
};

class Solution {
public:
  int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        comparator>
        minHeap;

    std::vector<std::vector<std::pair<int, int>>> adjList(
        n, std::vector<std::pair<int, int>>());

    // building the adjList
    for (const auto &time : times)
      adjList[time[0] - 1].emplace_back(std::make_pair(time[1] - 1, time[2]));

    int minTime{};
    std::unordered_set<int> visited;

    minHeap.emplace(std::make_pair(0, k - 1));

    while (!minHeap.empty()) {
      auto [currWeight, currNode] = minHeap.top();
      minHeap.pop();

      if (visited.count(currNode))
        continue;

      visited.insert(currNode);
      minTime = currWeight;

      for (const auto &[neighNode, neighWeight] : adjList[currNode])
        if (!visited.count(neighNode))
          minHeap.emplace(std::make_pair(neighWeight + currWeight, neighNode));
    }
    return visited.size() == n ? minTime : -1;
  }
};
