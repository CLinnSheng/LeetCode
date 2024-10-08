#include <functional>
#include <vector>

/*
 * Goal: Check whether is it a valid Tree or not
 * Valid Tree: Connected & has no cycle/loop
 *
 * Intuition: Can use UnionFind algorithm to connect and check cycle
 * Time Complexity: O(m*n) where m is the number of edges and n is the operation
 * on each edges which is include finding the Parent and union. (Finding the
 * path contribute the time compleixty which is n in worst case) Space
 * Complexity: O(n)
 * */
class Solution {
public:
  bool validTree(int n, std::vector<std::vector<int>> &edges) {

    std::vector<int> parents(n);
    for (int i = 0; i < n; i++)
      parents[i] = i;

    std::function<int(const int)> findParent = [&](const int x) {
      if (parents[x] != x)
        parents[x] = findParent(parents[x]);

      return parents[x];
    };

    for (const auto &edge : edges) {
      int edge1{edge[0]};
      int edge2{edge[1]};

      // From the same root that means will form a cycle
      if (findParent(edge1) == findParent(edge2))
        return false;

      // Union/Connect the 2 set together
      parents[findParent(edge1)] = findParent(edge2);

      // after connect thats mean the number of node left will decrease by 1
      n--;
    }

    // if we successfully connect all without forming cycle will be only left 1
    // set with all the connected components. If got more than 1 set means the
    // tree is not valid
    return n == 1;
  }
};
