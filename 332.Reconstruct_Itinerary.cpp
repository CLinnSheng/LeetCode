#include <algorithm>
#include <deque>
#include <functional>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * tickets[i] = [from_i, to_i].
 * Goal: Reconstruct the itinerary in order and return it
 * NOTE: All of the tickets originally departed from "JFK" & each ticket can only be used once
 * If exists multiple valid flight paths, take the lexicographically smallest one
 *
 * Intuition:
 * Must start from "JFK"
 * We can think this as a graph. Where the places is a node and the ticket is an edge.
 * So basically we can just dfs from JFK & and also need to sort the destinations
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets)
    {
        std::vector<std::string> answer{};
        std::unordered_map<std::string, std::deque<std::string>> adjList;

        for (const auto &ticket : tickets)
            adjList[ticket[0]].emplace_back(ticket[1]);

        // Sort the destinations, so that in lexicographically order
        // O(nlgn)
        for (auto &[source, dest] : adjList)
            std::sort(dest.begin(), dest.end());

        // O(n)
        std::function<void(const std::string &)> dfs = [&](const std::string &source) {
            while (!adjList[source].empty())
            {
                auto dest{adjList[source].front()};
                adjList[source].pop_front();
                dfs(dest);
            }
            answer.emplace_back(source);
        };

        dfs("JFK");
        std::reverse(answer.begin(), answer.end());
        return answer;
    }
};
