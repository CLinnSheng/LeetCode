#include <ios>
#include <iostream>
#include <vector>

/*
Goal: Return the minimum cpu run time
Constraint: There is an idle time to run the same process

Intuition: We must process the process with the most frequent count
This is because we can make use of the idle time to run other process that comes
after x (in frequency) Through this we can minimize the least interval time we
can make use of maxHeap data structure to get access the most frequent count use
queue data structure to handle the idle processes or also can known as waiting
queue. Once the process reach the desired amount of waiting time, we can send
the process back to the ready queue. Time Complexity: O(n) Space Complexity:
O(n)
*/
class Solution {
public:
  int leastInterval(vector<char> &tasks, int n) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::unordered_map<int, int> map;
    for (const auto &task : tasks)
      map[task]++;

    // maxheap
    std::priority_queue<int, std::vector<int>, less<>> maxHeap;
    for (const auto &[_, freq] : map)
      maxHeap.emplace(freq);

    // to track the time and to know when to execute process back from idle
    int time = 0;
    std::deque<std::pair<int, int>> queue; // to store idle process;
    while (!maxHeap.empty() || !queue.empty()) {
      // idle process go back to the ready queue after waiting for n time
      if (!queue.empty() && time >= queue.front().second) {
        maxHeap.emplace(queue.front().first);
        queue.pop_front();
      }

      if (!maxHeap.empty()) {
        int process_freq = maxHeap.top() - 1;
        maxHeap.pop();
        if (process_freq > 0)
          queue.emplace_back(process_freq, n + time + 1);
      }
      time++;
    }
    return time;
  }
};
