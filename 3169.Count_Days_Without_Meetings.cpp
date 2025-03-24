#include <algorithm>
#include <vector>
using std::vector;

/*
 * meetings[i] = [strat_i, end_i] (inclusive)
 * Goal: Return the count of days when the employee is available for work but no meetings are scheduled
 *
 * Intuition:
 * At first glance i can tell is an interval pattern problem.
 * We can just simply go through the meetings, and minus the day of meeting for the particulary meeting
 * But how do we deal with overlapping meeting?
 * We can sort the array first, so that we start from the earliest day
 * Then, have a variable to track the previous end day. So for every new meeting we take the maximum of prevDay + 1 and
 * start_i of meetings[i] to deal with the overlapping day.
 * Then, how do we deal with the edge case of another meeting which come later is entirely inside another meeting?
 * We will do the same thing but now the end day is smaller than start day will result in day < 0
 * so whenever face this we just make the number of day meeting equal to 0
 * Time Complexity: O(nlgn)
 *
 * */
class Solution
{
  public:
    int countDays(int days, vector<vector<int>> &meetings)
    {
        int prevStartDay{};
        std::sort(meetings.begin(), meetings.end());

        for (const auto &meeting : meetings)
        {
            int startDay{std::max(prevStartDay + 1, meeting[0])};
            int nDayMeeting{meeting[1] - startDay + 1};
            days -= std::max(nDayMeeting, 0);
            prevStartDay = std::max(prevStartDay, meeting[1]);
        }
        return days;
    }
};
