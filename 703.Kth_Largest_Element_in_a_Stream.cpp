/*
 * Can use priority queue data structure to store it
 * add -> return the kth largest after inserting the new element
 * First intuition will be using a maxHeap but this is wrong, because we need iterate from the top to the kth element
 * But using minHeap will be much more easier, because we acn make it alwayus contain only k element inside the heap, so
 * the top will always be the kth largest element
 * */

#include <functional>
#include <queue>
#include <vector>
class KthLargest
{
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  public:
    KthLargest(int k, std::vector<int> &nums) : k(k)
    {
        for (const auto &num : nums)
        {
            minHeap.emplace(num);
        }
    }

    int add(int val)
    {
        minHeap.emplace(val);

        while (k < minHeap.size())
        {
            minHeap.pop();
        }

        return minHeap.top();
    }
};
