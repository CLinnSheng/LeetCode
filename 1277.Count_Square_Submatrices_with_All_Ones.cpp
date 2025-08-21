#include <functional>
#include <vector>

/*
 * Goal: Return the number of square submatrices are all 1
 *
 * Intuition:
 * We can just simply dfs from each cell to see how big the square can create from each cell as the starting point
 * If we observe carefully actually we are repeating solving the same subproblem, we can
 * further optimize this with DP
 *
 * Bottom Up approahc will be similar but in the another direction
 * because if we follow how caching or top down, we are trying to access the subporblem havent sovle yet.
 * So instead we treat that cell as the ending cell or the bottom right
 * */
class Solution
{
  public:
    int countSquares(std::vector<std::vector<int>> &matrix)
    {
        int ROWS(matrix.size()), COLS(matrix[0].size());
        int ans{};

        // Top-Down / Caching
        // std::vector<std::vector<int>> cache(ROWS, std::vector<int>(COLS, -1));
        //
        // std::function<int(const int &, const int &)> dfs = [&](const int &row, const int &col) {
        //     if (row == ROWS || col == COLS || !matrix[row][col])
        //         return 0;
        //
        //     // Check have we solved it before
        //     if (cache[row][col] != -1)
        //         return cache[row][col];
        //
        //     return cache[row][col] =
        //                1 + std::min(std::min(dfs(row, col + 1), dfs(row + 1, col)), dfs(row + 1, col + 1));
        // };
        //
        // for (int i{}; i < ROWS; i++)
        //     for (int j{}; j < COLS; j++)
        //         if (matrix[i][j])
        //             ans += dfs(i, j);

        // Bottom Up
        std::vector<std::vector<int>> dp(ROWS + 1, std::vector<int>(COLS + 1, 0));
        for (int row{}; row < ROWS; row++)
            for (int col{}; col < COLS; col++)
                if (matrix[row][col])
                {
                    dp[row + 1][col + 1] = 1 + std::min(dp[row][col], std::min(dp[row][col + 1], dp[row + 1][col]));
                    ans += dp[row + 1][col + 1];
                }
        return ans;
    }
};
