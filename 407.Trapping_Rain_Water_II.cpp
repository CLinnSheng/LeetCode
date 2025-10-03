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
 * How do we solve this, we can actually use a minHeap so we start to pour the water from the lower height first and
 * boundary Time Complexity: O(m*n lg(m*n)) Space Complexity: O(m*n)
 * */
class Solution
{
  public:
    std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int trapRainWater(std::vector<std::vector<int>> &heightMap)
    {
        int ROWS(heightMap.size()), COLS(heightMap[0].size());

        std::vector<std::vector<bool>> visited(ROWS, std::vector<bool>(COLS, false));
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;

        // Push all the boundary to the minheap
        for (int row{}; row < ROWS; row++)
            for (int col{}; col < COLS; col++)
                if (row == 0 || col == 0 || row == ROWS - 1 || col == COLS - 1)
                {
                    minHeap.emplace(std::vector<int>{heightMap[row][col], row, col});
                    visited[row][col] = true;
                }

        // Now we flow from the minHeight first, so we can solve the issues of having a height
        int maxHeight{}, answer{};

        while (!minHeap.empty())
        {
            auto currCell = minHeap.top();
            minHeap.pop();

            maxHeight = std::max(maxHeight, currCell[0]);

            for (const auto direction : DIRECTIONS)
            {
                int newRow{direction.first + currCell[1]}, newCol{direction.second + currCell[2]};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || visited[newRow][newCol])
                    continue;

                if (maxHeight > heightMap[newRow][newCol])
                    answer += maxHeight - heightMap[newRow][newCol];

                // Push it into the heap because there might be cell bounded by these cells
                minHeap.emplace(std::vector<int>{heightMap[newRow][newCol], newRow, newCol});
                visited[newRow][newCol] = true;
            }
        }
        return answer;
    }
};
