#include <deque>
#include <utility>
#include <vector>

/*
 * 2d matrix. Most likely a graph problem
 * DFS/BFS
 * Start from the rotten fruit
 * BFS will be much more easier for this problem, as we can skip visiting the same cell
 * Time Complexity: O(m*n)
 * */

class Solution
{
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int time{};
        int rotten{}, fresh{};
        int ROWS = grid.size(), COLS = grid[0].size();

        // Store all the rotten fruit cell in a queue
        std::deque<std::pair<int, int>> queue;

        for (int row{}; row < grid.size(); row++)
        {
            for (int col{}; col < grid[0].size(); col++)
            {
                if (grid[row][col] == 1)
                {
                    fresh++;
                }

                if (grid[row][col] == 2)
                {
                    rotten++;
                    queue.emplace_back(row, col);
                }
            }
        }

        while (!queue.empty())
        {
            int n_rotten = queue.size();

            while (n_rotten)
            {
                auto currCell = queue.front();
                queue.pop_front();

                for (const auto &[_row, _col] : DIRECTIONS)
                {
                    int new_row = _row + currCell.first;
                    int new_col = _col + currCell.second;

                    if (new_row < 0 || new_col < 0 || new_row >= ROWS || new_col >= COLS || grid[new_row][new_col] != 1)
                    {
                        continue;
                    }

                    grid[new_row][new_col] = 2;
                    fresh--;
                    queue.emplace_back(new_row, new_col);
                }
                n_rotten--;
            }

            // Handle for edge cases where we dont have any more fresh orange left
            if (!queue.empty())
            {
                time++;
            }
        }

        return fresh == 0 ? time : -1;
    }
};
