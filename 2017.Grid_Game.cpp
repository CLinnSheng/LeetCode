#include <algorithm>
#include <climits>
#include <vector>
using ll = long long;

/*
 * 0-indexed 2d array of size 2xn
 * Robot initially starts at (0, 0) and ends at (1, n - 1). Each robot can only move down or to the right
 * At start, the first robot will moves first collecting all the points from the cell on its path.
 * For all the cell traversed on the path, it is set to 0. Then the second robot will moves and do the same thing.
 * Take Note: Their path may intersect with one another.
 * Both robot will need to be play optimally on choosing their path so that they can get the maximum score.
 *
 * Intuition:
 * We notice that they will be two chunks of cells left every time the first robot traversed. One on the top right &
 * another one on the top left. So the second robot can only choose either one because the robot cannot move up. So is
 * there an optimze way to get the score in O(1). The answer is yes if and only if we precompute the prefix score. So we
 * just need to iterate through the grid cell on the first row, because at index ith the first  robot will move down and
 * turn right all the way to the end. So we basically just need to minus the prefix sum at the index i for  the first
 * row and for the second row just get the prefix sum at i - 1
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    ll gridGame(std::vector<std::vector<int>> &grid)
    {
        int COLS(grid[0].size());
        std::vector<ll> prefixSumR1(grid[0].begin(), grid[0].end()), prefixSumR2(grid[1].begin(), grid[1].end());

        // populate the prefixSumArray
        for (int i{1}; i < COLS; i++)
        {
            prefixSumR1[i] += prefixSumR1[i - 1];
            prefixSumR2[i] += prefixSumR2[i - 1];
        }

        // since both robot will play optimally
        // so we need to consider the best move from first player
        ll score{LONG_LONG_MAX};
        for (int i{}; i < COLS; i++)
        {
            // means that the first robot chose to move down at this index
            ll top{prefixSumR1[COLS - 1] - prefixSumR1[i]};
            ll bottom{(i == 0) ? 0 : prefixSumR2[i - 1]};

            // robot2 can only choose 1 path
            // so choosing the 1 with the most score
            auto currScore{std::max(top, bottom)};

            // since need to optimize robot1 score, so we only take the 1 robot2 have the least
            score = std::min(score, currScore);
        }
        return score;
    }
};
