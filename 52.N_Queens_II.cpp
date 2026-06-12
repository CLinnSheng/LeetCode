/*
 * Find the number of distinct solutions
 * Similar to N_Queens. Similar approach to solve the solution
 * Try all possible path/ways
 * */
#include <functional>
#include <unordered_set>
class Solution
{
  public:
    int totalNQueens(int n)
    {
        int ans{};
        std::unordered_set<int> cols, diagonal_1, diagonal_2;

        std::function<void(const int)> backtracking = [&](const int row) {
            if (row == n)
            {
                ans++;
                return;
            }

            for (int col{}; col < n; col++)
            {
                // Check is this cell valid
                if (!(cols.count(col) || diagonal_1.count(col + row) || diagonal_2.count(col - row)))
                {
                    cols.insert(col);
                    diagonal_1.insert(col + row);
                    diagonal_2.insert(col - row);

                    backtracking(row + 1);

                    // backtrack
                    cols.erase(col);
                    diagonal_1.erase(col + row);
                    diagonal_2.erase(col - row);
                }
            }
        };
        backtracking(0);
        return ans;
    }
};
