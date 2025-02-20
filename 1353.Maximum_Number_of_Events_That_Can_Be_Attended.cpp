#include <algorithm>
#include <functional>
#include <queue>
#include <vector>
using std::vector;

/*
 * Given an array of events where events[i] = [startDayi, endDayi]. You can attend i event at any day where startDay <=
 * d <= endDay
 * NOTE: Can only attend one event at any time d
 *
 * Intuition:
 * Interpreting the question:
 *  - you are free to choose to attend an event i at any day as long as is just in between startDay and endDay
 * First of all we need to sort the events based on the starting day first for convention purpose.
 * We going to iterate from day1 to day10000 because the maximum day is day10000
 * Instead of focusing on the starting day, we should focus on the ending day because as long as the ending day is
 * less than d, we can attend it (greedy)
 * We can use a minHeap to store the event & we will also remove all those event havent attend yet but the ending day is
 * already past
 *
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    int maxEvents(vector<vector<int>> &events)
    {
        std::priority_queue<int, vector<int>, std::greater<>> minHeap;
        int answer{};
        vector<vector<int>>::iterator it{events.begin()};

        // sort the event
        std::sort(events.begin(), events.end());

        // be greedy and join any event that havent end yet
        for (int day{1}; day <= 100000; day++)
        {
            // remove any event that has past and not attend
            while (!minHeap.empty() && minHeap.top() < day)
                minHeap.pop();

            // push the event into the heap within the same day
            while (it != events.end() && (*it)[0] == day)
                minHeap.push((*it++)[1]);

            // be greedy & visit it
            if (!minHeap.empty())
            {
                minHeap.pop();
                answer++;
            }
        }

        return answer;
    }
};
