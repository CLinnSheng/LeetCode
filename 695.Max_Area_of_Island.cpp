#include <functional>
#include <vector>

/*
 * Goal: Find the maximum area of island
 *
 * Intuition:
 * We can just simply traverse the graph and mark it so that we wont revisit again
 * Time Complexity: O(m * n)
 * */
class Solution
{
  public:
    const std::vector<std::pair<int, int>> DIRECTIONS = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid)
    {
        int answer{};
        int ROWS(grid.size()), COLS(grid[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::function<int(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            if (row < 0 || col < 0 || row >= ROWS || col >= COLS || visited[row][col] || !grid[row][col])
                return 0;

            visited[row][col] = true;
            int area{1};

            for (const auto &direction : DIRECTIONS)
            {
                int newRow{direction.first + row}, newCol{direction.second + col};
                area += dfs(newRow, newCol);
            }
            return area;
        };
        for (int row{}; row < ROWS; row++)
            for (int col{}; col < COLS; col++)
                if (grid[row][col] && !visited[row][col])
                    answer = std::max(answer, dfs(row, col));
        return answer;
    }
};
