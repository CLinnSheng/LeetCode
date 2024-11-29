#include <deque>
#include <queue>
#include <utility>
#include <vector>
/*
 * Goal: Return the minimum number of obstacles to remove so you can move from
 * the upper left corner to the lower right corner
 *
 * Intuition: This is a graph problem we can use dfs/bfs to traverser the graph
 * My first thought will be using dfs & backtracking to traverse all the
 * possible path and take the minimum. But this will be very inefficient,
 * O(4^m*n)
 *
 * We can further optimize this since it only want the minimum obstacles, we can
 * use greedy method everytime chossing a path we always choose the 1 with
 * minimum obstacles. Dijkstra Algorithm. Time Complexity: O(m*nlogm*n) Space
 * Complexity: O(m*n)
 *
 * Theres a more optimal way which we can reduce the time complexity to just
 * O(m*n) which is by using bfs. This bfs is quite similar to dijkstra algorithm
 * where we only choose the least obstacle to traverse every single time We use
 * a deque data structure to store the next cell we want to move and then the
 * deque is monotomic increasing
 * */

struct compartor {
  bool operator()(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] > b[0];
  }
};

class Solution {
public:
  const std::vector<std::pair<int, int>> DIRECTIONS{
      {0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int minimumObstacles(std::vector<std::vector<int>> &grid) {

    int ROWS = grid.size(), COLS = grid[0].size();

    // // Dijkstra Algorithm
    // std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
    //                     compartor>
    //     minHeap;
    // // format: (obstacle, row, col)
    // minHeap.push({0, 0, 0});
    // std::vector<std::vector<bool>> visited(ROWS,
    //                                        std::vector<bool>(COLS, false));
    // visited[0][0] = true;
    //
    // while (!minHeap.empty()) {
    //   auto current = minHeap.top();
    //   minHeap.pop();
    //
    //   auto currObstacles{current[0]}, currRow{current[1]},
    //   currCol{current[2]};
    //
    //   if (currRow == ROWS - 1 && currCol == COLS - 1)
    //     return currObstacles;
    //
    //   for (const auto &[_r, _c] : DIRECTIONS) {
    //     auto newR = _r + currRow;
    //     auto newC = _c + currCol;
    //
    //     if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS ||
    //         visited[newR][newC])
    //       continue;
    //
    //     // We dont want to revisit the cell we visited before because
    //     // the next time we visit it will be equal or greater than the firs
    //     time
    //     // we visited so no point because we are trying to find the minimum
    //     // obstacles
    //     visited[newR][newC] = true;
    //     minHeap.push({currObstacles + grid[newR][newC], newR, newC});
    //   }
    // }
    // return -1;
    //
    // obstacles, row, col
    std::deque<std::vector<int>> queue;
    std::vector<std::vector<bool>> visited(ROWS,
                                           std::vector<bool>(COLS, false));
    queue.push_back({0, 0, 0});
    visited[0][0] = true;

    while (!queue.empty()) {
      // we always take from the front because it has the least obstacles
      auto current = queue.front();
      queue.pop_front();
      auto currObstacles{current[0]}, currRow{current[1]}, currCol{current[2]};

      if (currRow == ROWS - 1 && currCol == COLS - 1)
        return currObstacles;

      for (const auto &[_r, _c] : DIRECTIONS) {
        auto newR = _r + currRow;
        auto newC = _c + currCol;

        if (newR < 0 || newC < 0 || newR >= ROWS || newC >= COLS ||
            visited[newR][newC])
          continue;

        visited[newR][newC] = true;
        // if got obstacle append it from the back
        if (grid[newR][newC])
          queue.push_back({currObstacles + 1, newR, newC});
        else
          queue.push_front({currObstacles, newR, newC});
      }
    }
    return -1;
  }
};
