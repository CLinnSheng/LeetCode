#include <algorithm>
#include <vector>

/*
 * Given an m * n binary matrix filled with 0's & 1's, find the largest square containing only 1's and return its area.
 *
 * Intuition:
 * First thought need to find area, we can just simply use dfs & mark those visited cell so that we dont visited again.
 * But the constraint is that the cell must be a square. How can we do that?
 *
 * If we use brute force, basically trying every single cell.
 * This will be O(n^4) --> O(n ^ 2) for trying every single cell & O(n^2) for finding the biggest square from this cell
 * or we can also use recursion, if we notice how to determine whether has a legit square right, just check its right,
 * down & diagnoal down. Get the min + 1. Because getting the min, we can ensure that the overall square contains all 1
 * or might contains some 0s We can notice that, there's actually quite a lot of repetitive work. We can optimize it by
 * using memoziatoin or caching. Eventually we can use dp
 * Time Complexity: O(m * n)
 * Space Complexity: O(m * n)
 * */
class Solution
{
  private:
    int ans{};
    int helper(const std::vector<std::vector<char>> &matrix, std::vector<std::vector<int>> &dp, const int &row,
               const int &col)
    {
        // boundary checking
        if (row >= matrix.size() || col >= matrix[0].size())
            return 0;

        // check whethre we visit this cell before
        if (dp[row][col] != -1)
            return dp[row][col];

        int right = helper(matrix, dp, row, col + 1);
        int down = helper(matrix, dp, row - 1, col);
        int diag = helper(matrix, dp, row + 1, col + 1);

        // can construct square if and only if the current cell also 1
        if (matrix[row][col] == '1')
        {
            dp[row][col] = 1 + std::min(right, std::min(down, diag));
            ans = std::max(ans, dp[row][col]);

            return dp[row][col];
        }

        return dp[row][col] = 0;
    }

  public:
    int maximalSquare(std::vector<std::vector<char>> &matrix)
    {

        // top-down approach
        // std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), -1));
        // helper(matrix, dp, 0, 0);
        // return ans * ans;

        // bottom-up approach
        int row(matrix.size()), col(matrix[0].size());
        std::vector<std::vector<int>> dp(matrix.size(), std::vector<int>(matrix[0].size(), 0));

        for (int r{}; r < row; r++)
            for (int c{}; c < col; c++)
            {
                if (matrix[r][c] == '0')
                    continue;

                // for first row and col the maximum that can be formed is 1
                // for bottom up instead of right bottom diagonal we go another way because we dont have the future but
                // we can compute it out from the past
                int left{c > 0 ? dp[r][c - 1] : 0};
                int top{r > 0 ? dp[r - 1][c] : 0};
                int diag{(r > 0 && c > 0) ? dp[r - 1][c - 1] : 0};

                dp[r][c] = 1 + std::min(left, std::min(top, diag));

                ans = std::max(ans, dp[r][c]);
            }

        return ans * ans;
    }
};
