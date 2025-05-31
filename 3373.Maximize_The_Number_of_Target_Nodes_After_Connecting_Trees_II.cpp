#include <algorithm>
#include <vector>
using std::vector;

/*
 * Node u is target to node v if the number of edges on the path from u to v is even.
 * NOTE: A node is always target to it self
 *
 * Intuition:
 * Is about the same as the I version just some tweak on the condition of becoming the target node.
 * At here is only even path.
 * The approach will be the same which is using dfs and we can have a flag to determine whether is it even or not.
 * And then in terms way to compute the maxTargetNodes.
 * So what we basically do in the tree1 find the even edges and then for the tree2 find the odd edges because of we got
 * 1 extra edge to connect it then this make it even
 * If we observe, we repeat visiting some nodes. Why not we use cache?
 * So we can use caching to improve the time complexity
 * */
// class Solution
// {
//   private:
//     int dfs(const vector<vector<int>> &adjList, const int &currNode, const int &parentNode, bool isEven)
//     {
//         int res = isEven;
//
//         for (const auto neigh : adjList[currNode])
//         {
//             if (neigh == parentNode)
//                 continue;
//
//             res += dfs(adjList, neigh, currNode, !isEven);
//         }
//
//         return res;
//     }
//
//     vector<int> helper(const vector<vector<int>> &edges, bool isEven)
//     {
//         int n(edges.size() + 1);
//         vector<int> tree(n, 0);
//
//         vector<vector<int>> adjList(n, vector<int>());
//         for (const auto &edge : edges)
//         {
//             adjList[edge[0]].emplace_back(edge[1]);
//             adjList[edge[1]].emplace_back(edge[0]);
//         }
//
//         for (int i{}; i < n; i++)
//             tree[i] = dfs(adjList, i, -1, isEven);
//
//         return tree;
//     }
//
//   public:
//     vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
//     {
//         vector<int> tree1 = helper(edges1, true);
//         vector<int> tree2 = helper(edges2, false);
//
//         vector<int> answer;
//         auto it{std::max_element(tree2.begin(), tree2.end())};
//         for (int i{}; i <= edges1.size(); i++)
//             answer.emplace_back(tree1[i] + *it);
//
//         return answer;
//     }
// };
class Solution
{
  public:
    vector<vector<int>> buildList(const vector<vector<int>> &edges)
    {
        vector<vector<int>> adj(edges.size() + 1);
        for (auto &e : edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        return adj;
    }

    void dfsColor(const vector<vector<int>> &adj, int u, int parent, vector<int> &color, int &evenCnt, int &oddCnt)
    {
        if (color[u] == 0)
            evenCnt++;
        else
            oddCnt++;
        for (int v : adj[u])
            if (v != parent)
            {
                color[v] = color[u] ^ 1;
                dfsColor(adj, v, u, color, evenCnt, oddCnt);
            }
    }

    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        auto adjA = buildList(edges1), adjB = buildList(edges2);
        int n = adjA.size(), m = adjB.size();
        vector<int> colorA(n, -1), colorB(m, -1);
        int evenA = 0, oddA = 0, evenB = 0, oddB = 0;
        colorA[0] = 0;
        dfsColor(adjA, 0, -1, colorA, evenA, oddA);
        colorB[0] = 0;
        dfsColor(adjB, 0, -1, colorB, evenB, oddB);
        int maxiB = max(evenB, oddB);
        vector<int> res(n);
        for (int i = 0; i < n; i++)
            res[i] = (colorA[i] == 0 ? evenA : oddA) + maxiB;
        return res;
    }
};
