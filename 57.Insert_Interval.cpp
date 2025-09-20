#include <algorithm>
#include <vector>
using std::vector;

/*
 * Given an array of non overlapping intervals, 'intervals' where intervals[i] = [starti, endi] and is sorted in
 * ascending order
 *
 * Intuition:
 * We need to merge those interval that are overlapping with the newInterval
 * So we need to find the first interval that overlapped and the last the that overlapped
 * How do we find the first interval that we overlap?
 * So overlapp happen when the interval ending point is greater or equal than the newInterval starting point
 * Then the last interval, just simply take whenever the new ending point of the newInterval is equal or greater than
 * the interval starting point. And just take the maximum ending point out of them. greater than the interval in the
 * Time Complexity: O(N)
 * */
class Solution
{
  public:
    vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        std::vector<std::vector<int>> answer;
        int n(intervals.size());
        int index{};

        // First find the first interval that overlapped with the newInterval
        // Check through the startIndex of the newInterval whether is it smaller than the previous interval endtime
        while (index < n && intervals[index][1] < newInterval[0])
        {
            answer.emplace_back(intervals[index]);
            index++;
        }

        // OK now we know this current interval is overlapping with the newInterval
        // Then we need to merge until the last interval that is overlap with the current interval
        while (index < n && intervals[index][0] <= newInterval[1])
        {
            newInterval[0] = std::min(intervals[index][0], newInterval[0]);
            newInterval[1] = std::max(intervals[index][1], newInterval[1]);
            index++;
        }

        // Now insert the newInterval that copmutes all the overlapping interals
        answer.emplace_back(newInterval);

        // Then push every interval into the end that is not overlapped
        while (index < n)
            answer.emplace_back(intervals[index++]);

        return answer;
    };
};
