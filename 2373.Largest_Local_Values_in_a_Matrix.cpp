#include <vector>

/*
 * Given an n x n matrix
 * Goal: Return an integer matrix maxLocal of size (n - 2) x (n - 2) such that
 * maxlocal[i][i] is equal to the largest value of the 3x3 matrix in grid
 * centered around row i + 1 and col j + 1
 *
 * Intuition: Iterate until n - 2 rows and columns, and find the maximum value
 * in the 3x3 matrix
 * */
class Solution {
public:
  std::vector<std::vector<int>>
  largestLocal(std::vector<std::vector<int>> &grid) {

    int n = grid.size();
    std::vector<std::vector<int>> ans;

    for (int row = 0; row < n - 2; row++) {
      std::vector<int> temp;
      for (int col = 0; col < n - 2; col++) {
        int x = std::max(grid[row][col],
                         std::max(grid[row][col + 1], grid[row][col + 2]));
        int y = std::max(grid[row + 1][col], std::max(grid[row + 1][col + 1],
                                                      grid[row + 1][col + 2]));
        int z = std::max(grid[row + 2][col], std::max(grid[row + 2][col + 1],
                                                      grid[row + 2][col + 2]));

        temp.emplace_back(std::max(x, std::max(y, z)));
      }
      ans.emplace_back(temp);
    }
    return std::move(ans);
  }
};
