#include <algorithm>
#include <climits>
#include <vector>

/*
 * Each node has at mose one outging edges
 * edges[i] = 1 has outgoing and edges[i] = -1 has no outgoing edge
 *
 * Goal: Return index of the node that can be reached bot node1 and node2, such that the maximum between the distance
 * from node1 to the node and from node2 to the node is minimized. If multipole naswer, return the node with the
 * smallest index otherwise return -1 if impossible
 *
 * Intuition:
 * this is a graph problem. Since every node at max has only one outgoing edge, so dfs will be better and we dont have
 * to start at every node. Just start at node1 and node2. We need to find the node such that the maximum(node1 to node,
 * node2 to node) is the minimum.
 * Time Complexity: O(n) Travelling all the edges
 * Space Complexity: O(n) Recursive call stack
 * */
class Solution
{
  private:
    void dfs(std::vector<int> &path, const std::vector<int> &edges, const int &currNode)
    {
        int nxtNode{edges[currNode]};

        if (nxtNode != -1 && path[nxtNode] == INT_MAX)
        {
            path[nxtNode] = 1 + path[currNode];
            dfs(path, edges, nxtNode);
        }
    }

  public:
    int closestMeetingNode(std::vector<int> &edges, int node1, int node2)
    {
        // use this to keep track the distance and also can use for checking got cycle or not
        int n(edges.size());
        std::vector<int> path1(n, INT_MAX), path2(n, INT_MAX);
        path1[node1] = path2[node2] = 0;

        dfs(path1, edges, node1);
        dfs(path2, edges, node2);

        int ansNode{-1}, minDist{INT_MAX};
        for (int i{}; i < n; i++)
            if (minDist > std::max(path1[i], path2[i]))
            {
                ansNode = i;
                minDist = std::max(path1[i], path2[i]);
            }
        return ansNode;
    }
};
