#include <algorithm>
#include <climits>
#include <vector>

/*
 * n magicians standing in a line. Each magician has an attribute that gives you energy.
 * Some magicians can give negative energy which means taking energy from you.
 *
 * After absorbing energy from magician i, transported to magician i + k. Repeated until reach magician where i + k
 * doesnt exists
 *
 * Goal: Return the maximum energy you can get.
 *
 * Intuition:
 * Just do a nested loop for brute force way ended up in O(N^2)
 *
 * Optimized: If you observe from the brute force we did doing some redundant work.
 * Therefor, we can use dp to solve this problem in O(N)
 * Instead of traverse from the front, we traverse from the back such that we can reuse it.
 * dp[i] maximum energy can get if we starting from index i
 * */
class Solution
{
  public:
    int maximumEnergy(std::vector<int> &dungeon, int k)
    {
        int n(dungeon.size()), ans{INT_MIN};
        std::vector<int> dp(n);

        for (int i{n - 1}; i >= 0; i--)
        {
            dp[i] = dungeon[i] + (i + k >= n ? 0 : dp[i + k]);
            ans = std::max(ans, dp[i]);
        }
        return ans;
    }
};
