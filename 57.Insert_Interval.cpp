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
        vector<vector<int>> answer;
        int index{}, n(intervals.size());

        // finding the first interval where overlapping happen
        while (index < n && newInterval[0] > intervals[index][1])
        {
            answer.emplace_back(intervals[index]);
            index++;
        }

        // finding the last interval
        while (index < n && newInterval[1] >= intervals[index][0])
        {
            newInterval[0] = std::min(newInterval[0], intervals[index][0]);
            newInterval[1] = std::max(newInterval[1], intervals[index][1]);
            index++;
        }

        answer.emplace_back(newInterval);

        while (index < n)
        {
            answer.emplace_back(intervals[index]);
            index++;
        }

        return answer;
    };
};
