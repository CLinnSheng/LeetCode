#include <algorithm>
#include <climits>
#include <functional>
#include <vector>

/*
 * Lets say we at cell(i, j). We can only move in 3 directions
 * (i + 1, j + 1), (i - 1, j + 1) or (i, j + 1)
 *
 * Constraint: We can only start from the cell in the first column & the next
 * cell we move to must be bigger than the curent cell.
 * Goal: Return the maximum number of moves that can be made
 * Intuition: we actually traverse the same cell multiple times & for each cell
 * it has a number of steps of reaching it. So we can use caching and this leads
 * to dynamic programming Time Complexity: O(m*n) Space Complexity: O(m*n)
 * */
class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS = {{1, 1}, {-1, 1}, {0, 1}};

  int maxMoves(std::vector<std::vector<int>> &grid) {

    auto n_row{grid.size()};
    auto n_col{grid[0].size()};

    std::vector<std::vector<int>> dp(n_row, std::vector<int>(n_col, -1));

    for (int i{}; i < n_row; i++)
      dp[i][0] = 1;

    int maxMoves{};

    for (int j{1}; j < n_col; j++)
      for (int i{}; i < n_row; i++) {

        // 3 possible traversing way, instead of going forward we going
        // backwards because we are applying dp and we cannot apply what we
        // havent compute yet
        if (grid[i][j] > grid[i][j - 1] && dp[i][j - 1] > 0)
          dp[i][j] = std::max(dp[i][j], dp[i][j - 1] + 1);

        if (i - 1 >= 0 && grid[i][j] > grid[i - 1][j - 1] &&
            dp[i - 1][j - 1] > 0)
          dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);

        if (i + 1 < n_row && grid[i][j] > grid[i + 1][j - 1] &&
            dp[i + 1][j - 1] > 0)
          dp[i][j] = std::max(dp[i][j], dp[i + 1][j - 1] + 1);

        maxMoves = std::max(maxMoves, dp[i][j] - 1);
      }

    return std::move(maxMoves);
  }
};
