#include <functional>
#include <numeric>
#include <vector>
/*
 * Stations are interconnected via n bidirectional cables. connections[i] =[ui, vi]
 * Initially all are online
 * queries[i] = [1, x]
 * - Maintenance check for station x, if x is online, resolves the check by itself. If x is offline
 *   the check is resolved by the operational station with the smallest id in the same power grid as x. If no return -1.
 * Goal: Return an array representing the results of each query
 * queries[i] = [2, x]
 * - x goes offline
 *
 * Intuition:
 * - This is a graph problem where each station is connected to one another.
 *   So we can use union find set to find the station that connected to one another and then maintain a linked list
 * within the component it self
 *
 * Time Complexity: O(n + q)
 * - Initialization of the union find set
 * - Iterating through the queries
 * - Find parent --> Path Compression
 * */
class Solution
{
  public:
    std::vector<int> processQueries(int c, std::vector<std::vector<int>> &connections,
                                    std::vector<std::vector<int>> &queries)
    {
        std::vector<int> parents(c + 1);
        std::iota(parents.begin(), parents.end(), 0);

        std::function<int(int)> findParent = [&](int x) {
            if (parents[x] != x)
            {
                parents[x] = findParent(parents[x]);
            }
            return parents[x];
        };

        // Create the union component
        for (const auto &conn : connections)
        {
            int u = findParent(conn[0]);
            int v = findParent(conn[1]);
            if (u != v)
            {
                parents[u] = v;
            }
        }

        // Linked list for each component
        std::vector<int> nextNode(c + 1, 0), closestNode(c + 1, 0), lastNode(c + 1, 0);
        for (int i{1}; i <= c; i++)
        {
            int u = findParent(i);
            if (closestNode[u] == 0)
            {
                // Closest Station mean the station with smallest index id
                // So will just simply be 'i'
                closestNode[u] = i;
            }
            else
            {
                // Update i as the last node of the current last node in the current component
                nextNode[lastNode[u]] = i;
            }
            // Update i as the last node of the current component
            lastNode[u] = i;
        }

        std::vector<int> result;
        std::vector<bool> offline(c + 1, false);
        for (const auto &query : queries)
        {
            int type = query[0], x = query[1];

            // Maintenance
            if (type == 1)
            {
                // Check x is online or not
                if (!offline[x])
                {
                    result.emplace_back(x);
                }
                else
                {
                    // offline. Find the closest station
                    int u = findParent(x);
                    result.emplace_back(closestNode[u] ? closestNode[u] : -1);
                }
            }
            else
            {
                // Only do operation if x is online
                if (!offline[x])
                {
                    offline[x] = true;

                    // Then need to update the closest node
                    int u = findParent(x);

                    if (closestNode[u] == x)
                    {
                        // need to update closestNode[u] to nextNode[x]
                        int next = nextNode[x];
                        while (next && offline[next])
                        {
                            next = nextNode[next];
                        }

                        closestNode[u] = next ? next : 0;
                    }
                }
            }
        }

        return result;
    }
};
