
/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

#include <algorithm>
#include <map>
/*
 * Goal: Find the minimum number of days to schedule all meetings without any conflicts
 *
 * Intuition:
 * First sort the intervals by start time, to easier manage
 * Then we need to find out the interval that is overlapped with other interval
 * We can use a line sweeping algorithm to find out at any time what is the maximum of meetings is it. Then this will
 * simply be the answer for the menimum number of days required
 * Time Complexity: O(nlogn)
 *
 * */
class Solution
{
  public:
    int minMeetingRooms(std::vector<Interval> &intervals)
    {
        int n(intervals.size());

        if (n == 0)
            return 0;
        if (n == 1)
            return 1;

        std::map<int, int> intervalsMap;
        for (const auto &interval : intervals)
        {
            intervalsMap[interval.start]++;
            intervalsMap[interval.end]--;
        }

        int currMeeting{};
        int answer{};

        for (const auto &[time, val] : intervalsMap)
        {
            currMeeting += val;
            answer = std::max(answer, currMeeting);
        }

        return answer;
    }
};
