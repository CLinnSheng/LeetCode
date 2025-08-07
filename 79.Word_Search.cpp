#include <functional>
#include <string>
#include <utility>
#include <vector>

/*
 * Goal: Return true if the word is present in the grid otherwise return false
 *
 * Intuition:
 * We can use dfs and backtracking. DFS on every index
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        int ROW(board.size()), COL(board[0].size());
        std::vector<std::vector<bool>> visited(ROW, std::vector<bool>(COL, false));

        if (word.length() == 0)
            return true;

        std::function<bool(const int &, const int &, const int &)> dfs_backtracking =
            [&](const int &row, const int &col, const int &index) {
                // Mark it first
                visited[row][col] = true;

                if (index < word.length() && board[row][col] != word[index])
                    return false;

                if (index == word.length() - 1)
                    return true;

                for (const auto &direction : DIRECTIONS)
                {
                    int newRow{direction.first + row};
                    int newCol{direction.second + col};

                    if (newRow < 0 || newCol < 0 || newRow >= ROW || newCol >= COL || visited[newRow][newCol])
                        continue;

                    if (dfs_backtracking(newRow, newCol, index + 1))
                        return true;

                    // false
                    // backtrack to try other path
                    visited[newRow][newCol] = false;
                }

                return false;
            };

        for (int r{}; r < ROW; r++)
            for (int c{}; c < COL; c++)
            {
                if (dfs_backtracking(r, c, 0))
                    return true;
                visited[r][c] = false;
            }
        return false;
    }
};
