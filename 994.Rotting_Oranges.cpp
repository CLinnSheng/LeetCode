#include <deque>
#include <utility>
#include <vector>
/*
 * Goal: Return the minimum number of minutes that must elapse until there are zero fresh fruits remaining. If this
 * state is impossible within the grid, return -1.
 *
 * Intuition:
 * This is a graph problem. So if we compare bfs & dfs. BFS will be much more simplier.
 * We just have to bfs from the rotten fruits.
 * We also need to keep track of all the fruit as well because we only return the time if all fruit turn rotten
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int orangesRotting(std::vector<std::vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        // Store all the rotten fruit that gonna spread on the next wave
        std::deque<std::pair<int, int>> queue;

        int freshFruit{};
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
            {
                if (grid[i][j] == 1)
                    freshFruit++;
                else if (grid[i][j] == 2)
                    queue.emplace_back(i, j);
            }

        int time{};

        while (!queue.empty() && freshFruit > 0)
        {
            // Take note at the same time, every rotten fruit spread at the same time for the same wave
            int nRottenFruit(queue.size());

            while (nRottenFruit)
            {
                auto currCell{queue.front()};
                queue.pop_front();

                for (const auto &direction : DIRECTIONS)
                {
                    int newRow{direction.first + currCell.first}, newCol{direction.second + currCell.second};

                    if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || grid[newRow][newCol] != 1)
                        continue;

                    queue.emplace_back(newRow, newCol);
                    // Mark it so that we wont revisit again
                    grid[newRow][newCol] = 2;
                    freshFruit--;
                }
                nRottenFruit--;
            }

            time++;
        }
        return freshFruit == 0 ? time : -1;
    }
};
