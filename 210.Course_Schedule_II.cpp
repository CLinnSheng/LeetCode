/*
 * Goal: Return the ordering of courses. IF it is impossible to finish all
 * courses means theres a cycle then return an empty array NOTE:
 * prerequisites[i] = [ai, bi] where ai is the course and bi is the prequisite
 * course
 *
 * Intuition: Since there is a connection between ai and bi, so we can draw a
 * graph from vertex a to vertex b for every single prerequisites. The reason
 * why a to b because we need b before a. So we will traverse all the way down
 * to the child node as this course is prerequisite of all the courses before
 * it. So we will insert it into the output. Use a set data structrue to store
 * all the courses that we visited and already confirm it wont produce a cyce,
 * so when we encounter a courses that require the same prerequisites course, we
 * dont have to traverse the graph again Use a set data strucutre to keep track
 * of the nodes currently visiting so that it wont produce a cycle. Time
 * Complexity: O(V + E) Space Complexity: O(V + E)
 */
#include <functional>
#include <unordered_set>
#include <vector>

class Solution {
public:
  std::vector<int> findOrder(int numCourses,
                             std::vector<std::vector<int>> &prerequisites) {

    std::unordered_set<int> visited_courses;
    std::unordered_set<int> check_cycles;

    // build an adjList
    std::vector<std::vector<int>> adjList(numCourses, std::vector<int>());

    for (const auto &courses : prerequisites)
      adjList[courses[0]].emplace_back(courses[1]);

    std::vector<int> ans;

    std::function<bool(const int &)> dfs = [&](const int &curr_node) {
      if (check_cycles.count(curr_node))
        return false;
      if (visited_courses.count(curr_node))
        return true;

      check_cycles.insert(curr_node);

      for (const auto &neigh : adjList[curr_node])
        if (!dfs(neigh))
          return false;

      check_cycles.erase(curr_node);
      visited_courses.insert(curr_node);
      ans.emplace_back(curr_node);

      return true;
    };

    for (int i = 0; i < numCourses; i++)
      if (!dfs(i))
        return {};

    return std::move(ans);
  }
};
