#include <functional>
#include <vector>

/*
 * Given a 2d array which representing a map where grid[i][j] = 1 -> land while 0 -> water
 * Goal: Return the island perimeter.
 *
 * Intuition:
 * We can just simply use dfs to find all the connected island.
 * But the problem is how to find out the perimeter of a specific cell in the island
 * Observe the pattern if we are able to traverse from this cell to another from a direction then the part is not
 * counted. So whenever we couldnt traverse from the side we just count the perimter Time Complexity: O(m*n) Space
 * Complexity: O(m*n)
 * */

class Solution
{
  public:
    int islandPerimeter(std::vector<std::vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));

        std::function<int(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            // Base Cases
            // Becase we are not able to traverse from it so this side is counted into the perimetr
            if (row < 0 || col < 0 || row >= ROWS || col >= COLS || grid[row][col] == 0)
                return 1;

            if (visited[row][col])
                return 0;

            // mark as visited
            visited[row][col] = true;

            // traverse from 4 all possible directions
            return dfs(row + 1, col) + dfs(row - 1, col) + dfs(row, col + 1) + dfs(row, col - 1);
        };

        // to find out the first piece of land we can start
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (grid[i][j])
                    return dfs(i, j);
        return 0;
    }
};
