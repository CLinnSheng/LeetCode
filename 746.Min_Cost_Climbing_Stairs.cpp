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
 * */
class Solution
{
  public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        int n(cost.size());

        for (auto i{n - 3}; i >= 0; i--)
            cost[i] += std::min(cost[i + 1], cost[i + 2]);

        return std::min(cost[0], cost[1]);
    }
};
