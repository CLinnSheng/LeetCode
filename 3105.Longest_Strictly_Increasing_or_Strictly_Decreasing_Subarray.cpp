#include <algorithm>
#include <vector>
using std::vector;

class Solution
{
  public:
    int longestMonotonicSubarray(vector<int> &nums)
    {
        int increasing{};
        int answer{}, curr{};

        if (nums.size() == 1)
            return 1;

        for (int i{1}; i < nums.size(); i++)
        {
            // increasing
            if (nums[i] > nums[i - 1])
            {
                if (increasing > 0)
                    curr++;
                else
                {
                    increasing = 1;
                    curr = 2;
                }
            }
            // decreasing
            else if (nums[i] < nums[i - 1])
            {
                if (increasing < 0)
                    curr++;
                else
                {
                    increasing = -1;
                    curr = 2;
                }
            }
            // equal
            else
            {
                increasing = 0;
                curr = 1;
            }
            answer = std::max(answer, curr);
        }
        return answer;
    }
};
