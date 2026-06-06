#include <functional>
#include <string>
#include <utility>
#include <vector>

/*
 * Check whether we can find the word in the board or not
 * So this is also a decision tree problem at every index we choose it and then we check whether does it matches with
 * the current index, if yes we continue to saerch otherwise we backtrack and try other dircetion
 * So from here we know that backtrack is the algo to use
 *
 * At each cell we have 4 choices/directions to go
 * Time Complexity: O(m * 4^n) where m is the total number of cells
 * Space Complexity: O(n)
 * */

class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    bool exist(std::vector<std::vector<char>> &board, std::string word)
    {
        int ROW(board.size()), COL(board[0].size());

        // Track which cell we visited prevent looping
        std::vector<std::vector<bool>> visited(ROW, std::vector<bool>(COL, false));

        std::function<bool(const int, const int, const int)> backtrack = [&](const int index, const int row,
                                                                             const int col) {
            // Base Case
            if (index == word.length())
            {
                return true;
            }

            if (row < 0 || col < 0 || row >= ROW || col >= COL || visited[row][col] || word[index] != board[row][col])
            {
                return false;
            }

            visited[row][col] = true;

            for (const auto &[x, y] : DIRECTIONS)
            {
                int new_row = row + x;
                int new_col = col + y;

                if (backtrack(index + 1, new_row, new_col))
                {
                    return true;
                }
            }

            // Backtrack
            visited[row][col] = false;
            return false;
        };

        // Try every single cell as the starting
        for (int row{}; row < ROW; row++)
        {
            for (int col{}; col < COL; col++)
            {
                if (backtrack(0, row, col))
                {
                    return true;
                }
            }
        }

        return false;
    }
};
