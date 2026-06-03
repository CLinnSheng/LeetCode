/*
 * Brute force: Sort the arrays we stored every time a new value is added
 * Time Complexity: O(nlgn)
 *
 * Median is actually the mean from the maximum of the left half and the minimum from the right half
 * So we need to use a data strucutre we can easily add into the half, and easily access the minimum & maximum
 * Or Odd number just get the min/max from the larger half
 * Data Structure --> minheap & maxheap
 * But the problem is how do we know which half should we add whenever a new data comes?
 * One thing for sure is we need to make sure the size diff between these 2 heaps are always equal to 1
 * The way to determine add into which half is through the min/max element from each half
 * For instance, if greater than the min means must be at the right half which is larger
 * otherwise at the left half which is smaller
 * And also we need to always rebalance in order to keep it min size diff of 1
 * */

#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>
class MedianFinder
{
    std::priority_queue<int, std::vector<int>, std::greater<>> minHeap;
    std::priority_queue<int, std::vector<int>, std::less<>> maxHeap;

  public:
    MedianFinder()
    {
    }

    // O(lgn)
    void addNum(int num)
    {
        // Determine which half to add
        if (minHeap.empty() || num > minHeap.top())
        {
            minHeap.push(num);
        }
        else
        {
            maxHeap.push(num);
        }

        // Check the size, rebalance if needed
        if (std::abs(int(minHeap.size() - maxHeap.size())) > 1)
        {
            // The difference is always either 1 or 2
            // So we just need to pop one elmeent and add it to another half
            // And the element should be the top of either heap because if left half is too big then definitely the
            // maxElement should be decreased and vice versa
            if (minHeap.size() > maxHeap.size())
            {
                int top = minHeap.top();
                minHeap.pop();

                maxHeap.push(top);
            }
            else
            {
                int top = maxHeap.top();
                maxHeap.pop();

                minHeap.push(top);
            }
        }
    }

    // O(1)
    double findMedian()
    {
        int size = minHeap.size() + maxHeap.size();

        if (size % 2 == 0)
        {
            return (minHeap.top() + maxHeap.top()) / 2.0;
        }

        return minHeap.size() > maxHeap.size() ? minHeap.top() : maxHeap.top();
    }
};
