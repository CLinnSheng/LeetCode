#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * Given a 2darray moveTime where moveTime[i][j] represent the minimum time in seconds
 * when you can start moving to that room
 *
 * Goal: Return the minimum time to reach the room(n-1, m-1)
 *
 * Intuition:
 * Keyword --> Minimum time
 * greedy --> dijkstra algorithm (no negative).
 *
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

        minTime[0][0] = moveTime[0][0]; // Start at the minimum time of the first cell
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

                int time = std::max(minTime[newRow][newCol], moveTime[newRow][newCol]) + 1;

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
