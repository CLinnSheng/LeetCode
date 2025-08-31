#include <vector>
/*
 * Intuition:
 * Just use dfs and backtracking
 * Time Complexity: (9^81)
 * Each cell has 9 choices and there is 81 cells
 * */
class Solution
{
  private:
    bool checkValid(std::vector<std::vector<char>> &board, const int row, const int col, const char val)
    {
        for (int i{}; i < 9; i++)
        {
            // Check Row
            if (board[row][i] == val)
                return false;

            if (board[i][col] == val)
                return false;

            if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == val)
                return false;
        }
        return true;
    }
    bool solve(std::vector<std::vector<char>> &board)
    {
        for (int i{}; i < 9; i++)
        {
            for (int j{}; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    for (char val{'1'}; val <= '9'; val++)
                    {
                        if (checkValid(board, i, j, val))
                        {
                            board[i][j] = val;
                            if (solve(board))
                                return true;
                            // backtracking
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

  public:
    void solveSudoku(std::vector<std::vector<char>> &board)
    {
        solve(board);
    }
};
