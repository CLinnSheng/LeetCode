#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

/*
 * Need to use all matchsticks to make a square
 * Note: Can not break any stick but can link them up
 *
 * Obesrvation:
 * The total length must be dvisible by 4 since we can link them up
 * The maximum length of a side is just basically total_sum / 4
 * So at each index we have 4 choices to put where the stick
 * This is a problem where we try find all the possible path
 * So backtracking will be the algo to solve this problem
 *
 * */

class Solution
{
  public:
    bool makesquare(std::vector<int> &matchsticks)
    {
        int ttlLen = std::accumulate(matchsticks.begin(), matchsticks.end(), 0);

        // Base Case
        if (matchsticks.size() < 4 || ttlLen % 4)
        {
            return false;
        }

        int len = ttlLen / 4;
        std::vector<int> side(4, 0);

        // Pruning Optimization
        // We can easily fill the side with the gratest length first
        std::sort(matchsticks.begin(), matchsticks.end(), [&](const int A, const int B) { return A > B; });

        std::function<bool(const int)> backtracking = [&](const int index) {
            if (index == matchsticks.size())
            {

                return true;
            }

            // Try placing all 4 side
            for (int i{}; i < 4; i++)
            {
                // Possible Placement
                if (side[i] + matchsticks[index] <= len)
                {
                    side[i] += matchsticks[index];

                    if (backtracking(index + 1))
                    {
                        return true;
                    }

                    // backtrack
                    side[i] -= matchsticks[index];
                }
            }
            return false;
        };

        return backtracking(0);
    }
};
