#include <functional>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;

/*
 * Total of numCourses have to take from 0 to numCourses - 1.
 * Given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course ai first if you
 * want to take course bi.
 * prerequisites can be indirect. eg: a is the prerequisite of course b, and course b is a prequisite of course c,
 * then a is the prerequisites of course c.
 * queries[j] = [uj, vj]. For the jth query, answer whether course uj is a prerequisite of course vj or not.
 * Goal: Return a boolean array where answer[j] is the answer to the jth query.
 *
 * Intuition:
 * This is a graph problem, we can simply just use dfs to search from the prerequisites courses to the target courses
 * if we able to reach means the query is true. This is actually a brute force way.
 * Time Complexity: O(V + E) * m
 *
 * The way we can optimize this is through memoziation because from the brute force way, we
 * can see there is actually lots of overlapping of subproblem. So we can optimize it through caching or dp or
 * memoziatinon.
 *
 * Another way is actually using hash map and hash set. We would like to store all the prerequisites courses of A in a
 * hash set while traversing the graph
 *
 * */
class Solution
{
  private:
    std::unordered_set<int> &dfs(const int &course, std::unordered_map<int, std::unordered_set<int>> &prereqMap,
                                 const vector<vector<int>> &adjList)
    {
        // if already populate the current course just return it
        if (prereqMap.count(course))
            return prereqMap[course];

        prereqMap[course] = std::unordered_set<int>();
        for (const auto &preq : adjList[course])
        {
            auto &allpreqCourse = dfs(preq, prereqMap, adjList);
            prereqMap[course].insert(allpreqCourse.begin(), allpreqCourse.end());
        }

        // need to include the current course because we return to the parent course
        prereqMap[course].insert(course);
        return prereqMap[course];
    }

  public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>> &prerequisites, vector<vector<int>> &queries)
    {
        // build an adjList
        vector<vector<int>> adjList(numCourses, std::vector<int>());

        for (const auto &prerequisite : prerequisites)
        {
            auto course{prerequisite[1]};
            auto prereqCourse{prerequisite[0]};

            adjList[course].emplace_back(prereqCourse);
        }

        std::unordered_map<int, std::unordered_set<int>> prereqMap;
        for (int i{}; i < numCourses; i++)
            dfs(i, prereqMap, adjList);

        vector<bool> answer;
        for (int i{}; i < queries.size(); i++)
            answer.emplace_back((prereqMap[queries[i][1]].count(queries[i][0])) ? true : false);

        return answer;
    }
};
