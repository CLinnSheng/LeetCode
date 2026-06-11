#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Return all the possible solution to place n queens in a NxN board.
 * So in another way, it also means what is all the possible path.
 * Since finding all the possible path --> Backtracking
 * But we need to take care of how can we place the queen
 * Queen can go horizontally, vertically and diagonally.
 * So before placing each pieces we need to check every one of it
 * We can choose either iterate the rows/columns but it doesnt matter
 * The problem here is how can we check the diagonal or what value should we check if we store the placed queens
 * in a set or array.
 * If we take rows --> Then we only care about the `upper` left & right diagonal
 * Notice that (0,0) , (1,1), (2,2) & ... is the same
 * So we can come up with row - col and also row + col for each diagonal
 *
 * Time Complexity: O(n!)
 * Because at every row we only left with n - 1 column to place
 * Space Complexity: O(n^2)
 * */

class Solution
{
  public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> temp(n, std::string(n, '.'));
        std::unordered_set<int> cols, left_diagonals, right_diagonals;

        std::function<void(const int)> backtracking = [&](const int row) {
            if (row == n)
            {
                ans.push_back(temp);
                return;
            }

            // Try all possible columns
            for (int col{}; col < n; col++)
            {
                // Check whether is it safe to place or not
                if (!(cols.count(col) || left_diagonals.count(row - col) || right_diagonals.count(row + col)))
                {
                    // Place it
                    cols.insert(col);
                    left_diagonals.insert(row - col);
                    right_diagonals.insert(row + col);
                    temp[row][col] = 'Q';

                    backtracking(row + 1);

                    // Backtrack
                    cols.erase(col);
                    left_diagonals.erase(row - col);
                    right_diagonals.erase(row + col);
                    temp[row][col] = '.';
                }
            }
        };

        backtracking(0);
        return ans;
    }
};
