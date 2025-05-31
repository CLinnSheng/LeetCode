#include <algorithm>
#include <deque>
#include <numeric>
#include <utility>
#include <vector>

/*
 * Given a n x n board where the cells are labeled from 1 to n^2 starting from the bottom left.
 * At each step choose a destination square in the range [curr + 1, min(curr + 6, n^2)]
 * if 'next' has a snake or ladder must move to the destination of that snake or ladder. otherwise move to next
 * Game ends whenreach the square n^2
 *
 * boards[r][c] != -1 --> snake/ladder
 *
 * NOTE: Can only take snake/ladder at most once per dice roll. if the destination to a snake or ladder is the start of
 * another snake or ladder, do not follow the subsequent snake or ladder
 *
 * Goal: Return the least number of dice rolls required to reach the n^2
 * If not possible to reach the square, return -1.
 *
 * Constraint: 2 <= n <= 20
 * Intuitoin:
 * Basically we need to stimulate the process of playing the game.
 * The algo we can use is bfs since we need to find the minimum amount of dice rolls`` but need to handle cases on snake
 * and ladder. And also need to think a way of transforming this 2d cells to [1, n^2] And also need to think of a way to
 * determine we canoot reach n^2 Hmm for rolling the dice, since we can choose it is not exactly rng. So we will be
 * greedy try to get to ladder every move.
 * We need to take care of cycle as well because there might be a cycle
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * */
class Solution
{
  public:
    int snakesAndLadders(std::vector<std::vector<int>> &boards)
    {
        int n(boards.size());
        // Base Case can straight away reach
        if (n * n <= 6)
            return 1;

        // Change the 2d into a list according to the format
        int block{1};
        std::vector<std::pair<int, int>> flatboard(n * n + 1);
        std::vector<int> columns(n);
        std::iota(columns.begin(), columns.end(), 0);
        for (int i{n - 1}; i >= 0; i--)
        {
            for (const int &col : columns)
                flatboard[block++] = {i, col};

            std::reverse(columns.begin(), columns.end());
        }

        std::vector<int> distance(n * n + 1, -1);
        distance[1] = 0;
        std::deque<int> queue;
        queue.emplace_back(1);

        while (!queue.empty())
        {
            int currCell{queue.front()};
            queue.pop_front();

            for (int next{currCell + 1}; next <= std::min(currCell + 6, n * n); next++)
            {
                auto boardformat{flatboard[next]};
                int nextCell = boards[boardformat.first][boardformat.second] == -1
                                   ? next
                                   : boards[boardformat.first][boardformat.second];

                // Making sure there is no cycle
                if (distance[nextCell] == -1)
                {
                    distance[nextCell] = distance[currCell] + 1;
                    queue.emplace_back(nextCell);
                }
            }
        }

        return distance[n * n];
    }
};
