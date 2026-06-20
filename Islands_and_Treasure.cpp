
#include <climits>
#include <deque>
#include <utility>
#include <vector>

/*
 * Find the distance of each cell to its nearest treasure chest
 * Graph Problem since given a 2d matrix (Most likely)
 * DFS/BFS
 * Brute force solution will be BFS on each land cell
 * Instead of thinking finding the treasure chest, why dont we do it reverse and visit all the land cell?
 * This will be nuch more easier, and need to handle revisit the same cell again
 * Time Complexity: O(m*n)
 * */

class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

  public:
    void islandsAndTreasure(std::vector<std::vector<int>> &grid)
    {
        int ROWS = grid.size(), COLS = grid[0].size();

        // Push all the treasure into the queue
        std::deque<std::pair<int, int>> queue;
        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (grid[row][col] == 0)
                {
                    queue.emplace_back(row, col);
                }
            }
        }

        // Start BFS from the treasure
        while (!queue.empty())
        {
            auto top = queue.front();
            queue.pop_front();

            for (const auto &[_col, _row] : DIRECTIONS)
            {
                int new_row = _row + top.first;
                int new_col = _col + top.second;

                if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS ||
                    grid[new_row][new_col] != INT_MAX)
                {
                    continue;
                }

                grid[new_row][new_col] = std::min(grid[new_row][new_col], grid[top.first][top.second] + 1);
                queue.emplace_back(new_row, new_col);
            }
        }
    }
};
