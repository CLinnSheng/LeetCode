#include <algorithm>
#include <climits>
#include <functional>
#include <vector>

/*
 * Goal: Return the minimum number of days need to travel every day in the list of days
 * Train ticket sold in 3 different ways:
 * i. 1-day pass sold for costs[0] dollars
 * ii. 7-day pass sold for costs[1] dollars
 * iii. 30-day pass sold for costs[2] dollars
 *
 * Intuition:
 * This is actually a decision tree problem.
 * At any point of time we have 3 option to choose.
 * We can solve it naively by using dfs & backtracking.
 * All we need is just 1 variable to keep track of the index of days.
 * However, it exceeds the time limit, we can improve it by using caching because
 * we can see there is overlapping subproblem.
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 *
 * */
class Solution
{
  private:
    const std::vector<int> DAYS{1, 7, 30};

  public:
    int mincostTickets(std::vector<int> &days, std::vector<int> &costs)
    {
        int n_day(days.size());

        // top-down approach

        //     // Base case
        //     if (index_days >= n_day)
        //         return 0;
        //
        //     // Memoziaiton
        //     if (dp[index_days] != 0)
        //         return dp[index_days];
        //
        //     int dollars{INT_MAX};
        //     for (int i{0}; i < 3; i++)
        //     {
        //         int inner_index_days{index_days};
        //         while (inner_index_days < n_day && days[inner_index_days] < days[index_days] + DAYS[i])
        //             inner_index_days++;
        //
        //         dollars = std::min(dollars, costs[i] + dfs_backtracking(inner_index_days));
        //     }
        //     dp[index_days] = dollars;
        //     return dollars;
        // };
        // return dfs_backtracking(0);

        // Bottom-up approach
        int lastDay{days[n_day - 1]};
        std::vector<int> dp(lastDay + 1, 0);

        int i{};
        for (int day{1}; day <= lastDay; day++)
            if (day < days[i])
                // means that we dont have to travel, so the costing wll be the same as the previous day
                dp[day] = dp[day - 1];
            else
            {
                // we need to travel
                i++;
                dp[day] = INT_MAX;
                // therefore we need to find the minimum cost to travel on this day by checking all 3 costs of different
                // number of days
                for (int i{}; i < 3; i++)
                    // in case for negative day
                    dp[day] = std::min(dp[day], dp[std::max(day - DAYS[i], 0)] + costs[i]);
            }

        return dp[lastDay];
    }
};
