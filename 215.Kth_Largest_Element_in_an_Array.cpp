#include <functional>
#include <queue>
#include <vector>
/*
 * Find 'Kth' largest --> First intuition use a heap
 * max or min heap? Since we getting the kth largest, so that mean we want to get it in O(1)
 * Then the method will be accessing the top of the heap
 * Then just use a minheap
 *
 * Time Complexity: O(nlgn) --> Inserting/Deletion is O(lgn)
 * Space Complexity: O(k)
 * */
class Solution
{
  public:
    int findKthLargest(std::vector<int> &nums, int k)
    {
        std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;

        for (const auto num : nums)
        {
            minHeap.push(num);

            if (minHeap.size() > k)
            {
                minHeap.pop();
            }
        }

        return minHeap.top();
    }
};
