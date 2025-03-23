#include <climits>
#include <cmath>
#include <queue>
#include <utility>
#include <vector>

/*
 * roads[i] = [ui, vi, timei]
 * Want to know in how mnay ways you can travel from intersection 0 to intersection n -1 in the shortest amount of time
 * Goal: Return the number of ways you can arrive at destination in the shortest amount of time.
 * NOTE: RETURN IT MODULO 10^9 + 7
 *
 * Intuition:
 * The first algo thats come into my mind is using dijkstra algo because of finding the shortest amount of time reaching
 * the destination Since from the question, it states that the answer may be very large. So if we simply just use
 * dijkstra algo sure TLE How can we optimize it? Instead of really going to traverse every single path what we can do
 * is caching. So if we want to go node n, to find the number of ways go to node n all we need to know how many ways can
 * i get to n - 1. So the number of ways reaching n will simply just the number of ways reaching n -1
 * So we need an array to track the number of paths can reach each node
 * Time Complexity: O((V+E)lgV)
 * */
class Solution
{
  public:
    struct Comparator
    {
        bool operator()(const std::pair<long long, int> &p1, const std::pair<long long, int> &p2)
        {
            return p1.first > p2.first;
        }
    };

    int countPaths(int n, std::vector<std::vector<int>> &roads)
    {
        // building the adjlist
        std::vector<std::vector<std::pair<int, int>>> adjList(n, std::vector<std::pair<int, int>>());
        for (const auto &road : roads)
        {
            adjList[road[0]].emplace_back(std::make_pair(road[1], road[2]));
            adjList[road[1]].emplace_back(std::make_pair(road[0], road[2]));
        }

        const int MOD(std::pow(10, 9) + 7);
        std::vector<int> pathCache(n, 0);
        std::vector<long long> minCost(n, LONG_LONG_MAX);

        std::priority_queue<std::pair<long, int>, std::vector<std::pair<long, int>>, Comparator> minHeap;
        minHeap.emplace(std::make_pair(0, 0));
        pathCache[0] = 1;

        // normal dijkstra algo
        while (!minHeap.empty())
        {
            auto [currCost, currNode]{minHeap.top()};
            minHeap.pop();

            for (const auto &[neigh, weight] : adjList[currNode])
            {
                if (currCost + weight < minCost[neigh])
                {
                    minCost[neigh] = currCost + weight;
                    pathCache[neigh] = pathCache[currNode];
                    minHeap.emplace(minCost[neigh], neigh);
                }
                else if (currCost + weight == minCost[neigh])
                    pathCache[neigh] = (pathCache[neigh] + pathCache[currNode]) % MOD;
            }
        }
        return pathCache[n - 1];
    }
};
