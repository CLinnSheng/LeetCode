#include <algorithm>
#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::vector;

/*
 * Goal: Return the size of largest island.
 * NOTE: Allowed to change at most one 0 to 1.
 *
 * Intution: Just use dfs to find the biggest island and then turn.
 * Then for changing the water to land since we can only allow at most. What we can do is just try to find every single
 * water cell. And check the surrounding whether got land or not then we just combine the area. For combining the land,
 * we need to label the land so that we dont include the land more than 1 time in 4 direction. So just use a hash map to
 * label the land -> area and hash set to mark the visited land with their label
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * */
class Solution
{
  private:
    const vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool boundaryChecking(const int &row, const int &col, const int &n)
    {
        return (row < 0 || col < 0 || row >= n || col >= n);
    }

    int dfs(const int &row, const int &col, const int &label, vector<vector<int>> &grid, const int &n)
    {
        if (boundaryChecking(row, col, n) || grid[row][col] != 1)
            return 0;

        int size{1};
        grid[row][col] = label;

        for (const auto &direction : DIRECTIONS)
            size += dfs(direction.first + row, direction.second + col, label, grid, n);

        return size;
    }

  public:
    int largestIsland(vector<vector<int>> &grid)
    {
        int n(grid.size());

        // use a hash map to label each individual island
        // precompute the area of each individual island
        std::unordered_map<int, int> islandArea;
        // we need label because we need try to flip the water later as a label so we dont confuse ourself
        int label{2}, maxArea{};

        for (int r{}; r < n; r++)
            for (int c{}; c < n; c++)
                if (grid[r][c] == 1)
                {
                    islandArea[label] = dfs(r, c, label, grid, n);
                    maxArea = std::max(maxArea, islandArea[label]);
                    label++;
                }

        // now we try to flip the water
        std::function<int(const int &, const int &)> connect = [&](const int &row, const int &col) {
            std::unordered_set<int> visit;
            int res{};

            for (const auto &direction : DIRECTIONS)
            {
                int newR{row + direction.first}, newC{col + direction.second};
                if (!boundaryChecking(newR, newC, n) && visit.count(grid[newR][newC]) == 0)
                {
                    res += islandArea[grid[newR][newC]];
                    visit.insert(grid[newR][newC]);
                }
            }

            return res;
        };

        for (int r{}; r < n; r++)
            for (int c{}; c < n; c++)
                if (!grid[r][c])
                    maxArea = std::max(maxArea, connect(r, c));
        return maxArea;
    }
};
