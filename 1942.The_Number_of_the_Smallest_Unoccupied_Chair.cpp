#include <algorithm>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

/*
 * When a friend arrives at the party, they sit on the unoccupied chair with the
 * smallest number time[i] = [ai, bi] friend i reaches at ai and leaves at bi
 * Intuition:
 * We need to place the seat according to the arrival times
 * The constarint is the friend is not coming an ascending order. So to solve
 * this problem we need to use map data structure to store the index.
 * Time Complexity: O(nlgn) because o using heap
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int smallestChair(std::vector<std::vector<int>> &time, int targetFriend) {

    // to store the arrival and leaving of each friend with its index
    std::vector<std::pair<int, int>> events;
    int n_friends = time.size();
    for (int i = 0; i < n_friends; i++) {
      events.emplace_back(time[i][0], i); // arrival
      events.emplace_back(time[i][1], ~i);
    }
    std::sort(events.begin(), events.end());

    // minHeap, because everytime we try to assign a chair we assign the minimum
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        availableChairs;
    for (int i = 0; i < n_friends; i++)
      availableChairs.push(i);

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        occupiedChairs;

    for (const auto &[_time, _friendIndex] : events) {
      // Free up chairs if some1 leaves
      while (!occupiedChairs.empty() && occupiedChairs.top().first <= _time) {
        availableChairs.push(occupiedChairs.top().second);
        occupiedChairs.pop();
      }

      // if got firend arrives
      if (_friendIndex >= 0) {
        int smallestAvailableChair = availableChairs.top();
        availableChairs.pop();

        if (_friendIndex == targetFriend)
          return smallestAvailableChair;

        // push the occupied chair into the heap with the respective leaving
        // time
        occupiedChairs.emplace(time[_friendIndex][1], smallestAvailableChair);
      }
    }
    return -1;
  }
};
