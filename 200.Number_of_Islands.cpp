#include <functional>
#include <utility>
#include <vector>
/*
 * Find the number of islands
 * First this is a graph problem, dfs/bfs
 * Dfs will be much more simpler and we dont want to have dead cycle
 * So having an array to track the cells visited
 *
 * Time Complexity: O(n^2)
 * */
class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int numIslands(std::vector<std::vector<char>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();
        // std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        int island{};

        std::function<void(const int, const int)> dfs = [&](const int row, const int col) {
            // Mark visited
            grid[row][col] = '0';

            for (const auto &[x, y] : DIRECTIONS)
            {
                int new_row = row + y;
                int new_col = col + x;

                if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || grid[new_row][new_col] == '0')
                {
                    continue;
                }

                dfs(new_row, new_col);
            }
        };

        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (grid[row][col] == '1')
                {
                    island++;
                    dfs(row, col);
                }
            }
        }
        return island;
    }
};
