#include <functional>
#include <utility>
#include <vector>

/*
 * Goal: Find the number of islands.
 * An islands is formed by connecting adjacent lands horizontally or vertically
 *
 * Intuition: Dfs the grid if is it a land and then search through all the
 * nearby lands and mark it as visited so that we wont visit it again. Therefore
 * this will result in a piece of land. Then continue to search all until there
 * is no more land Time Complexity: O(m*n) because we traverse all Space
 * Complexity: O(m*n) recursive call stack
 * */

class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int numIslands(std::vector<std::vector<char>> &grid) {
    int n_row = grid.size();
    int n_col = grid[0].size();

    int ans = 0;

    std::function<void(const int &, const int &)> dfs = [&](const int &row,
                                                            const int &col) {
      if (row < 0 || col < 0 || row >= n_row || col >= n_col ||
          grid[row][col] == '0')
        return;

      // mark as visited
      grid[row][col] = '0';

      for (const auto &[_row, _col] : DIRECTIONS) {
        auto new_row = _row + row;
        auto new_col = _col + col;

        dfs(new_row, new_col);
      }
    };
    for (int i = 0; i < n_row; i++)
      for (int j = 0; j < n_col; j++)
        if (grid[i][j] == '1') {
          dfs(i, j);
          ans++;
        }

    return ans;
  }
};
