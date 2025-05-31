#include <algorithm>
#include <vector>
using std::vector;

/*
 * Node u is target to node v if the number of edges on the path from u to v is even.
 * NOTE: A node is always target to it self
 *
 * Intuition:
 * Is about as the first version but here we only count path with even distance.
 * So the approach will be the same separate the process into 2 for each each tree.
 * Is easy to track even path if start from a single source of node O(n^2)
 * but how can we check it efficiently if starting from each node?
 * There's a clever way, we can start from 1 source node then mark the color as black if even distance from that node
 * otherwise white. Because if we start from other node, the number of nodes which has even path is actually the same.
 *
 * So while for the other tree, then we do the same but we dont really have to strict it just choose the 1 with odd path
 * due to the reason of additional 1 edges. This is because if there is more even nodes then we can just simply connect
 * the odd nodes such that it will form even path
 * Time Complexity: O(n)
 * */

class Solution
{
  private:
    void dfs(const vector<vector<int>> &adjList, vector<int> &colors, const int &currNode, const int &parentNode,
             int &oddCnt, int &evenCnt)
    {
        if (colors[currNode] == 0)
            evenCnt++;
        else
            oddCnt++;

        for (const auto &neigh : adjList[currNode])
        {
            if (neigh == parentNode)
                continue;

            colors[neigh] = colors[currNode] ^ 1;
            dfs(adjList, colors, neigh, currNode, oddCnt, evenCnt);
        }
    }

    vector<vector<int>> buildAdjList(const vector<vector<int>> &edges)
    {
        int size(edges.size() + 1);
        vector<vector<int>> adjList(size, vector<int>());

        for (const auto &edge : edges)
        {
            adjList[edge[0]].emplace_back(edge[1]);
            adjList[edge[1]].emplace_back(edge[0]);
        }

        return adjList;
    }

  public:
    vector<int> maxTargetNodes(vector<vector<int>> &edges1, vector<vector<int>> &edges2)
    {
        auto adjList1{buildAdjList(edges1)}, adjList2{buildAdjList(edges2)};

        int m(edges1.size() + 1), n(edges2.size() + 1);
        int odd1{}, even1{}, odd2{}, even2{};
        vector<int> colors1(m), colors2(n);

        // colors[i] = 0 --> Even otherwise 1 --> Odd
        colors1[0] = colors2[0] = 1;
        dfs(adjList1, colors1, 0, -1, odd1, even1);
        dfs(adjList2, colors2, 0, -1, odd2, even2);

        vector<int> answers(m);
        int bestNodeTree2{std::max(odd2, even2)};
        for (int i{}; i < m; i++)
            answers[i] = (colors1[i] ? odd1 : even1) + bestNodeTree2;

        return answers;
    }
};
