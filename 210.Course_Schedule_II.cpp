#include <deque>
#include <vector>

/*
 * Find the order of courses need to taken
 * So in order to take all courses --> Must have no cycle
 * So we need to start from the root course which means the inDegree is 0
 * Can think each course is a node and the edge is the prequiesites
 * Can either use BFS/DFS, since we want to start from the course with no prequiesites use BFS will be much more easier
 * Time Complexity: O(V + E)
 * */
class Solution
{
  public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> adjLists(numCourses, std::vector<int>());
        for (const auto &prerequisite : prerequisites)
        {
            adjLists[prerequisite[1]].emplace_back(prerequisite[0]);
        }

        std::deque<int> queue;
        std::vector<int> inDegree(numCourses, 0);
        for (const auto &course : prerequisites)
        {
            inDegree[course[0]]++;
        }
        for (int i{}; i < numCourses; i++)
        {
            if (inDegree[i] == 0)
            {
                queue.emplace_back(i);
            }
        }

        std::vector<int> ans;

        // The queue only contains course that is `ready` which means all of its prequiesites courses are cleared
        while (!queue.empty())
        {
            auto currCourse = queue.front();
            queue.pop_front();
            ans.emplace_back(currCourse);

            // Remove the inDegree Count of the course that needed this `currCourse` as prerequisite
            for (int nextCourse : adjLists[currCourse])
            {
                inDegree[nextCourse]--;

                if (inDegree[nextCourse] == 0)
                {
                    queue.emplace_back(nextCourse);
                }
            }
        }

        // Cycle detection, if ans doesnt include all means some course cannot be taken because it depends on another
        // course that also depend on itself
        return ans.size() == numCourses ? ans : std::vector<int>();
    }
};
