#include <algorithm>
#include <functional>
#include <utility>
#include <vector>
using std::vector;

/*
 * Goal: Return the maximum number of fish the fisher can catch if he chooses his starting cell optimally or 0 if no
 * water cell exists.
 *
 * Intuition:
 * Fisher can choose his starting cell optimally. So we need to trying every single cell as the starting cell
 * But do we really need to try out every single cell? Not really because we can travel to adjacent cell, so whichever
 * cell we travelled just mark it, so we dont have to repeat it Just use dfs to traverse through the grpah
 *
 * Time Complexity: O(m * n)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int findMaxFish(vector<vector<int>> &grid)
    {
        int answer{};

        std::function<int(const int &, const int &)> dfs = [&](const int &row, const int &col) {
            int fishes{grid[row][col]};
            // mark as visited
            grid[row][col] = 0;

            for (const auto &direction : DIRECTIONS)
            {
                int newRow{row + direction.first}, newCol{col + direction.second};
                if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() ||
                    grid[newRow][newCol] == 0)
                    continue;

                fishes += dfs(newRow, newCol);
            }
            return fishes;
        };

        for (int i{}; i < grid.size(); i++)
            for (int j{}; j < grid[0].size(); j++)
                if (grid[i][j])
                    answer = std::max(dfs(i, j), answer);

        return answer;
    }
};
