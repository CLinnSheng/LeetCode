#include <algorithm>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

/*
 * Given a 0-indexed array heights where heights[i] represents the height of the ith building
 * If a person is in building i, they can move to any other building j where i < j & heights[i] < heights[j]
 *
 * Another 2d array queries where queries[i] = [ai, bi] where Alice is in building ai while bob is in building bi
 * Goal: Return an array ans where ans[i] is the index of the leftmost building where Alice & Bob can meet on the ith
 * query. If alice & bob cannot move to a common building on query i. set answer[i] to -1
 *
 * Intuition:
 * Using naive approach to find the leftmost building starting from the max(index of alice, bob). This will be including
 * double for loop Time Compleixty: O(n^2)
 *
 * Is there any way to optimize this? maybe we can precompute the leftmost building for every single index where both
 * alice and bob can meet
 * we can actually precompute by grouping all those by using hash map & then use minHeap to solve it
 * then we can just solve it by iterate through the hieghts array
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */

struct comparator
{
    bool operator()(const std::pair<int, int> &a, const std::pair<int, int> &b)
    {
        return a.first > b.first;
    }
};

class Solution
{
  public:
    std::vector<int> leftmostBuildingQueries(std::vector<int> &heights, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> answer(queries.size(), -1);
        std::unordered_map<int, std::vector<std::pair<int, int>>> groups;

        for (int i{}; i < queries.size(); i++)
        {
            int a{queries[i][0]}, b{queries[i][1]};
            // we standardzie it by letting b has a greater index than a
            if (a > b)
                std::swap(a, b);

            // take note it only can jump if height[m] > height[i]
            if (a == b || heights[b] > heights[a])
                answer[i] = b;
            else
                groups[b].emplace_back(std::make_pair(std::max(heights[b], heights[a]), i));
        }

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, comparator> minHeap;
        for (int i{}; i < heights.size(); i++)
        {
            for (const auto &[height_, index] : groups[i])
                minHeap.emplace(std::make_pair(height_, index));

            while (!minHeap.empty() && minHeap.top().first < heights[i])
            {
                auto top{minHeap.top()};
                minHeap.pop();
                answer[top.second] = i;
            }
        }
        return answer;
    }
};
