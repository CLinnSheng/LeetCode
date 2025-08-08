#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

/*
 * matchsticks[i] - length of ith matchsticks
 * Goal: Need to use all the matchsticks to make square.
 * NOTE: Cannot break any stick but can link them up, and all matchstick must be used exactly one time
 *
 * Intuition:
 * Need to make a square, so need 4 equal sides.
 * The sticks can be linked up together.
 * Need to find the possible combinations to make up 4 equal length sides
 * We can sort it first for easy handling because we trying to link up the matchsticks, so at earlier index if cannot
 * make it up to total length / 4 then that means we dont have to continue down the array, can stop right there
 * Time Complexity: O(4^n)
 * */
class Solution
{
  public:
    bool makesquare(std::vector<int> &matchsticks)
    {
        int ttlLength{std::accumulate(matchsticks.begin(), matchsticks.end(), 0)};

        // Check whether is it possible to split into 4
        if (!ttlLength % 4)
            return false;

        // Each side length
        int side{ttlLength / 4};
        std::vector<int> sidesLen(4, 0);

        // Sort the array in descending order
        std::sort(matchsticks.begin(), matchsticks.end(), [](const int &A, const int &B) { return A > B; });

        std::function<bool(const int &)> dfs_backtracking = [&](const int &index) {
            if (index == matchsticks.size())
                return true;

            // Iterate through the sides instead of the array because now we trying to build the sides
            for (int i{}; i < 4; i++)
            {
                if (matchsticks[index] + sidesLen[i] <= side)
                {
                    sidesLen[i] += matchsticks[index];
                    if (dfs_backtracking(index + 1))
                        return true;

                    // dfs_backtracking
                    sidesLen[i] -= matchsticks[index];
                }

                // Base Case to check whether side can be build or not because since the array is sorted, if earlier
                // index cannot build means at a later index also cannot build
                if (sidesLen[i] == 0)
                    return false;
            }

            return false;
        };
        return dfs_backtracking(0);
    }
};
