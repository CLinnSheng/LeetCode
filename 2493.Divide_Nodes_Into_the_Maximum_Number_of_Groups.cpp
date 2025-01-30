#include <algorithm>
#include <cstdlib>
#include <deque>
#include <numeric>
#include <vector>
using std::vector;

/*
 * n - number of nodes
 * edges where edges[i] = [ai, bi] there is a bidirectional edge between node ai & bi.
 * IMPORTANT: The given graph may be disconnected.
 *
 * Divide the nodes into m groups such that:
 * Each node in the graph belongs to exactly one group
 * Every pair of nodes in the graph that are connected by an edge, if ai belongs to the group with index m & bi belongs
 * to the group with index y, then |y - x| = 1 Goal: Return the maximum number of groups or else return -1 if cannot be
 * group under those conditions
 *
 * Intuition:
 * We need to find all the connected components in the graph. Not all nodes is connected.
 * So we need to find out the number of groups from each group then sum it up.
 * And also make sure the gouoping follow the condition.
 * We need to maximize the number of group also
 * What we can try to do bfs from every single node.
 * Time Complexity: O(V + E) Exploring every single node
 * */
class Solution
{
  public:
    int magnificentSets(int n, vector<vector<int>> &edges)
    {
        // build adj list
        vector<vector<int>> adjList(n, vector<int>());
        for (const auto &edge : edges)
        {
            adjList[edge[0] - 1].emplace_back(edge[1] - 1);
            adjList[edge[1] - 1].emplace_back(edge[0] - 1);
        }

        vector<int> distance(n, 0);
        // perform bfs from every single node to find the maximum number of group can be divided
        for (int startNode{}; startNode < n; startNode++)
        {
            std::deque<int> queue{startNode};
            vector<int> pathDistance(n, 0);
            pathDistance[startNode] = 1;
            // we use rootNode just to simplify things for updating
            int maxDistance{1}, rootNode{startNode};

            while (!queue.empty())
            {
                int currNode{queue.front()};
                queue.pop_front();
                rootNode = std::min(rootNode, currNode);

                for (const auto &neigh : adjList[currNode])
                {
                    // havent visited yet
                    if (pathDistance[neigh] == 0)
                    {
                        pathDistance[neigh] = pathDistance[currNode] + 1;
                        maxDistance = std::max(maxDistance, pathDistance[neigh]);
                        queue.emplace_back(neigh);
                    }
                    // checking whether does it meet the condition or not
                    else if (std::abs(pathDistance[neigh] - pathDistance[currNode]) != 1)
                        return -1;
                }
            }
            distance[rootNode] = std::max(distance[rootNode], maxDistance);
        }
        // accumulate is because some of the nodes are disconnected
        return std::accumulate(distance.begin(), distance.end(), 0);
    }
};
