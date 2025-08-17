#include <functional>
#include <vector>

/*
 * prerequisites[i] = [ai, bi] where u must take course b before course a
 * Goal: Return true if possible to finish all course.
 *
 * Intuition:
 * From one of the example [1, 0], [0, 1]. We can see this 2 course is depends on one another.
 * So we can treat each course as a node and build a graph on it.
 * So if we have cycle in a graph means that some of the courses are depends on one another. therefore
 * we cannot complete all the courses
 * */
class Solution
{
  public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> adjList(numCourses);
        for (const auto &prerequisite : prerequisites)
            adjList[prerequisite[0]].emplace_back(prerequisite[1]);

        std::vector<bool> visited(numCourses, false);

        std::function<bool(const int &)> dfs = [&](const int &currCourse) {
            if (visited[currCourse])
                return false;

            // if no more prerequisites for this course
            if (adjList[currCourse].empty())
                return true;

            visited[currCourse] = true;

            for (const auto &prerequisite : adjList[currCourse])
                if (!dfs(prerequisite))
                    return false;

            // Pruning as the first time we visit this course and can complete it we can remove it from the graph
            // as the second time traverse tothis node we already know we can done this course
            adjList[currCourse].clear();
            visited[currCourse] = false;

            return true;
        };

        for (int i{}; i < numCourses; i++)
            if (!dfs(i))
                return false;

        return true;
    }
};
