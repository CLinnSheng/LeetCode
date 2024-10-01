#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return all the distinct solution to the n-queens puzzle.
 * Intuition: Need to place n queens in n * n board such that every queen
 * couldnt attack each queen We can use dfs and backtracking approach. Try to
 * find a column in every row such taht placing the queen is safe Use set data
 * structure to determine whether the coordinate is safe or not for col,
 * diagonal & another diagonal Time Complexity: O(n^2) Space Complexity: O(n)
 * */

class Solution {
public:
  std::vector<std::vector<std::string>> solveNQueens(int n) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (!n)
      return {{}};

    std::vector<std::vector<std::string>> ans;

    std::unordered_set<int> col;
    std::unordered_set<int> diagonal;
    std::unordered_set<int> diagonal_opp;

    std::vector<std::string> placement(n, std::string(n, '.'));

    std::function<void(int)> dfs_backtracking = [&](const int row) {
      if (row == n) {
        ans.emplace_back(placement);
        return;
      }

      for (int c = 0; c < n; c++) {
        // Check whether is it safe to place the queen
        if (col.count(c) || diagonal.count(row + c) ||
            diagonal_opp.count(row - c))
          continue;

        col.insert(c);
        diagonal.insert(row + c);
        diagonal_opp.insert(row - c);

        // dfs
        placement[row][c] = 'Q';
        dfs_backtracking(row + 1);

        // backtracking
        col.erase(c);
        diagonal.erase(row + c);
        diagonal_opp.erase(row - c);
        placement[row][c] = '.';
      }
    };
    dfs_backtracking(0);
    return std::move(ans);
  }
};
