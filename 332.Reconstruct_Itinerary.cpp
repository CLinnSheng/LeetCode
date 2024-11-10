#include <algorithm>
#include <functional>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
 * Given a list of airline tickets where tickets[i] = [fromi, toi].
 * Goal: Reconstruct the itineray in order and return it in a string where every
 * ticket must use once and only once.
 *
 * Constraint: if multiple valid itinaries, return the 1 that has the smallest
 * lexical order eg: ["JFK", "LGA"] has a smaller lexical order than ["JFK",
 * "LGB"]
 *
 * Intuition:
 * Sort the tickets vector becuase we want to make sure we traverse the graph in
 * lexicograph order Just use dfs and backtracking
 *
 * Time Complexity: O(E*V) because at most possible got V^2 edges & backtracking
 * Space Complexity: O(E*V) recursive call stack
 * */
class Solution {
public:
  std::vector<std::string>
  findItinerary(std::vector<std::vector<std::string>> &tickets) {
    std::sort(tickets.begin(), tickets.end());
    std::unordered_map<std::string, std::vector<std::string>> adjList;

    for (const std::vector<std::string> ticket : tickets)
      adjList[ticket[0]].emplace_back(ticket[1]);

    std::vector<std::string> ans{"JFK"};

    std::function<bool(const std::string)> dfs_backtracking =
        [&](const std::string src) {
          if (ans.size() == tickets.size() + 1)
            return true;

          // if no ticket from this city
          if (!adjList.count(src))
            return false;

          std::vector<std::string> temp(adjList[src]);
          for (int i{}; i < temp.size(); i++) {
            std::string currCity{temp[i]};

            // dfs
            ans.emplace_back(currCity);
            adjList[src].erase(adjList[src].begin() + i);
            if (dfs_backtracking(currCity))
              return true;

            // backtracking
            ans.pop_back();
            adjList[src].insert(adjList[src].begin() + i, currCity);
          }
          return false;
        };
    dfs_backtracking("JFK");
    return std::move(ans);
  }
};
