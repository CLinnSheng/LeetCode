#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

/*
 * At time t, the depth of water everywhere is t. Can enter any 4-adjacent cell
 * if and only if both squares individually are at most t.
 * Take Note: Can swim infinite distance in zero time as long as it met the
 * requirement & didnt go out of bound.
 *
 * Intuition: Can use dfs to search until it reach the final cell with the
 * condition given which is at most t. the t can be range in the min value of
 * the cell until the max value of the cell
 *
 * Time Complexity: O(4^(n^2)) because each cell can go 4 directoins & each
 * direction can maximum go n^2 times.
 *
 * We can do some optimization by using dijkstra algorithm where we will pick
 * the lowest t every single time. This reduce the time complexity to
 * O(n^2(logn^2)) -> O(n^2(logn)) Space Complexity: O(n^2)
 * */

struct comparator {
  bool operator()(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] > b[0];
  }
};

class Solution {
public:
  std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
  int swimInWater(std::vector<std::vector<int>> &grid) {

    std::size_t n_row{grid.size()}, n_col{grid[0].size()};

    std::vector<std::vector<bool>> visited(n_row,
                                           std::vector<bool>(n_col, false));

    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        comparator>
        minHeap;

    minHeap.push({grid[0][0], 0, 0});
    visited[0][0] = true;

    while (!minHeap.empty()) {
      auto currVal = minHeap.top();
      minHeap.pop();

      int t{currVal[0]}, row{currVal[1]}, col{currVal[2]};

      if (row == n_row - 1 && col == n_col - 1)
        return t;

      for (const auto &[row_, col_] : DIRECTIONS) {
        int newR{row + row_}, newC{col + col_};
        if (newR < 0 || newC < 0 || newR == n_row || newC == n_col ||
            visited[newR][newC])
          continue;

        visited[newR][newC] = true;
        minHeap.push({std::max(t, grid[newR][newC]), newR, newC});
      }
    }
    return n_row * n_col;
  }
};
