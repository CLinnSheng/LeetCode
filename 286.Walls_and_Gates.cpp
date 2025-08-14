#include <climits>
#include <deque>
#include <utility>
#include <vector>

/*
 * grid[i][j]:
 * 0 --> Treasure
 * -1 --> Water, cannot traverse
 * inf --> land cell that can traverse
 *
 * Goal: Fill each land cell with the distance to its nearest chest. If cannot reach then remain INF
 * NOTE: edit it inplace
 *
 *
 * Intuition:
 * This is a graph problem. Using bfs will be much more easier than using dfs
 * How can we handle so that we wont revist the same cell again? How do we manage different source to a destination and
 * choose which value? So to make thing easier we can bfs from the treasure, then simply take the previous cell value
 * + 1. And we only visit those cell with INF because visited cell wont be INF anymore
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    void islandsAndTreasure(std::vector<std::vector<int>> &grid)
    {
        std::deque<std::pair<int, int>> queue;
        int ROWS(grid.size()), COLS(grid[0].size());
        // Push all the treasures first
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (grid[i][j] == 0)
                    queue.emplace_back(i, j);

        while (!queue.empty())
        {
            auto top{queue.front()};
            queue.pop_front();

            for (const auto &direction : DIRECTIONS)
            {
                int newRow{direction.first + top.first}, newCol{direction.second + top.second};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || grid[newRow][newCol] != INT_MAX)
                    continue;

                grid[newRow][newCol] = std::min(grid[newRow][newCol], grid[top.first][top.second] + 1);
                queue.emplace_back(newRow, newCol);
            }
        }
    }
};
