#include <algorithm>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>
/*
 * trips[i] --> [numPassengers[i], from[i], to[i]]
 * Direction due east from car initial location
 * Goal: Determine is it possible to pick up and drop of all passengers for all the given trips
 *
 * Intuition:
 * So we need to make sure everytime we pick it wont exceed the available capacity if it exceeds then means
 * cannot prick and drop all passgeners
 *
 * We need to sort the trip according to the start time.
 * Then have a data structure that storing the current psasenger trip end time and num of passengers
 * This we can use a minHeap that can easily access the earliest trip end time
 * Time Complexity: O(Nlgn)
 *
 * Theres actually a more efficient way which is use line sweeping algorithm
 * because we can see at a specific time passenger will go up and a specific time a passenger will go down
 * So we just need to build a time array where passenger will go up and down and track the num of passenger on the bus
 * */
class Solution
{
  public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
    {
        // Time Complexity: O(nlgn)
        // std::sort(trips.begin(), trips.end(),
        //           [](const std::vector<int> &A, const std::vector<int> &B) { return A[1] < B[1]; });
        //
        // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>>
        //     minHeap;
        //
        // int currPassenger{};
        //
        // for (const auto &trip : trips)
        // {
        //     int numPassengers{trip[0]}, from{trip[1]}, to{trip[2]};
        //
        //     // Remove any end trip
        //     while (!minHeap.empty() && minHeap.top().first <= from)
        //     {
        //         currPassenger -= minHeap.top().second;
        //         minHeap.pop();
        //     }
        //
        //     // Fetch the current trip passenger
        //     currPassenger += numPassengers;
        //
        //     // Check whether exceed capacity or not
        //     if (currPassenger > capacity)
        //         return false;
        //
        //     // Push the ongoing trip
        //     minHeap.emplace(to, numPassengers);
        // }
        //
        // return true;

        // Line Sweeping Algorithm O(n)
        int minTime{INT_MAX}, maxTime{INT_MIN};
        for (const auto &trip : trips)
        {
            minTime = std::min(trip[1], minTime);
            maxTime = std::max(trip[2], maxTime);
        }

        int N{maxTime - minTime + 1};
        std::vector<int> timeline(N + 1, 0);
        // Populate the timeline array
        for (const auto &trip : trips)
        {
            timeline[trip[1] - minTime] += trip[0]; // Up
            timeline[trip[2] - minTime] -= trip[0]; // Down
        }

        int passengers{};
        for (const auto &passenger : timeline)
        {
            passengers += passenger;
            if (passengers > capacity)
                return false;
        }
        return true;
    }
};
