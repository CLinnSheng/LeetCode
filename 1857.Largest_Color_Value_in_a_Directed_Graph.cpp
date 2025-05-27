#include <algorithm>
#include <climits>
#include <string>
#include <string_view>
#include <vector>

/*
 * Directed graph of n colored nodes & m edges.
 * Given a string colors where colors[i] is a lowercase letter representing the color of ith node.
 * edges[i] = [ai,bi] indicates theres is a directed edge from node ai to bi.
 * Color volaue of a path is the number of nodes that are colored the most frequently occuring color along the path
 *
 * Goal: Return the color value of any valid path in the given path or -1 if contain cycle
 *
 * Intuition:
 * We can use dfs from every single node, and have an visited to check for cycle.
 * */
class Solution
{
  private:
    int dfs(const int &currNode, const std::string_view &colors, const std::vector<std::vector<int>> &adjList,
            std::vector<int> &visit, std::vector<std::vector<int>> &count)
    {
        if (!visit[currNode])
        {
            visit[currNode] = 1;

            for (const auto &neigh : adjList[currNode])
            {
                if (dfs(neigh, colors, adjList, visit, count) == INT_MAX)
                    return INT_MAX;

                for (int i{}; i < 26; i++)
                    count[currNode][i] = std::max(count[currNode][i], count[neigh][i]);
            }
            count[currNode][colors[currNode] - 'a']++;
            visit[currNode] = 2;
        }

        return visit[currNode] == 2 ? count[currNode][colors[currNode] - 'a'] : INT_MAX;
    }

  public:
    int largestPathValue(std::string colors, std::vector<std::vector<int>> &edges)
    {
        int n(colors.size()), m(edges.size());
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        std::vector<int> visit(n, 0);
        // count[src][color]
        std::vector<std::vector<int>> count(n, std::vector<int>(26, 0));

        for (const auto &edge : edges)
            adjList[edge[0]].emplace_back(edge[1]);

        int ans{};

        // DFS from every single node
        for (int i{}; i < n; i++)
            ans = std::max(ans, dfs(i, colors, adjList, visit, count));

        return ans == INT_MAX ? -1 : ans;
    }
};
