/*
Goal: Fill each land cell with the distance to its nearest treasure chest.
Intuition: We need dfs from the position of treasure. So just  + 1 from the
distance of previous cell so for the the first land of the traverse from
treasure will be 0 + 1 because distance of treasure itself will be 0 and then
everytime we reach a land we will just take the min because it might be visit
from other treasure position as well Space Complexity: O(m*n) Time
Complexity:O(m*n)
*/
#include <cstdint>
#include <ios>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  void islandsAndTreasure(std::vector<std::vector<int>> &grid) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (grid.empty())
      return;

    int n_row = grid.size(), n_col = grid[0].size();
    std::deque<std::pair<int, int>> queue;

    for (int row = 0; row < n_row; row++)
      for (int col = 0; col < n_col; col++)
        if (grid[row][col] == 0)
          queue.emplace_back(row, col);

    while (!queue.empty()) {
      const auto &coordinate = queue.front();
      queue.pop_front();
      int y = coordinate.first;
      int x = coordinate.second;

      for (const auto &[_row, _col] : DIRECTIONS) {
        auto new_row = y + _row;
        auto new_col = x + _col;

        if (new_row < 0 || new_col < 0 || new_col >= n_col ||
            new_row >= n_row || grid[new_row][new_col] != INT_MAX)
          continue;

        grid[new_row][new_col] =
            std::min(grid[new_row][new_col], grid[y][x] + 1);
        queue.emplace_back(new_row, new_col);
      }
    }
  }
};
