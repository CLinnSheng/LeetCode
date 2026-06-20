#include <vector>

/*
 * Return the minimum cost to reach the top of the staircase
 * We can either start from index 0 or index 1
 * At each step we can either take 1 or 2 steps
 *
 * Brute force way will recursive try 2 possible steps and get the minimum
 *
 * If you notice from the recursive function, sometime we are repeating doing the same thing
 * So from here we can use cache
 * Time Complexity: O(n)
 * */

class Solution
{
    std::vector<int> cache;
    int helper(const std::vector<int> &cost, int index)
    {
        if (index >= cost.size())
        {
            return 0;
        }

        if (cache[index] != -1)
        {
            return cache[index];
        }

        int cst = cost[index];

        return cache[index] = std::min(cst + helper(cost, index + 1), cst + helper(cost, index + 2));
    }

  public:
    int minCostClimbingStairs(std::vector<int> &cost)
    {
        cache = std::vector<int>(cost.size() + 1, -1);
        return std::min(helper(cost, 0), helper(cost, 1));
    }
};
