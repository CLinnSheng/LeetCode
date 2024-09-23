#include <cstdint>
#include <ios>
#include <iostream>
#include <vector>

/*
 * Goal: Return the minimum cost to reach the top of the floor.
 * TAKE NOTE: We can either start from the step with index 0 or the stop with
 * index 1 Each time you can either climb one or two steps
 *
 * Intuition: Since want to find minimum costs and it involves with previous
 * event This is a dp Solution at each stair we compare whether want to climb 1
 * or 2 and make use of the prev data
 *
 * */
class Solution {
public:
  int minCostClimbingStairs(std::vector<int> &cost) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::int32_t size = cost.size();

    for (auto i = size - 3; i >= 0; i--)
      cost[i] += std::min(cost[i + 1], cost[i + 2]);

    return std::min(cost[0], cost[1]);
  }
};
