#include <functional>
#include <utility>
#include <vector>
/*
 * Find the maximum area of island
 * Traverse the grid, and do dfs when we found land and mark visited to prevent revisit
 * DFS/BFS for searching through grid --> Graph
 * Use dfs much more simpler
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int ans{};
        int ROWS = grid.size(), COLS = grid[0].size();

        std::function<int(const int, const int)> dfs = [&](const int row, const int col) {
            // Mark visited
            grid[row][col] = 0;
            int area{1};

            for (const auto &[y, x] : DIRECTIONS)
            {
                int new_row = row + y;
                int new_col = col + x;

                if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || grid[new_row][new_col] == 0)
                {
                    continue;
                }

                area += dfs(new_row, new_col);
            }
            return area;
        };

        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (grid[row][col])
                {
                    ans = std::max(ans, dfs(row, col));
                }
            }
        }

        return ans;
    }
};
