#include <deque>
#include <functional>
#include <unordered_set>
#include <vector>
/*
 * Return an array answer where for each i in the range [0, queries.length - 1],
 * answer[i] is the length of the shortest path from city 0 to city n - 1 after
 * processing the first i + 1 queries.
 *
 * Intuition: Since this is a graph problem, we can use dfs/bfs
 * at here we choose bfs(personal preferneces and a bit more efficient)
 * we just need to check every time a new edge is added into the graph
 *
 * Time Complexity: O(m*(n + m)) the number of nodes we traverse is upper
 * bounded by the maximum number of edges + number of nodes Space Complexity:
 * O(m)
 * */
class Solution {
public:
  std::vector<int>
  shortestDistanceAfterQueries(int n, std::vector<std::vector<int>> &queries) {
    std::vector<int> ans;

    // build the adjList
    std::vector<std::vector<int>> adjList(n, std::vector<int>());

    for (int i{}; i < n - 1; i++)
      adjList[i].emplace_back(i + 1);

    std::function<int()> helper = [&]() {
      std::unordered_set<int> visited;
      std::deque<std::pair<int, int>> queue;

      queue.emplace_back(0, 0);

      while (!queue.empty()) {
        auto [currNode, currDistance] = queue.front();
        queue.pop_front();

        if (currNode == n - 1)
          return currDistance;

        for (const auto &nextNode : adjList[currNode])
          if (!visited.count(nextNode)) {
            queue.emplace_back(nextNode, currDistance + 1);
            visited.insert(nextNode);
          }
      }
    };

    for (const auto &query : queries) {
      adjList[query[0]].emplace_back(query[1]);
      ans.emplace_back(helper());
    }

    return ans;
  }
};
