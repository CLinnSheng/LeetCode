#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
/*
 * At time t, water level is t, meaning any cell with elevation less than equal to t is submerged or reachable
 * Goal: Return the minimum time until you can reach bottom right square
 *
 * Intuition:
 * "minimum" time and water from higher can flow to lower level
 * and at any time the water can go infinite distance, so what really matters is the height.
 * so inorder to get into another cell of height "A" from a lower cell. The time needed will be A
 * We can use dijkstra algorithm to find we always search from least cell so whenever we reach the last cell, the t will
 * be the minimum
 * Time Complexity: O(N^2 log N) worst case need to traverse all cell
 * */

struct comparator
{
    bool operator()(const std::vector<int> &A, const std::vector<int> &B)
    {
        return A[0] > B[0];
    }
};
class Solution
{
  private:
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int swimInWater(std::vector<std::vector<int>> &grid)
    {
        int n(grid.size());

        std::vector<std::vector<bool>> visited(n, std::vector<bool>(n, false));
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, comparator> minHeap;

        // Time, Row, Column
        minHeap.emplace(std::vector<int>{grid[0][0], 0, 0});

        while (!minHeap.empty())
        {
            auto top{minHeap.top()};
            minHeap.pop();

            int time{top[0]}, row{top[1]}, col{top[2]};

            if (row == n - 1 && col == n - 1)
                return time;

            for (const auto &[dr, dc] : DIRECTIONS)
            {
                int newRow{row + dr}, newCol{col + dc};

                if (newRow < 0 || newRow >= n || newCol < 0 || newCol >= n || visited[newRow][newCol])
                    continue;

                visited[newRow][newCol] = true;
                minHeap.emplace(std::vector<int>{std::max(time, grid[newRow][newCol]), newRow, newCol});
            }
        }
        return -1;
    }
};
