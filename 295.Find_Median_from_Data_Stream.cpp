/*
 * Goal: Find the median of every single time we want to & the median changes
 * everytime we insert a new eleemt
 *
 * Intuition:
 * Brute force
 * Sort the element everytime we
 * want to find the median. And then get the middle element. Time Complexity:
 * O(nlgn) because of sorting Space Complexity: O(n)
 *
 * Theres a better way to optimize it for the sorting part instead of sorting it
 * every single time. Why dont we seperate the whole array into 2 parts by using
 * maxHeap & minHeap. To find the median just get the average of the top from
 * minHeap & maxHeap if even number or else get the 1 larget in size This will
 * reduce the timec complexity to O(lgn) because everytime insert and remove
 * will only cost logn Space Complexity: O(N)
 * */

#include <functional>
#include <queue>
class MedianFinder
{
  public:
    // minHeap storing the largete element which is on the right half
    // maxHeap storing the smaller element which is on the left half
    std::priority_queue<int, std::vector<int>> left_half;
    std::priority_queue<int, std::vector<int>, std::greater<>> right_half;

    MedianFinder()
    {
    }

    void addNum(int num)
    {
        // we by default add number to minHeap first then only proceed to check
        if (left_half.empty())
        {
            left_half.emplace(num);
            return;
        }

        left_half.emplace(num);
        // Checking whether is it on the correct half or not
        if (!left_half.empty() && !right_half.empty() && right_half.top() < left_half.top())
        {
            right_half.emplace(left_half.top());
            left_half.pop();
        }

        // Make sure the size differences at max is 1
        if (right_half.size() > left_half.size() + 1)
        {
            left_half.emplace(right_half.top());
            right_half.pop();
        }
        if (left_half.size() > right_half.size() + 1)
        {
            right_half.emplace(left_half.top());
            left_half.pop();
        }
    }

    double findMedian()
    {
        return (right_half.size() + left_half.size()) % 2
                   ? (right_half.size() > left_half.size() ? right_half.top() : left_half.top())
                   : (right_half.top() + left_half.top()) / (double)2;
    }
};
