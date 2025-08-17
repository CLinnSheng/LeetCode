#include <functional>
#include <vector>

/*
 * prerequisites[i] = [ai, bi] take course ai, must take course bi first
 * Goal: Return a valid ordering of course you acn take all course.
 *
 * Intuition:
 * A bit similar to the first version of course_schedule. but just a little bit tweek.
 * We can make use of the first version to find whether is it possible to have all course or not
 * by just checking got cycle or not
 * Since this is finding the order of course taken, we need another array to keep track of all the course we taken. So
 * that we no need to go through the same prerequisiteCourse again
 * Time COmplexity: O(V + E)
 * */
class Solution
{
  public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> adjList(numCourses);
        for (const auto &prerequisite : prerequisites)
            adjList[prerequisite[0]].emplace_back(prerequisite[1]);

        std::vector<int> answer{};
        std::vector<bool> cycles(numCourses, false), courseTaken(numCourses, false);

        std::function<bool(const int &)> dfs = [&](const int &currCourse) {
            if (cycles[currCourse])
                return false;

            // If already taken this course no need to put into the array again
            // So means the this course is a prerequisiteCourse and already taken
            if (courseTaken[currCourse])
                return true;

            // Mark this course as visited
            cycles[currCourse] = true;

            for (const auto &prerequisiteCourse : adjList[currCourse])
                if (!dfs(prerequisiteCourse))
                    return false;

            answer.emplace_back(currCourse);
            courseTaken[currCourse] = true;

            // Unmark in case other course need this as prerequisite as well
            cycles[currCourse] = false;
            adjList[currCourse].clear();
            return true;
        };
        for (int i{}; i < numCourses; i++)
            if (!dfs(i))
                return {};

        return answer;
    }
};
