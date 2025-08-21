#include <deque>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using std::vector, std::string;

/*
 * equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]
 * queries[i] = [Cj, Dj], task is to find answer for Cj / Dj
 * Goal: Return answer to all queries
 *
 * Intuition:
 * Queries might contain variable that never appear in the equations
 * Eg:
 * equations = [["a","b"],["b","c"],["ab","bc"]], values = [4.0,1.0,3.25], queries =
 * [["a","c"],["b","a"],["c","c"],["ab","a"],["d","d"]]
 * How can find first query, a / c? is actually equal to a /b * b / c
 * From here we can actually see the way we compute is just keep times with all the values we have, so is kinda like a
 * graph problem. Where every single node means is a division of something
 * Time Complexity: O(m*n)
 * */
class Solution
{
  private:
    double bfs(const string source, const string target,
               std::unordered_map<string, vector<std::pair<string, double>>> &adj)
    {
        // Check whether we have this variable or not
        if (adj.find(source) == adj.end() || adj.find(target) == adj.end())
            return -1;

        if (source == target)
            return 1;

        std::deque<std::pair<string, double>> queue;
        queue.emplace_back(source, 1);

        std::unordered_set<string> visited;

        while (!queue.empty())
        {
            auto top{queue.front()};
            queue.pop_front();

            if (top.first == target)
                return top.second;

            for (const auto &[neigh, neighWeight] : adj[top.first])
            {
                if (visited.find(neigh) == visited.end())
                {
                    visited.insert(neigh);
                    queue.emplace_back(neigh, neighWeight * top.second);
                }
            }
        }

        return -1;
    }

  public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values,
                                vector<vector<string>> &queries)
    {
        std::unordered_map<string, vector<std::pair<string, double>>> adj;
        for (int i{}; i < equations.size(); i++)
        {
            // First one
            adj[equations[i][0]].emplace_back(equations[i][1], values[i]);
            // Second one
            adj[equations[i][1]].emplace_back(equations[i][0], 1.0 / values[i]);
        }

        // Can be dfs or bfs
        // but bfs will be simplier
        vector<double> answer;
        for (const auto &query : queries)
            answer.emplace_back(bfs(query[0], query[1], adj));

        return answer;
    }
};
