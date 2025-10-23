#include <climits>
#include <vector>

/*
 * Goal Find the minimum path sum from top left to bottom right
 * just return the path sum
 *
 * Intuition:
 * Ok this must be a graph problem --> DFS/BFS
 * DFS will be much more easier to implement
 * We can just recursively go through the grid and find the minimum sum of path until it reach the final cell
 * NOTE: We can either move down or right at any point at time
 * Since at each cell we can choose to move either 2 direction and there is m + n cell
 * Time Complexity: O(2^(m + n))
 * TO reach the final cell, the maximum number of move can be make is actuall m - 1 + n - 1. one move to the most bottom
 * and one move to the most right Therefor the recursion stack at most is m + n - 2 Space Complexity: O(m + n)
 *
 * If we observe from the brute force way, we can actaully see we have recompute some visited cell
 * We can use caching to improve it to O(m*n)
 * Space Complexity: O(m*n)
 * */

class Solution
{
  private:
    int dfs(std::vector<std::vector<int>> &grid, const int &row, const int &col, std::vector<std::vector<int>> &caching)
    {
        // Base Case
        if (row == grid.size() - 1 && col == grid[0].size() - 1)
        {
            return grid[row][col];
        }

        // If out of bound
        if (row == grid.size() || col == grid[0].size())
        {
            return INT_MAX;
        }

        if (caching[row][col] != -1)
        {
            return caching[row][col];
        }

        return caching[row][col] =
                   grid[row][col] + std::min(dfs(grid, row + 1, col, caching), dfs(grid, row, col + 1, caching));
    }

  public:
    int minPathSum(std::vector<std::vector<int>> &grid)
    {
        std::vector<std::vector<int>> caching(grid.size(), std::vector<int>(grid[0].size(), -1));
        return dfs(grid, 0, 0, caching);
    }
};
