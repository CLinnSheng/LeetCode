#include <algorithm>
#include <vector>

/*
 * Goal: Return the minimum cost to reach the top of the floor.
 * TAKE NOTE: We can either start from the step with index 0 or the stop with
 * index 1 Each time you can either climb one or two steps
 *
 * Intuition:
 * We can either start from step 0 or step 1
 * Using information from the past & repetitive subproblem.
 * Can solve it using dp. So instead of start from the start, we do it backwards
 * to make thing much more eaasier
 *
 * Top Down Approach:
 * Recursive --> Caching
 * So at every index we can either jump once or twice, and then the information passing down is the index.
 * So the dp can just 1d array
 * */
class Solution
{
  private:
    int dfs(const int index, const std::vector<int> &cost, std::vector<int> &caching)
    {
        if (index == cost.size())
            return 0;

        if (caching[index] != -1)
            return caching[index];
        return caching[index] = cost[index] + std::min(dfs(index + 1, cost, caching), dfs(index + 2, cost, caching));
    }

  public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        // Bottom Up Approach
        // int n(cost.size());
        //
        // for (auto i{n - 3}; i >= 0; i--)
        //     cost[i] += std::min(cost[i + 1], cost[i + 2]);
        //
        // return std::min(cost[0], cost[1]);

        std::vector<int> caching(cost.size() + 1, -1);
        return std::min(dfs(0, cost, caching), dfs(1, cost, caching));
    }
};
