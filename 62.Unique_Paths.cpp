/*
 * Robot initially at top-left corner and tries to move to the bottom-right corner.
 * NOTE: The robot can only move down or right at any point in time.
 *
 * Goal: Find the number of possiblee unique paths that the robot can take to reach the bottom-right corner.
 *
 * Intuition:
 * This is can be solve by recursivly dfs.
 * However, we can observe from the brute force, there is overlapping of the same question.
 * therefor we can apply caching. The cache array will be 2d because we passing 2 information while dfs
 * */
#include <vector>
class Solution
{
  private:
    int dfs(const int row, const int col, const int m, const int n, std::vector<std::vector<int>> &caching)
    {
        // Check Boundary
        if (row < 0 || col < 0 || row >= m || col >= n)
            return 0;

        // If reach exit state
        if (row == m - 1 && col == n - 1)
            return 1;

        // Move down or right
        return dfs(row, col + 1, m, n, caching) + dfs(row + 1, col, m, n, caching);
    }

  public:
    int uniquePaths(int m, int n)
    {
        // top-down approach
        std::vector<std::vector<int>> caching(m, std::vector<int>(n, -1));
        return dfs(0, 0, m, n, caching);

        // bottom-up approach
        // we can actually observe the real computation starts from the last cell from the top-down approach.
        // So for bottom-up we just have to start from the last cell and then to the left then move the cell and
        // eventually reach the starting cell as the last cell
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        // every dp[i][j] means that from cell(i, j) how many unique path it exists to reach the last cell
        // so dp[m - 1][n - 1] has exactly 1 step
        // dp[m - 1][n - 1] = 1;
        //
        // for (int i{m - 1}; i >= 0; i--)
        //     for (int j{n - 1}; j >= 0; j--)
        //         if (i == m - 1 && j == n - 1)
        //             continue;
        //         else
        //             dp[i][j] = dp[i + 1][j] + dp[i][j + 1];
        //
        // return dp[0][0];
    }
};
