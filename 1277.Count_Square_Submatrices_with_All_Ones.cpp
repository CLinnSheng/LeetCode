#include <algorithm>
#include <functional>
#include <vector>
/*
 * Goal: Return how many square submatrices have all ones.
 * Intuition: We have to check for every single entry in the matrix if it is a
 * '1', then check c + 1, r + 1 & (r+1, c+1) is 1 or not. Then keep recursively
 * checking This is actually very expensive in terms of time complexity But from
 * here we can see we keep solving the same subproblem So this lead me to use
 * dynamic programming to solve it. We can use a cache to store the subproblem
 * solution which is the maximum square can be created in the entry.
 * Top down approach will basically the same as the iterative/naive approach
 * just by utilize caching Bottown up approach will be slightly harder because
 * we cant start from matrix[0][0] because if we start from this we need
 * matrix[0][1], matrix[1][0] & matrix[1][1], which violates the principle of dp
 * where we uses the information that we havent compute for bottom up approach.
 * If we observe it clearly, theres a clever way instead of going into the
 * direction as top down approach, we can actually go into the opposite
 * direction by adding a new row and a new column initialized with 0. So
 * matrix[0][0] will be transformed into matrix[1][1]
 *
 * Time complexity: O(n*m)
 * Space Complexity: O(m + n)
 * */
class Solution {
public:
  int countSquares(std::vector<std::vector<int>> &matrix) {
    auto n_row{matrix.size()};
    auto n_col{matrix[0].size()};

    int res{};

    // top-down approach
    /*
    std::vector<std::vector<int>> topdownCache(n_row,
                                               std::vector<int>(n_col, -1));

    std::function<int(const int &, const int &)> topdownDP =
        [&](const int &row, const int &col) {
          if (row == n_row || col == n_col || !matrix[row][col])
            return 0;

          if (topdownCache[row][col] != -1)
            return topdownCache[row][col];

          int size{1};

          size += std::min({topdownDP(row, col + 1), topdownDP(row + 1, col),
                            topdownDP(row + 1, col + 1)});

          topdownCache[row][col] = size;

          return topdownCache[row][col];
        };

    for (int i{}; i < n_row; i++)
      for (int j{}; j < n_col; j++)
        res += topdownDP(i, j);
    */

    // bottom-up approach
    std::vector<std::vector<int>> bottomUpCache(n_row + 1,
                                                std::vector<int>(n_col + 1, 0));
    for (int i{}; i < n_row; i++)
      for (int j{}; j < n_col; j++)
        if (matrix[i][j]) {
          bottomUpCache[i + 1][j + 1] =
              1 + std::min({bottomUpCache[i][j + 1], bottomUpCache[i + 1][j],
                            bottomUpCache[i][j]});
          res += bottomUpCache[i + 1][j + 1];
        }

    return std::move(res);
  }
};
