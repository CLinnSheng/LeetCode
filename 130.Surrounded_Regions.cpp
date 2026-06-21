#include <functional>
#include <utility>
#include <vector>
/*
 * Replace all the surrounded 'O' cell to 'X'
 * One important observation is the cell is surrounded if & only if none of the 'O' cells in that region are on the edge
 * of the board And must be completely enclosed by 'X' cells
 * Hence it is easier to saerch from the boundary, just dfs and replace all of it with a temp character to mark it not
 * replacable
 * */

class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    void solve(std::vector<std::vector<char>> &board)
    {
        int ROWS = board.size(), COLS = board[0].size();

        std::function<void(const int, const int)> dfs = [&](const int row, const int col) {
            board[row][col] = 'A';

            for (const auto &[_row, _col] : DIRECTIONS)
            {
                int new_row = row + _row;
                int new_col = col + _col;

                if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || board[new_row][new_col] != 'O')
                {
                    continue;
                }

                dfs(new_row, new_col);
            }
        };

        // Search from the boundary
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (board[row][col] == 'O' && ((row == 0 || row == ROWS - 1) || (col == 0 || col == COLS - 1)))
                {
                    dfs(row, col);
                }
            }
        }

        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (board[row][col] == 'O')
                {
                    board[row][col] = 'X';
                }
                if (board[row][col] == 'A')
                {
                    board[row][col] = 'O';
                }
            }
        }
    }
};
