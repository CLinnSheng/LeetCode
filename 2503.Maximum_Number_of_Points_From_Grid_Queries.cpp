#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Find an array answer of size k such that each integer queries[i] you start in the top left then:
 * i. if queries[i] is strictly greater than the value of the curent cell, then get 1 point if first time visiting and
 * can move to adjacent cell in 4 directions ii. Othewise you don not get any points and end in this process.
 *
 * Intuition:
 * The brute force way will be going through each query and then do the graph traversal see how far can we go.
 * Can either use dfs/bfs
 * but this is not efficient, time complexity: O(q*m*n)
 *
 * How can we further optimize it?
 * If you observe, the number of points increases when the queries[i] value increases.
 * So what can we do is sort the queries so we start from the least value, and then the next value will just have to
 * start from those unvisited cell that is adjacent to the visited cell. Then we need to use bfs, so we can keep the
 * position/indices that the adjacent cell not visited yet.
 * So for the bfs instead of using queue, we can use priority queue or more specifically minHeap.
 * So we just need to compare to see whether can we traverse the min value in the queue or not.
 * If cannot just proceed to the next queries
 * Time Complexity: O(q*mnlgmn)
 * */
class Solution
{
  private:
    struct Comparator
    {
        bool operator()(const std::pair<int, std::pair<int, int>> &p1, const std::pair<int, std::pair<int, int>> &p2)
        {
            return p1.first > p2.first;
        }
    };

  public:
    const std::vector<std::pair<int, int>> DIRECTIONS{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    std::vector<int> maxPoints(std::vector<std::vector<int>> &grid, std::vector<int> &queries)
    {
        std::vector<int> answer(queries.size());
        std::vector<std::vector<bool>> visited(grid.size(), std::vector<bool>(grid[0].size(), false));
        visited[0][0] = true;

        int point{};
        std::priority_queue<std::pair<int, std::pair<int, int>>, std::vector<std::pair<int, std::pair<int, int>>>,
                            Comparator>
            minHeap;
        minHeap.emplace(std::make_pair(grid[0][0], std::make_pair(0, 0)));

        std::vector<std::pair<int, int>> queryIndex;
        for (int i{}; i < queries.size(); i++)
            queryIndex.push_back({queries[i], i});

        // sort the queries
        // O(qlgq)
        std::sort(queryIndex.begin(), queryIndex.end());

        for (const auto &[queryVal, queryIndex] : queryIndex) // O(q)
        {
            while (!minHeap.empty() && minHeap.top().first < queryVal) // O(mnlgmn)
            {
                point++;
                auto [_, coord]{minHeap.top()};
                minHeap.pop();

                for (const auto &dir : DIRECTIONS)
                {
                    int newRow{dir.first + coord.first}, newCol{dir.second + coord.second};

                    if (newRow < 0 || newCol < 0 || newRow >= grid.size() || newCol >= grid[0].size() ||
                        visited[newRow][newCol])

                        continue;

                    minHeap.emplace(std::make_pair(grid[newRow][newCol], std::make_pair(newRow, newCol)));
                    visited[newRow][newCol] = true;
                }
            }
            answer[queryIndex] = point;
        }
        return answer;
    }
};
