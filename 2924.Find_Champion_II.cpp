#include <vector>

/*
 * A directed edge from a to b in the graph means that team a is stronger than
team b and team b is weaker than team a.

Team a will be the champion of the tournament if there is no team b that is
stronger than team a.

Return the team that will be the champion of the tournament if there is a unique
champion, otherwise, return -1.

Intuition:
Find all the number of incident on every single edges. Then choose the vertices
that has 0 incident edges. If exists more than 2 or more vertices then return -1
Time Complexity: O(n)
Space Complexity: O(n)
*/
class Solution {
public:
  int findChampion(int n, std::vector<std::vector<int>> &edges) {
    // an array to store the number of incident edges on every single vertex
    std::vector<int> vertices(n, 0);

    for (const auto &edge : edges)
      vertices[edge[1]]++;

    int cnt{}, ans{};

    for (int i{}; i < n; i++)
      if (vertices[i] == 0) {
        cnt++;
        if (cnt > 1)
          return -1;

        ans = i;
      }

    return ans;
  }
};
