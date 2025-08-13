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
 * We can treat the relationship as a graph
 * We can have indegree and outdegree. So for judge, it need to have  n - 1 indegree and 0 outdegree
 * */
class Solution
{
  public:
    int findJudge(int n, vector<vector<int>> &trust)
    {
        vector<int> inDegree(n + 1, 0), outDegree(n + 1, 0);
        for (const auto &relationship : trust)
        {
            inDegree[relationship[1]]++;
            outDegree[relationship[0]]++;
        }

        for (int i{1}; i <= n; i++)
            if (inDegree[i] == n - 1 && outDegree[i] == 0)
                return i;

        return -1;
    }
};
