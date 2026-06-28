#include <functional>
#include <vector>
/*
 * Check whether a tree is valid or not
 * A tree doesnt has a cycle, so what we can do is checking whether can we find a cycle
 * And also all the nodes must be connected
 * Just dfs the tree
 * */
class Solution
{
    std::vector<bool> visited;

  public:
    bool validTree(int n, std::vector<std::vector<int>> &edges)
    {
        if (edges.size() != n - 1)
        {
            return false;
        }

        visited = std::vector<bool>(n, false);
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        for (const auto &edge : edges)
        {
            // Edges are undirected so add both direction
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        std::function<bool(const int, const int)> dfs = [&](const int currNode, const int parentNode) {
            if (visited[currNode])
            {
                return false;
            }

            // Mark visited
            visited[currNode] = true;
            for (const auto &child : adjList[currNode])
            {
                // Make sure the node is not parentNode because the adjList is bidrectional
                if (child != parentNode && dfs(child, currNode) == false)
                {
                    return false;
                }
            }

            return true;
        };

        for (int i{}; i < n; i++)
        {

            if (visited[i] == false && dfs(i, -1) == false)
            {
                return false;
            }
        }

        // Final checking on whether all the nodes are connected or not
        for (const auto &visit : visited)
        {
            if (!visit)
            {
                return false;
            }
        }
        return true;
    }
};
