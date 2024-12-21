#include <functional>
#include <vector>

/*
 * Valid Split: Removing any set of edges, possibly empty, from the tree such that the resulting components all have
 * values that are divisible by k (total sum). Goal: Return the maximum number of components in any valid split
 *
 * Intuition:
 * Initially the whole tree is divisible by k, so if we remove x from n then n - x is also divisible by k.
 * This is a graph problem we can use dfs / bfs
 * We will choose dfs here
 * To find the maximum number of split, we need to start from subtree which is bottom up instead of from top
 * if start from the bottom we find the subtree that is divisible by k then we add the count to it
 *
 * Time Complexity: O(n + m) Traverse all nodes and edges
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int maxKDivisibleComponents(int n, std::vector<std::vector<int>> &edges, std::vector<int> &values, int k)
    {
        std::vector<std::vector<int>> adjList(n, std::vector<int>());
        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        int ans{};

        std::function<int(const int &, const int &)> dfs = [&](const int &currNode, const int &parentNode) {
            int sum{values[currNode]};

            // traverse
            for (const auto &neigh : adjList[currNode])
                if (neigh != parentNode)
                    sum += dfs(neigh, currNode);

            // check whether the subtreee can be divisible by k or not
            if (sum % k == 0)
                ans++;

            return sum % k;
        };

        dfs(0, -1);
        return ans;
    }
};
