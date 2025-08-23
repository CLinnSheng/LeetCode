#include <array>
#include <climits>
#include <cmath>
#include <cstddef>
#include <queue>
#include <utility>
#include <vector>

/*
 * Goal: Return the minimum effort to travel from top left cell to the bottom right cell
 * Effort: Maximum absolute difference in heights between 2 consecutive cells
 *
 * Intuition:
 * Keyword "minimum" this lead us to think of solving it using dijkstra algorithm
 * Time Complexity: O(m*n lgmn)
 * */
class Solution
{
  private:
    static constexpr std::array<std::pair<int, int>, 4> DIRECTIONS{{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}};

  public:
    int minimumEffortPath(std::vector<std::vector<int>> &heights)
    {
        std::size_t ROWS{heights.size()}, COLS{heights[0].size()};
        // Base Case
        if (ROWS == 1 && COLS == 1)
            return 0;

        // Use a minHeap, so everytime we will pick the shortest option
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        minHeap.emplace(std::vector<int>{0, 0, 0}); // 0 -> distance, 1 -> row, 2 -> col

        // An array to store the current latest effort reach [i][j]
        std::vector<std::vector<int>> effort(ROWS, std::vector<int>(COLS, INT_MAX));

        while (!minHeap.empty())
        {
            auto currCell{minHeap.top()};
            minHeap.pop();

            auto currEffort{currCell[0]}, row{currCell[1]}, col{currCell[2]};

            if (row == ROWS - 1 && col == COLS - 1)
                return currEffort;

            // Prevent searching if we already traversed this node, as dijkstra algorithm
            // ensure the first visit is always the smallest
            if (currEffort > effort[row][col])
                continue;

            for (const auto &direction : DIRECTIONS)
            {
                auto newRow{direction.first + row}, newCol{direction.second + col};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS)
                    continue;

                auto newEffort{std::max(currEffort, std::abs(heights[newRow][newCol] - heights[row][col]))};

                if (newEffort >= effort[newRow][newCol])
                    continue;

                effort[newRow][newCol] = newEffort;
                minHeap.emplace(std::vector<int>{newEffort, newRow, newCol});
            }
        }

        return -1;
    }
};
