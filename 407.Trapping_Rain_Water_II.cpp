#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * Given a 2d array representing the height of each unit cell in a 2d elevation map
 * Goal: Return the volume of water it can trap.
 *
 * Intuition: For the cell that can be trap by water it must be bounded.
 * So automatically the boundary of the grid are automatically neglected.
 * And then the amount of water trap is equal to the min height of the bounded cell.
 * So the boundary that bounded the cell must be at least heightMap[i] + 1 in order to trap the water.
 * There are some cases where:
 * 4 3 3 3
 * 5 2 1 3
 * 3 3 3 3
 * For eg: (1, 2) even though the minimum height bounded is 2 but actually we can fill it up until 3
 * How do we solve this, we can actually use a minHeap so we start to pour the water from the lower height first
 * Time Complexity: O(m*n lg(m*n))
 * Space Complexity: O(m*n)
 * */
class Solution
{
  public:
    int trapRainWater(std::vector<std::vector<int>> &heightMap)
    {
        int ROWS(heightMap.size()), COLS(heightMap[0].size());

        if (ROWS < 3 || COLS < 3)
            return 0;

        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;

        // we start to pour from the boundary
        // so fill up the minHeap with the boundary first
        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (i == 0 || i == ROWS - 1 || j == 0 || j == COLS - 1)
                {
                    visited[i][j] = true;
                    minHeap.push({heightMap[i][j], i, j});
                }

        const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int currMaxHeight{}, ttlRainWater{};

        while (!minHeap.empty())
        {
            const auto currCell{minHeap.top()};
            minHeap.pop();

            currMaxHeight = std::max(currMaxHeight, currCell[0]);

            for (const auto &direction : DIRECTIONS)
            {
                int nextRow{currCell[1] + direction.first}, nextCol{currCell[2] + direction.second};

                if (nextRow < 0 || nextCol < 0 || nextRow >= ROWS || nextCol >= COLS || visited[nextRow][nextCol])
                    continue;

                visited[nextRow][nextCol] = true;
                minHeap.push({heightMap[nextRow][nextCol], nextRow, nextCol});

                if (currMaxHeight > heightMap[nextRow][nextCol])
                    ttlRainWater += currMaxHeight - heightMap[nextRow][nextCol];
            }
        }
        return ttlRainWater;
    }
};
