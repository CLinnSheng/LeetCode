#include <functional>
#include <unordered_set>
#include <vector>

/*
 * Undirected graph with n vertices.
 * Connected Component is a subgraph of a graph in which there exists a path betweem any two vertices, and no vertex of
 * the subbgraph shares an edge with a vertex outside the subgraph
 *
 * Goal: Return the number of complete connected components of the graph
 *
 * Intuition:
 * First thought will be using unionFind because we can straightaway connect all the component belong to the same
 * subgraph Then just iterate through the parent array and find out how many parents is there
 *
 * We can also use bfs/dfs
 * Dfs will be much more easier, just iterate through the vertices and mark all those nodes or connected vertices, so
 * that we wont travel again. Time complexity wise is about the same which is O(V+E) but dfs is much more easier to
 * implement
 * */
class Solution
{
  public:
    int countCompleteComponents(int n, std::vector<std::vector<int>> &edges)
    {
        int answer{};
        std::unordered_set<int> visited;
        // building the adjList
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        std::function<void(const int &, int *)> dfs = [&](const int &currNode, int *componentInfo) {
            // mark it
            visited.insert(currNode);
            componentInfo[0]++;
            componentInfo[1] += adjList[currNode].size();

            for (const auto &neighNode : adjList[currNode])
                if (!visited.count(neighNode))
                    dfs(neighNode, componentInfo);
        };

        for (int node{}; node < n; node++)
            if (!visited.count(node))
            {
                // have an array to track the comoponent info
                // first index --> number of node
                // second index --> number of edges
                // Complete graph has n*(n-1)/2 edges
                // since our adjList store the edges in both endpoint then we can simply remove the 2
                int componentInfo[2]{};
                dfs(node, componentInfo);

                if (componentInfo[1] == (componentInfo[0] * (componentInfo[0] - 1)))
                    answer++;
            }
        return answer;
    }
};
