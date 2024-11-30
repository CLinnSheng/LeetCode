#include <algorithm>
#include <climits>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return an arrangement of pairs is valid if for every inedx where 1 <= i
 * < pairs.length, we have endi-1 == start Eg: pairs =
 * [[5,1],[4,5],[11,9],[9,4]] return: [[11,9],[9,4],[4,5],[5,1]]
 *
 * Intuition:
 * This is actually a graph problem as we can see the every pairs of the return
 * array is linked together treat the number as nodes and the pair as an edge,
 * and then we need to find a path where it can go back to it original position
 * and also follow the rule
 *
 * This is actually an euler path or it can be euler circuit also
 * every edge must be visited once and it can be same or not same ending vertex
 *
 * Time Complexity: O(V + E)
 * Time Complexity: O(n)
 * */
class Solution {
public:
  std::vector<std::vector<int>>
  validArrangement(std::vector<std::vector<int>> &pairs) {
    std::vector<std::vector<int>> ans;
    std::unordered_map<int, std::vector<int>> adjList;
    std::unordered_map<int, int> inDegree, outDegree;

    // Build graph and count degrees
    // O(n)
    for (const auto &pair : pairs) {
      adjList[pair[0]].push_back(pair[1]);
      outDegree[pair[0]]++;
      inDegree[pair[1]]++;
    }

    // Find starting node
    // O(n)
    int startingNode = pairs[0][0];
    for (const auto &node : adjList)
      if (outDegree[node.first] == inDegree[node.first] + 1) {
        startingNode = node.first;
        break;
      }

    // O(V + E) traverse every single edges and vertices
    std::function<void(const int &)> findEulerPath = [&](const int &currNode) {
      while (!adjList[currNode].empty()) {
        int nextNode = adjList[currNode].back();
        adjList[currNode].pop_back();
        findEulerPath(nextNode);
        ans.push_back({currNode, nextNode});
      }
    };

    findEulerPath(startingNode);

    // Reverse the node in the array
    // O(N)
    std::reverse(ans.begin(), ans.end());

    return ans;
  }
};
