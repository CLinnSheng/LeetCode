#include <algorithm>
#include <functional>
#include <string>
#include <vector>
using std::string, std::vector;

/*
 * Given a string s, and an array of pairs of indices in the string pairs where
 * pairs[i] = [a, b] indicates 2 indices of the string
 * Operation: Can swap the characters at any pair of indices in the given pairs any number of times
 *
 * Goal: Return the lexicographically smallest string that s can be changed to after using the swaps.
 *
 * Intuition:
 * For indices that are not part of the graph, the value at the position is fix. So what we can change is those indices
 * in the pairs. We can treat the pairs as a graph. So what we can do is actually dfs all the connected pairs. So we got
 * all the values of the connected graphs. Then we just sort it. So when we traverse through the string s. Those values
 * that are exists in the graph, can be switching places no limit of time. So what we have to do is just place all the
 * component within the same graph according to the sorted list that we get from dfs
 *
 * Time Complexity:
 * Let n be the length of s and m is the length of pairs
 * So building adjList --> O(m)
 * DFS --> O(M + N)
 * Sorting --> O(NlgN)
 *
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        int len(s.length());
        if (len == 1)
            return s;

        vector<vector<int>> adjList(len, vector<int>());
        for (const auto &pair : pairs)
        {
            adjList[pair[0]].emplace_back(pair[1]);
            adjList[pair[1]].emplace_back(pair[0]);
        }

        vector<bool> visited(len, false);

        // track all the index/component of the connected graph
        vector<int> graphComponent;

        // track all the char value of the component of the graph
        string temp{};

        std::function<void(const int &)> dfs = [&](const int &currIndex) {
            // mark the current index as visited
            visited[currIndex] = true;
            graphComponent.emplace_back(currIndex);
            temp += s[currIndex];

            for (const auto &neigh : adjList[currIndex])
                if (!visited[neigh])
                    dfs(neigh);
        };
        // iterate through the array
        for (int i{}; i < len; i++)
        {
            // if the character is being visited through the dfs of the graph, then no point to check again because
            // is already place in the right places
            if (visited[i])
                continue;

            graphComponent.clear();
            temp.clear();

            dfs(i);

            // sort it because we want lexicographically, so at any random index we will place the smallest value
            // possible
            std::sort(temp.begin(), temp.end());
            std::sort(graphComponent.begin(), graphComponent.end());

            for (int j{}; j < graphComponent.size(); j++)
                s[graphComponent[j]] = temp[j];
        }
        return s;
    }
};
