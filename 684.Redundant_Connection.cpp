/*
Goal: Return a edge that can be removed so that the resulting graph is a tree
Note: Tree has no cycles.
Constraint: Return the occurs last in the input

Intuition: Use UnionFind Algorithm to connect the nodes and check whether theres
a cycle or not Time Complexity: O(n + n) [1 n is for the initialization of the
array of parents & the other n is iterate through n edges and also involve
findParent(this is constant time complexity due to the path compression)] Space
Complexity: O(n)
*/
#include <functional>
#include <vector>

class Solution {
public:
  std::vector<int>
  findRedundantConnection(std::vector<std::vector<int>> &edges) {

    std::vector<int> parents(edges.size() + 1);

    std::function<int(const int &)> findParent = [&](const int &x) {
      if (parents[x] != x)
        parents[x] = findParent(parents[parents[x]]);

      return parents[x];
    };

    for (int i = 0; i <= edges.size(); i++)
      parents[i] = i;

    for (const auto &edge : edges) {
      int parent1{findParent(edge[0])};
      int parent2{findParent(edge[1])};

      if (parent1 == parent2)
        return std::vector<int>{edge[0], edge[1]};
      else
        parents[parent1] = parent2;
    }

    return {};
  }
};
