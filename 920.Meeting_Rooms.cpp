
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
#include <vector>
/*
 * Goal: Determine if a person could add all meetings to their schedule without any conflicts
 *
 * Intuition: Sort the intervals by star time, then it will be easier
 * Then just simply check the start time of the next interval is it lesser than the end time of the previous interval
 * */
class Solution
{
  public:
    bool canAttendMeetings(std::vector<Interval> &intervals)
    {
        if (intervals.size() == 0)
            return true;

        std::sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) { return a.start < b.start; });
        std::pair<int, int> prevInterval{intervals[0].start, intervals[0].end};

        for (int i{1}; i < intervals.size(); i++)
        {
            if (prevInterval.second > intervals[i].start)
                return false;

            prevInterval = std::make_pair(intervals[i].start, intervals[i].end);
        }

        return true;
    }
};
