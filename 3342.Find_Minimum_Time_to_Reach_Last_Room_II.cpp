#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * The same question as the I verison just with some modificatoin, where every time visit a new cell will be alternate
 * between 1 & 2 seconds
 *
 * Intuitoin:
 * Same use dijkstra & greedy algo.
 * And have a variable to track how much second to visit the cell.
 * Time Complexity: O(mn*lg(mn))
 * */

class Solution
{
  private:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int minTimeToReach(std::vector<std::vector<int>> &moveTime)
    {

        int m(moveTime.size()), n(moveTime[0].size());
        std::vector<std::vector<int>> minTime(m, std::vector<int>(n, INT_MAX));

        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                            std::greater<std::pair<int, std::pair<int, int>>>>
            minHeap;

        minTime[0][0] = 0; // Start at the minimum time of the first cell
        minHeap.push({minTime[0][0], {0, 0}});

        while (!minHeap.empty())
        {
            int currTime{minHeap.top().first};
            auto [currRow, currCol]{minHeap.top().second};
            minHeap.pop();

            if (currTime > minTime[currRow][currCol])
                continue;

            if (currRow == m - 1 && currCol == n - 1)
                return currTime;

            for (const auto &[r, c] : DIRECTIONS)
            {
                int newRow{currRow + r}, newCol{currCol + c};

                if (newRow < 0 || newCol < 0 || newRow >= m || newCol >= n)
                    continue;

                int time = std::max(currTime, moveTime[newRow][newCol]) + (currRow + currCol) % 2 + 1;

                if (time < minTime[newRow][newCol])
                {
                    minTime[newRow][newCol] = time;
                    minHeap.emplace(std::make_pair(minTime[newRow][newCol], std::make_pair(newRow, newCol)));
                }
            }
        }

        return -1;
    }
};
