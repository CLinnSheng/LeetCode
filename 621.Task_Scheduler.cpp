#include <deque>
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
/*
 * identical tasks must be seperated by at least n cpu cycles
 * return the minimum number of cpu cycles qre required to complete all tasks
 *
 * observation:
 * "identical" --> counts/freq of the task matters
 * want to return the minimum cycle so try to reduce as much idle time as possible
 *
 * intuition:
 * always process the most frequent task as possible, then we can use the idle time to process other task to make use of
 * the idle task
 *
 * since we want to always process the most frequent, then use a maxheap to get access to it in o(1)
 * get the frequency of each task --> map
 * and also need to handle task that gets into waiting queue. --> can use a queue to store the task and the time it gets
 * available. So we dont really need to know which task is in the waiitng queue, just psuh the next available time is
 * enough
 * */
class Solution
{
  public:
    int leastInterval(std::vector<char> &tasks, int n)
    {
        int time{};
        std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;
        std::unordered_map<int, int> mp;

        for (const auto task : tasks)
        {
            mp[task]++;
        }

        // push the freq into the heap
        for (auto [_, freq] : mp)
        {
            maxHeap.push(freq);
        }

        // Hold tasks that are cooling down
        std::deque<std::pair<int, int>> queue;

        while (!queue.empty() || !maxHeap.empty())
        {
            // Always processed the most freq task first
            if (!maxHeap.empty())
            {
                time++;

                // Need to handle tasks in the waiting queueu become available then only choose from all of it
                if (queue.front().second == time)
                {
                    auto [freq, _] = queue.front();
                    queue.pop_front();

                    maxHeap.push(freq);
                }

                int freq = maxHeap.top();
                maxHeap.pop();

                freq--;

                // Then check whether do we still need to process this task again?
                if (freq != 0)
                {
                    queue.emplace_back(std::pair{freq, time + n});
                }
            }
            else
            {
                auto [freq, task_time] = queue.front();
                queue.pop_front();

                // Move forward the time
                time = task_time;

                maxHeap.push(freq);
            }
        }

        return time;
    }
};
