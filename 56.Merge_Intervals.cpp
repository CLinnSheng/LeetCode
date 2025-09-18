#include <algorithm>
#include <vector>

/*
 * Merge all overlapping intervals.
 *
 * Intuition:
 * Sort the interval by the start time so we can easily check whether the next event will overlap with the first
 * interval or not
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals)
    {
        std::vector<std::vector<int>> answer;

        std::sort(intervals.begin(), intervals.end());

        for (const auto &interval : intervals)
        {
            if (answer.empty())
                answer.emplace_back(interval);
            else
            {
                int prevEnd{answer.back()[1]};

                if (prevEnd >= interval[0])
                    answer.back()[1] = std::max(prevEnd, interval[1]);
                else
                    answer.emplace_back(interval);
            }
        }
        return answer;
    }
};
