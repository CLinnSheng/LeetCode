#include <algorithm>
#include <queue>
#include <utility>
#include <vector>
using std::vector;

/*
 * If CPU is idle & tasks are available, CPU will choose the one with the shortest processing time.
 * If multiple tasks have the same processing time, then choose the 1 with smallest index
 *
 * So the goal is try to reduce the CPU idle time as much as possible
 * Firs the tasks are not sorted
 * At every time frame we push the  all the available task at this timeframe (index, time), then take the shortest
 * processing time. --> minHeap
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */

struct Comparator
{
    bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
    {
        if (A.first == B.first)
        {
            return A.second > B.second;
        }

        return A.first > B.first;
    }
};

class Solution
{
  public:
    vector<int> getOrder(vector<vector<int>> &tasks)
    {
        int n = tasks.size();
        vector<int> ans;

        // Sort the tasks but still need to preserve the index
        // HashMap to store the indices? --> Unfortunately no because the key cannot be a tuple otherwise need to create
        // own hash function
        // Use an array or vector
        vector<vector<int>> indexes;
        for (int i{}; i < n; i++)
        {
            indexes.push_back(vector<int>{tasks[i][0], tasks[i][1], i});
        }
        std::sort(indexes.begin(), indexes.end());

        // Variable to track the current time
        int time = indexes[0][0];
        // Keep track of the task we pushed into the heap
        int index{};

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> taskQueue;

        // Loop until we process all the task
        while (ans.size() < n)
        {
            // Push all the available task into the queue
            while (index < n && indexes[index][0] <= time)
            {
                taskQueue.push(std::pair<int, int>{indexes[index][1], indexes[index][2]});
                index++;
            }

            // Edge Cases --> If no time then fast forward to the next task
            if (taskQueue.empty())
            {
                time = indexes[index][0];
                taskQueue.push(std::pair<int, int>{indexes[index][1], indexes[index][2]});
                index++;
            }

            // Process the task
            auto task = taskQueue.top();
            taskQueue.pop();
            ans.push_back(task.second);

            // Move forward the time
            time += task.first;
        }

        return ans;
    }
};
