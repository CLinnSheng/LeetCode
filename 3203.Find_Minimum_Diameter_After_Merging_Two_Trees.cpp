#include <cmath>
#include <utility>
#include <vector>

/*
 * Given 2 2d array of edges and we need to connect one node from the first tree with another node from the second tree
 * with an edge Goal: Return the minimum possible diameter of the resulting tree Diameter of a tree: Length of the
 * longest path between any 2 nodes in the tree
 *
 * Intuition: We need to find the shortest path of a node to a center node in both tree and then add 1 to it
 * that will be the minimum possible diameter of the resulting tree.
 * There a few possible ways of how the 2 nodes will be, it might from the same tree or in different tree
 * so we will compare the maximum diameter from each tree and then also on the resulting tree.
 * the formula for finding the diameter from a tree if the 2 node from sperate tree ceil(diameter / 2)
 *
 * Time Complexity: O(m + n) go through every single nodes
 * Space Complexity: O(m + n)
 * */
class Solution
{
  private:
    void buildAdjList(std::vector<std::vector<int>> &adjList, const std::vector<std::vector<int>> &edges)
    {
        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
    }

    // Bottom up approach
    std::pair<int, int> findDiameter_DFS(const int &currNode, const int &parentNode,
                                         const std::vector<std::vector<int>> &adjList)
    {
        int maxDiameter{};
        // Var to keep track the depth of its child
        int depth1{}, depth2{};

        for (const auto &neigh : adjList[currNode])
        {
            if (neigh == parentNode)
                continue;

            // every single child will return the maximum diameter at its current position and also the maximum path to
            // the child node
            auto [neigh_D, depth] = findDiameter_DFS(neigh, currNode, adjList);
            maxDiameter = std::max(maxDiameter, neigh_D);

            // To include this node
            depth++;
            if (depth > depth1)
            {
                depth2 = depth1;
                depth1 = depth;
            }
            else if (depth > depth2)
                depth2 = depth;
        }
        maxDiameter = std::max(maxDiameter, depth1 + depth2);
        return {maxDiameter, depth1};
    }

  public:
    int minimumDiameterAfterMerge(std::vector<std::vector<int>> &edges1, std::vector<std::vector<int>> &edges2)
    {
        int s1(edges1.size() + 1), s2(edges2.size() + 1);
        std::vector<std::vector<int>> adjList1(s1, std::vector<int>()), adjList2(s2, std::vector<int>());

        buildAdjList(adjList1, edges1);
        buildAdjList(adjList2, edges2);

        auto tree1{findDiameter_DFS(0, -1, adjList1)};
        auto tree2{findDiameter_DFS(0, -1, adjList2)};
        int combineTree(std::ceil(tree1.first / 2.0) + std::ceil(tree2.first / 2.0) + 1);

        return std::max(tree1.first, std::max(tree2.first, combineTree));
    }
};
