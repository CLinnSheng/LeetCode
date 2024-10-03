#include <functional>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

/*
 * Goal: Find the maximum area of island
 * Intuition: Is it similar to the question to find the number of island so
 * basically just add one mroe thing which is the area keep finding and updating
 * the maximum area Time COmplexity: O(m*n) Space Complexity: O(m*n)
 * */
class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n_row = grid.size();
    int n_col = grid[0].size();

    int maxArea = 0;

    std::function<int(const int &, const int &)> dfs = [&](const int &row,
                                                           const int &col) {
      if (row < 0 || col < 0 || row >= n_row || col >= n_col || !grid[row][col])
        return 0;

      int area = 1;
      // mark as visited
      grid[row][col] = 0;

      for (const auto &[_row, _col] : DIRECTIONS) {
        auto new_row = row + _row;
        auto new_col = col + _col;

        area += dfs(new_row, new_col);
      }

      return area;
    };

    for (int i = 0; i < n_row; i++)
      for (int j = 0; j < n_col; j++)
        if (grid[i][j])
          maxArea = std::max(maxArea, dfs(i, j));

    return maxArea;
  }
};
