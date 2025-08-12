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
 *
 * Time Complexity: O(m * n)
 * */
class Solution
{
  private:
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::function<int(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            // Base Case, cannot traverse only return the side length other wise is 0
            if (row < 0 || col < 0 || row >= ROWS || col >= COLS || grid[row][col] == 0)
                return 1;

            if (visited[row][col])
                return 0;

            // Mark as visited
            visited[row][col] = true;

            int answer{};

            for (const auto &direction : DIRECTIONS)
                answer += dfs(row + direction.first, col + direction.second);

            return answer;
        };
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (grid[i][j])
                    return dfs(i, j);
        return -1;
    }
};
