#include <functional>
#include <utility>
#include <vector>

/*
 * Goal: Change all surrounded regions of '0' to 'x'
 *
 * Intuition:
 * Graph Problem --> DFS / BFS
 * DFS implementation will be much more simpler
 * One key important observation is only cell that are not sides can be surrounded.
 * So what we can do is we can find those cannot be surrounded. We will traverse the sides only where it is '0'
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    void solve(std::vector<std::vector<char>> &board)
    {
        int ROWS(board.size()), COLS(board[0].size());

        std::function<void(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            board[row][col] = 'A';
            for (const auto &direction : DIRECTIONS)
            {
                int newRow{direction.first + row}, newCol{direction.second + col};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || board[newRow][newCol] != 'O')
                    continue;

                dfs(newRow, newCol);
            }
        };
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (board[i][j] == 'O' && (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1))
                    dfs(i, j);

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
            {
                if (board[i][j] == 'O')
                    board[i][j] = 'X';
                else if (board[i][j] == 'A')
                    board[i][j] = 'O';
            }
    }
};
