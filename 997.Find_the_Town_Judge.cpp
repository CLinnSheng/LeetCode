#include <vector>
using std::vector;

/*
 * n people label from 1 to n. One of these people is a judge
 * if judge exists then:
 * 1. judge trust nobody.
 * 2. Everybody trust judge
 * 3. Only one person statisfies property 1 & 2
 *
 * Given an array trust[i] = [ai, bi] represting the person label ai trust the person label bi.
 *
 * Goal: Return the label of the judge otherwise -1
 *
 * Intuition:
 * We can actually make this as a graph, we can treat the trust relationship as an edge.
 * Basically a judge trust nobody & everybody trust the judge that means in a graph property
 * the node will have n - 1 indegree & 0 outdegree
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegree(n, 0), outdegree(n, 0);
        // O(N)
        for (const auto &edge : trust)
        {
            outdegree[edge[0] - 1]++;
            inDegree[edge[1] - 1]++;
        }

        // O(N)
        for (int i{}; i < n; i++)
            if (inDegree[i] == n - 1 && outdegree[i] == 0)
                return i + 1;

        return -1;
    }
};
