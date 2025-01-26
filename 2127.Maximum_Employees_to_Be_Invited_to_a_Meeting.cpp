#include <algorithm>
#include <deque>
#include <functional>
#include <unordered_set>
#include <utility>
#include <vector>
using std::vector;

/*
 * Each employee has a favorite person and they will attend the meeting only if they can sit
 * next to their favorite person at the table.
 * Goal: Return the maximum number of employees that can be invited to the meeting.
 *
 * Intuition:
 * There are something we can deduce from the observation of the favorite edges.
 * There are n edges & n vertices, therefore there must be at least 1 cycle in the graph.
 * Since every vertices has only 1 outgoing edegs therefore at max we only have 1 cycle in the graph.
 * In order to find the maximumInvitations we need to find the longest chain we can find from the graph
 * and how do we solve for cyclic part? use an array to track those visited vertices, if visited that's mean
 * we are in a loop.
 *
 * However, there're 2 type of cycle.
 * 1. A closed cycle in the table which cannot be connected to other cycle. (n > 2)
 * 2. A non-closed cycle can be connected to other non-closed cycle. (n = 2)
 * */
class Solution
{
  public:
    int maximumInvitations(vector<int> &favorite)
    {
        int numberEmployee(favorite.size());
        std::vector<int> visit(numberEmployee, false);
        int longestCycle{};
        std::vector<std::pair<int, int>> cycleLen2;

        // 1. Find the longest cycle
        for (int i{}; i < numberEmployee; i++)
        {
            if (visit[i])
                continue;

            int start{i}, curr{i};
            // Have a different hash set, so we can easily to differentiate what are the current set and visited set
            std::unordered_set<int> currSet;

            // Finding the longest cycle in the graph
            while (!visit[curr])
            {
                visit[curr] = true;
                currSet.insert(curr);
                curr = favorite[curr];
            }

            // Check whether have we ever visited this set of vertices or not and also prevent looping
            // the cycle again
            if (currSet.count(curr))
            {
                int numberNodesInvolved(currSet.size());
                // finding the number of nodes in the cycle
                while (curr != start)
                {
                    numberNodesInvolved--;
                    start = favorite[start];
                }

                longestCycle = std::max(longestCycle, numberNodesInvolved);

                // In-case is a non closed cycle
                if (numberNodesInvolved == 2)
                    cycleLen2.emplace_back(curr, favorite[curr]);
            }
        }

        // 2. Finding the sum of the longest non closed circles.
        // we need to bfs from the cycle nodes of length 2
        std::vector<std::vector<int>> invertedGraph(numberEmployee);
        for (int i{}; i < numberEmployee; i++)
        {
            int src{favorite[i]}, dest{i};
            invertedGraph[src].emplace_back(dest);
        }

        std::function<int(const int &, const int &)> bfs = [&](const int &srcNode, const int &parentNode) {
            std::deque<std::pair<int, int>> queue;
            queue.emplace_back(srcNode, 0);
            int maxLength{};

            while (!queue.empty())
            {
                const auto [currNode, currLen] = queue.front();
                queue.pop_front();

                for (const auto &neigh : invertedGraph[currNode])
                    if (neigh != parentNode)
                        queue.emplace_back(neigh, currLen + 1);

                maxLength = std::max(maxLength, currLen);
            }
            return maxLength;
        };

        int chain2Sum{};
        for (const auto &[node1, node2] : cycleLen2)
            // chain2Sum = chain2Sum + is because of all those non closed cycle can be added together inside the table
            // 2 bfs function is because we want to traverse from each node
            // +2 is to involve the 2 nodes in the cycle
            chain2Sum += bfs(node1, node2) + bfs(node2, node1) + 2;

        return std::max(chain2Sum, longestCycle);
    }
};
