#include <algorithm>
#include <vector>
using std::vector;

/*
 * 2 trees with m & n nodes.
 * edges1 with len m - 1 and edges 2 with n - 1.
 * Node u is target to node v if the number of edges on the path from u to v is less than or equal to k.
 * NOTE: A node is always target to itself.
 *
 * GoaL: Return an array of n integers answers where answers[i] is the maximum possible number of nodes target to node i
 * of the first tree if you have to connect one node from the first tree to another node of the tree.
 *
 * Intuition:
 * Basically in the first tree, for each node we need to find how many nodes are there can reach to the current with at
 * most k edges. Then repeat the same for the second tree but k - 1. Because we need to connect one edge from the first
 * tree to the second tree. Then basically just sum up. Use dfs.
 * THen which node to choose from connecting node from tree1 to tree2?
 * Simply just choose the 1 with the most target in tree2.
 * Since is a tree we dont have to check for whether is there a cycle or not
 * Time Complexity: O(a + b) where a = m nodes + m - 1 edges and b is the same
 * */
class Solution
{
  private:
    int dfs(vector<vector<int>> &adjList, const int &currNode, const int &parentNode, int currK)
    {
        if (currK < 0)
            return 0;

        // Beacuse a node itself
        int cnt{1};

        for (const auto &neigh : adjList[currNode])
        {
            // Handle cases where it travels back again
            if (neigh == parentNode)
                continue;
            cnt += dfs(adjList, neigh, currNode, currK - 1);
        }

        return cnt;
    }

    vector<int> helper(const vector<vector<int>> &edges, int k)
    {
        // Straight away return array of 1, because each node is target of itself and since can only can make 1 move
        // (actually true value is k + 1 for tree2)
        if (k == 0)
            return std::vector<int>(edges.size() + 1, 1);

        int len(edges.size() + 1);
        vector<vector<int>> adjList(len, vector<int>());
        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }
        vector<int> tree(len, 0);

        for (int i{}; i < len; i++)
            tree[i] = dfs(adjList, i, -1, k);

        return tree;
    }

  public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2, int k)
    {
        int len1(edges1.size()), len2(edges2.size());
        // Base Case cannot make any move, so straight away return arrays of 1 because each node is target of itself
        if (k == 0)
            return vector<int>(len1 + 1, 1);

        // O(m + n)
        vector<int> tree1 = helper(edges1, k);
        vector<int> tree2 = helper(edges2, k - 1);

        vector<int> answers;
        auto it{std::max_element(tree2.begin(), tree2.end())};
        for (int i{}; i <= edges1.size(); i++)
            answers.emplace_back(tree1[i] + *it);

        return answers;
    }
};
