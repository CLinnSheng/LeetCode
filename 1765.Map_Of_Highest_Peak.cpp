#include <functional>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

/*
 * given a 2d matrix isWater where isWater[i][j] = 0 -> land otherwise isWater[i][j] = 1 -> water
 * Must assign each cell a height by following these rules:
 * i. Height of each cell must be non-negative
 * ii. if the cell is a water cell, its height must be 0
 * iii. Any 2 adjacent cells must have an absolulte heigh difference of at most 1.
 * Goal: Find an assignment of heights such that the maximum height in the matrix is maximized.
 *
 * Intuition:
 * We need to start from the water so this lead us have the thought of using a priority queue.
 * So that every time we add from the cell that has the lowest value first
 * Time Complexity: O(m*n lg m*n)
 * Space Complexity: O(m*n)
 * */

class Solution
{
  public:
    vector<vector<int>> highestPeak(vector<vector<int>> &isWater)
    {
        int ROWS(isWater.size()), COLS(isWater[0].size());

        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> minHeap;
        std::vector<std::vector<int>> answer(ROWS, std::vector<int>(COLS, -2));

        for (int i{}; i < ROWS; i++)
            for (int j{}; j < COLS; j++)
                if (isWater[i][j])
                {
                    answer[i][j] = 0;
                    minHeap.push({0, i, j});
                }

        const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        // bfs & minHeap
        while (!minHeap.empty())
        {
            const auto currCell{minHeap.top()};
            minHeap.pop();

            for (const auto &direction : DIRECTIONS)
            {
                int newRow{currCell[1] + direction.first}, newCol{currCell[2] + direction.second};

                if (newRow < 0 || newCol < 0 || newRow >= ROWS || newCol >= COLS || answer[newRow][newCol] != -2)
                    continue;

                answer[newRow][newCol] = currCell[0] + 1;
                minHeap.push({answer[newRow][newCol], newRow, newCol});
            }
        }
        return answer;
    }
};
