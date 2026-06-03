#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * The trips are not sorted at all
 * We need to sort according to their starting point, so is must more easier for us to process the array
 * Then just iterate through the array and check against the to & from time, to know when to add passenger and check the
 * capacity after adding the pasenger
 * But we need to take care when to minus and when to add
 * We only drop the customer if the current trip starting is greater than the end of ongoing trip
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 *
 *
 * So instead of tracking the trip, why not we track what changes at each position?
 * Since we got the border of each trip, so simply just drop/add the cnt
 * If at any point of time the cnt exceed the capacity then means fail
 * Time Complexity: O(n)
 * */

class Solution
{
  public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity)
    {
        // Sort the trips
        // O(nlgn)
        // std::sort(trips.begin(), trips.end(), [](const auto &a, const auto &b) { return a[1] < b[1]; });
        // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> onGoing;
        // int cnt{};
        //
        // for (const auto &trip : trips)
        // {
        //     // Dropping the passenger
        //     while (!onGoing.empty() && onGoing.top().first <= trip[1])
        //     {
        //         cnt -= onGoing.top().second;
        //         onGoing.pop();
        //     }
        //
        //     // Adding the passenger
        //     cnt += trip[0];
        //     onGoing.emplace(trip[2], trip[0]);
        //
        //     if (cnt > capacity)
        //     {
        //         return false;
        //     }
        // }

        // Scan through the event
        int positions[1001] = {0};
        for (const auto &trip : trips)
        {
            positions[trip[1]] += trip[0];
            positions[trip[2]] -= trip[0];
        }

        int cnt{};
        for (int i{}; i <= 1000; i++)
        {
            cnt += positions[i];

            if (cnt > capacity)
            {
                return false;
            }
        }
        return true;
    }
};
