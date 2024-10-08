/*
Goal: Find the number of connected components in an undirected graphs
Intuition: Use UnionFind algorithm to connect and check whether got cycle or not
Time Complexity: O(n + E) [The time complexity of the root is O(a(n)) is almost
constant because of path compression O(1)] Space Complexity: O(n)
*/
#include <vector>

class Solution {
public:
  /**
   * @param n: the number of vertices
   * @param edges: the edges of undirected graph
   * @return: the number of connected components
   */

  int countComponents(int n, std::vector<std::vector<int>> &edges) {

    ranks.resize(n);
    parents.resize(n);

    for (int i = 0; i < n; i++) {
      ranks[i] = i;
      parents[i] = 1;
    }

    int n_nodes{n};

    for (const auto &edge : edges)
      n_nodes -= UnionFind(edge[0], edge[1]);
    return n_nodes;
  }

private:
  std::vector<int> ranks;
  std::vector<int> parents;
  int UnionFind(const int &node1, const int &node2) {
    int p1 = findParent(node1);
    int p2 = findParent(node2);

    // if same root dont connect
    if (p1 == p2)
      return 0;

    if (ranks[p1] > ranks[p2]) {
      parents[p2] = p1;
      ranks[p1] += ranks[p2];
    } else {
      parents[p1] = p2;
      ranks[p2] += ranks[p1];
    }
    return 1;
  }

  int findParent(const int &node) {
    if (parents[node] != node)
      parents[node] = findParent(parents[parents[node]]);
    return parents[node];
  }
};
