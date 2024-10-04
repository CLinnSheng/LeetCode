/*
Goal: Return the minimum number of minutes that must elpase until there are 0
fresh fruit NOTE: Every minute, if a fresh fruit is horizontally or vertically
adjacent to a rotten fruit, then the fresh fruit also become rotten. Intuition:
So the fresh fruit take place next (horizontally or vertically) to a rotten
fruit it will turns rotten. So we only need to know the position of rotten
fruit. And every minute all the fresh fruit rotten at the same time Time
Complexity: O(m*n) Space Complexity: O(m*n)
*/
#include <deque>
#include <vector>

class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS = {
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  int orangesRotting(std::vector<std::vector<int>> &grid) {

    int n_row = grid.size();
    int n_col = grid[0].size();

    int n_freshfruit = 0;

    // to keep track of the position of the rotten fruit
    std::deque<std::pair<int, int>> rottenfruit_pos;
    int time = 0;

    for (int row = 0; row < n_row; row++)
      for (int col = 0; col < n_col; col++) {
        if (grid[row][col] == 1)
          n_freshfruit++;
        if (grid[row][col] == 2)
          rottenfruit_pos.emplace_back(row, col);
      }

    if (n_freshfruit == 0)
      return 0;
    if (rottenfruit_pos.empty())
      return -1;

    // now we stimulate every single minute
    while (n_freshfruit > 0 && !rottenfruit_pos.empty()) {
      int curr_size = rottenfruit_pos.size();

      // At this minute every fresh fruit that is adjacent to the rotten fruit
      // will get rotten
      for (int i = 0; i < curr_size; i++) {
        const auto [y, x] = rottenfruit_pos.front();
        rottenfruit_pos.pop_front();

        for (const auto &[_y, _x] : DIRECTIONS) {
          int new_y = y + _y;
          int new_x = x + _x;

          if (new_x < 0 || new_y < 0 || new_x >= n_col || new_y >= n_row ||
              grid[new_y][new_x] != 1)
            continue;

          n_freshfruit--;
          grid[new_y][new_x] = 2;
          rottenfruit_pos.emplace_back(new_y, new_x);
        }
      }
      time++;
    }
    return (n_freshfruit != 0) ? -1 : time;
  }
};
