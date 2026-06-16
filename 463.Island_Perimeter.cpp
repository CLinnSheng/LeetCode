#include <functional>
#include <utility>
#include <vector>

/*
 * Only exactly one island
 * Goal: Find the perimeter of the island
 *
 * Intuition:
 * This is a grpah problem so we can simply use dfs
 * Since there is only one island we just have to dfs once. And we use an array to keep track of the cell we visited
 * And how do we handle the perimeter? If we notice the exmaple given the perimeter is only added when it is out of
 * bound
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        int perimeter{};
        int ROWS = grid.size(), COLS = grid[0].size();
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::function<int(const int, const int)> dfs = [&](const int row, const int col) {
            // Check boundary
            if (row < 0 || col < 0 || row >= ROWS || col >= COLS || grid[row][col] == 0)
            {
                return 1;
            }

            if (visited[row][col])
            {
                return 0;
            }

            // mark visit
            visited[row][col] = true;

            int perimeter{};

            for (const auto direction : DIRECTIONS)
            {
                perimeter += dfs(row + direction.first, col + direction.second);
            }

            return perimeter;
        };

        for (int row{}; row < ROWS; row++)
        {
            for (int col{}; col < COLS; col++)
            {
                if (grid[row][col])
                {
                    return dfs(row, col);
                }
            }
        }
        return -1;
    }
};
