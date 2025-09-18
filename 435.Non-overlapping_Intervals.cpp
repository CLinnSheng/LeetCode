#include <algorithm>
#include <vector>

/*
 * Goal: Find the minimum number of intervals needed to remove the rest of the intervals non-overlapping
 *
 * Intuition:
 * We can sort the intervals by starting point first, so we can easily to amnage it
 * Then we can just simple check the current event start point got less than the previous event end time or not.
 * And then if we overlap, we will remove the 1 that has the longer end time. So we be greedy by getting the minimum end
 * time
 * Time Complexity: O(nlogn)
 * */
class Solution
{
  public:
    int eraseOverlapIntervals(std::vector<std::vector<int>> &intervals)
    {
        std::sort(intervals.begin(), intervals.end());
        int answer{};
        int prevEnd{intervals[0][1]};

        for (int i{1}; i < intervals.size(); i++)
        {
            if (intervals[i][0] < prevEnd)
            {
                answer++;
                prevEnd = std::min(prevEnd, intervals[i][1]);
            }
            else
            {
                prevEnd = intervals[i][1];
            }
        }

        return answer;
    }
};
