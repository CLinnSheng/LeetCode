#include <algorithm>
#include <functional>
#include <queue>
#include <vector>

/*
 * Goal: Return the minimum number of operations needed so taht all elements of the array are greater than or equal to
 * k.
 *
 * Intuition:
 * So we only need to check the smallest number.
 * If not:
 * pop the 2 smallest number and undergo the give operation
 * So, using minHeap data structure can easily get the smallest element every single time
 *
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    int minOperations(std::vector<int> &nums, int k)
    {
        int cnt{};
        std::priority_queue<long long, std::vector<long long>, std::greater<>> minHeap(nums.begin(), nums.end());

        // only need to check the smallest
        while (minHeap.top() < k)
        {
            auto firs{minHeap.top()};
            minHeap.pop();
            auto sec{minHeap.top()};
            minHeap.pop();

            minHeap.emplace(std::min(firs, sec) * 2 + std::max(firs, sec));

            cnt++;
        }
        return cnt;
    }
};
