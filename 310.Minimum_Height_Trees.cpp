#include <functional>
#include <vector>
using std::vector;

/*
 * Goal: Return a list of all MHT's root labels.
 * MHT: among all possible rooted trees
 *
 * Intuition:
 * This is a tree problem and we can traverse the tree to find the height.
 * We just simply need to start from every single node as we need to treat it as a node
 * Time Complexity: V * (V + E)
 * */
class Solution
{
  public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>> &edges)
    {
        vector<int> answer;

        // build the adj list
        vector<vector<int>> adjList(n);
        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        std::function<int(const int &, const int &)> dfs = [&](const int &node, const int &parent) {
            int height{};

            for (const auto &neigh : adjList[node])
                if (neigh != parent)
                {
                    height = std::max(height, 1 + dfs(neigh, node));
                }
            return height;
        };

        int minHeight{n};
        for (int i{}; i < n; i++)
        {
            int currHeight{dfs(i, -1)};

            if (minHeight > currHeight)
            {
                answer = {i};
                minHeight = currHeight;
            }
            else if (minHeight == currHeight)
                answer.emplace_back(i);
        }
        return answer;
    }
};
