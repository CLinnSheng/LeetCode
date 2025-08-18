#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Check every single query whether queries[uj, kj] course uj is a prerequisite course of kj
 *
 * Intuition:
 * The brute force way will be iterating through every single queries then just dfs through to check whether is it a
 * prerequisite or not Time Complexity: O(V + E) * m
 *
 * If we notice from the brute force, we actually solved some subproblem multiple times.
 * How can we optimize it? Caching
 * Time Complexity: O(V +E + m)
 * */
class Solution
{
  public:
    std::vector<bool> checkIfPrerequisite(int numCourses, std::vector<std::vector<int>> &prerequisites,
                                          std::vector<std::vector<int>> &queries)
    {
        std::vector<std::vector<int>> adjList(numCourses);
        std::unordered_map<int, std::unordered_set<int>> caching;

        for (const auto &edge : prerequisites)
            adjList[edge[0]].emplace_back(edge[1]);

        std::vector<bool> answer;

        // std::function<bool(const int &, const int &)> dfs = [&](const int &currCourse, const int &targetCourse) {
        //     if (currCourse == targetCourse)
        //         return true;
        //
        //     for (const auto &pre : adjList[currCourse])
        //         if (dfs(pre, targetCourse))
        //             return true;
        //     return false;
        // };

        // for (const auto &query : queries)
        //     answer.emplace_back(dfs(query[0], query[1]));

        std::function<std::unordered_set<int>(const int &)> dfs = [&](const int &currCourse) {
            // If already traverse before
            if (caching.find(currCourse) != caching.end())
                return caching[currCourse];

            caching[currCourse] = std::unordered_set<int>();

            for (const auto &course : adjList[currCourse])
            {
                auto allPreqCourses{dfs(course)};
                caching[currCourse].insert(allPreqCourses.begin(), allPreqCourses.end());
            }

            // Include itself becaues we returning to the parent course
            caching[currCourse].insert(currCourse);
            return caching[currCourse];
        };
        for (int i{}; i < numCourses; i++)
            dfs(i);
        for (const auto &query : queries)
            answer.emplace_back(caching[query[0]].find(query[1]) != caching[query[0]].end());
        return answer;
    }
};
