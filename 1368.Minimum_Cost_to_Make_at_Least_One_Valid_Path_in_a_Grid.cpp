#include <climits>
#include <deque>
#include <vector>

/*
 * Sign of grid[i][j] can be (1, 2, 3, 4) each stands for different directions
 * Initially start at [0][0] and ends at[m - 1][n -1].
 * Able to modify the sign of a cell with cost of 1.
 *
 * Goal: Return the minimum cost to make the grid have at least oen valid path.
 *
 * Intuition:
 * According to the question, we actually finding the minimum cost but not the shortest path.
 * The first thought will be using a priority queue and always pop the 1 with lowest cost first but since
 * we are not interested on the path with the shortest length. Is ok to get found a valid path which are longer
 * as long as it is the minimum cost because without using priority queue we can save a time complexity of O(lgn)
 * We can use bfs & deque because we are able to access the array in both directions, so everytime we will access the 1
 * with the least cost first Every time we visit a new cell we will add to the front if no added cost otherwise to the
 * back. To make sure we keep searching from the least cost first
 *
 * Time Complexity: O(m*n)
 * Space Complexity: O(m*n)
 * */
class Solution
{
  private:
    // According to the question given
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

  public:
    int minCost(std::vector<std::vector<int>> &grid)
    {
        int ROWS(grid.size()), COLS(grid[0].size());
        std::vector<std::vector<int>> costGrid(ROWS, std::vector<int>(COLS, INT_MAX));
        std::deque<std::vector<int>> queue;
        queue.push_back({0, 0, 0});

        // bfs
        while (!queue.empty())
        {
            auto currentPosition{queue.front()};
            queue.pop_front();

            int currentRow{currentPosition[0]}, currentCol{currentPosition[1]}, currentCost{currentPosition[2]};

            if (currentRow == ROWS - 1 && currentCol == COLS - 1)
                return currentCost;

            // try to walk in 4 directions
            for (int i{}; i < 4; i++)
            {
                int nextRow{currentRow + DIRECTIONS[i].first}, nextCol{currentCol + DIRECTIONS[i].second};

                bool addedCost{grid[currentRow][currentCol] == i + 1 ? false : true};
                int nextCost{currentCost + (addedCost ? 1 : 0)};

                // check whether got out of bound or not
                // also check whether have we either process this cell before
                // if processed and the current stored cost is lesser then dun bother to rewrite it and also prevent
                // duplicate nextCell to travel in the queue
                if (nextRow < 0 || nextCol < 0 || nextRow >= ROWS || nextCol >= COLS ||
                    nextCost >= costGrid[nextRow][nextCol])
                    continue;

                // update with the shortest cost
                costGrid[nextRow][nextCol] = nextCost;

                // check append on the front or back
                if (addedCost)
                    queue.push_back({nextRow, nextCol, nextCost});
                else
                    queue.push_front({nextRow, nextCol, nextCost});
            }
        }
        return -1;
    }
};
