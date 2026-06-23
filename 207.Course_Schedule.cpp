#include <unordered_set>
#include <vector>
/*
 * Every course has a prequisite couse need to take
 * eg: prequiesites[i] = [a, b]
 * Course 'a' must be taken before 'b'
 * So we need to make sure that for each course we want to take, we did take the prequisite as well
 * In order to able to finish all courses means we dont have a dead lock where for instance
 * [a,b] & [b,a] where b has to take before a and a has to take before b
 * So this is a graph problem and we can just DFS every course and traverse down its prequisite and make sure there is
 * no dead cycle inside it Can use a hashset to track the courses taht we had taken
 *
 * Time Complexity: O(V + E)
 * */
class Solution
{
    bool dfs(std::unordered_set<int> courses, std::vector<std::vector<int>> &adjList, int courseIndex)
    {
        courses.insert(courseIndex);

        for (const auto &prerequisite : adjList[courseIndex])
        {
            if (courses.find(prerequisite) != courses.end())
            {
                return false;
            }

            if (dfs(courses, adjList, prerequisite) == false)
            {
                return false;
            }
        }

        // prune it means this course can be taken with all the prerequisites also taken
        adjList[courseIndex].clear();
        return true;
    }

  public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites)
    {
        std::vector<std::vector<int>> adjList(numCourses, std::vector<int>());
        for (const auto &prequisite : prerequisites)
        {
            adjList[prequisite[0]].emplace_back(prequisite[1]);
        }

        for (int course{}; course < numCourses; course++)
        {
            // Track the current path instead of current DFS
            // Eg: [0, 1], [0, 2], [1, 2]
            // 2 path
            // Path 1 : 0->1->2
            // Path 2: 0->2
            // There is no cycle at all but if we track the current dfs then we will think theres a cycle which is wrong
            std::unordered_set<int> courses;
            if (dfs(courses, adjList, course) == false)
            {
                return false;
            }
        }
        return true;
    }
};
