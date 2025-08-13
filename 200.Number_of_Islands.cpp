#include <functional>
#include <utility>
#include <vector>

/*
 * Goal: Find the number of islands.
 * An islands is formed by connecting adjacent lands horizontally or vertically
 *
 * Intuition:
 * We can just simply dfs and mark those cells we visited so that we wont visited again
 * Time Complexity: O(n^2)
 * */

class Solution
{
  public:
    const std::vector<std::pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        int ans{};

        std::function<void(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            // mark
            visited[row][col] = true;

            for (const auto &direction : DIRECTIONS)
            {
                int newRow{direction.first + row}, newCol{direction.second + col};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || grid[newRow][newCol] == '0' ||
                    visited[newRow][newCol])
                    continue;

                dfs(newRow, newCol);
            }
        };

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (grid[i][j] == '1' && !visited[i][j])
                {
                    ans++;
                    dfs(i, j);
                }
        return ans;
    }
};
