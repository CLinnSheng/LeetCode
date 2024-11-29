#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

/*
 * Standing in the top left cell of the matrix in the 0th second, and you must
 * move to any adjacent cell in 4 directions. Each move take s 1 wsecond. Goal:
 * Return the minimum time required in which u can visit the bottom right cell
 * of the matrix or else return -1 if not able to reach
 *
 * Intuition: This is a graph problem and also the situation where we cannot
 * reach the bottom right cell when we cannot move to any adjacent cell this is
 * only possible at the starting cell where all the adjacent cell is greater
 * than 1
 *
 * there are 3 choices dijkstra, dfs &  bfs
 * Since we want to find the optimize time we can use greedy method which is the
 * dijkstra algorithm. The hard part is when all the neigh cell is greater than
 * the t + 1 & the only move is go back to previous cell we want to determine
 * when we can traverse the min neigh cell. Theres a observation if the diff
 * between the neigh cell n the current cell is odd then there is no waiting
 * time for eg at time t = 1 we at 1 & then we want to go to cell = 4, so it
 * will be 1 -> 0 -> 1 -> 4, t = 4 if the neigh cell is 5 then we will have 1
 * more extra time which takes 6 seoncd to reach cell 5 1 -> 0 -> 1 -> 0 -> 1 ->
 * 5
 * Time Complexity: O(mnlgmn)
 * Space Complexity: O(mn)
 * */
class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS{
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int minimumTime(std::vector<std::vector<int>> &grid) {

    int ROWS = grid.size(), COLS = grid[0].size();

    if (grid[0][1] > 1 && grid[1][0] > 1)
      return -1;

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        std::greater<>>
        minHeap;
    // time, row, col
    minHeap.push({0, 0, 0});

    std::vector<std::vector<bool>> visited(ROWS,
                                           std::vector<bool>(COLS, false));
    visited[0][0] = true;

    while (!minHeap.empty()) {
      auto curr = minHeap.top();
      minHeap.pop();

      auto currTime{curr[0]}, currRow{curr[1]}, currCol{curr[2]};

      if (currRow == ROWS - 1 && currCol == COLS - 1)
        return currTime;

      for (const auto &[_r, _c] : DIRECTIONS) {
        auto newRow = _r + currRow;
        auto newCol = _c + currCol;

        if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS ||
            visited[newRow][newCol])
          continue;

        int waitingTime =
            std::abs(grid[newRow][newCol] - currTime) % 2 == 0 ? 1 : 0;
        int nextTime =
            std::max(grid[newRow][newCol] + waitingTime, currTime + 1);

        minHeap.push({nextTime, newRow, newCol});
        visited[newRow][newCol] = true;
      }
    }
    return -1;
  }
};
