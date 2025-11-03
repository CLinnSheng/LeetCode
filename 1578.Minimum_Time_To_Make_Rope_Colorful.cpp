#include <string>
#include <vector>
/*
 * n balloons arranged on a rope where colors[i] is the color of balloon i
 * No 2 consecutive balloons can be of the same color
 * You can remove any balloon from the rope and cost neededTime[i] time
 *
 * Goal: find the minimum cost to make all the balloons the same color
 *
 * Intuition:
 * Use sliding window to find the window where all balloons are the same color then only left the 1 with the maximum
 * time
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int minCost(std::string colors, std::vector<int> &neededTime)
    {
        int left{}, right{};
        int ans{};

        while (right < neededTime.size())
        {
            int maximumTime{};
            int ttlTime{};

            while (right < neededTime.size() && colors[left] == colors[right])
            {
                ttlTime += neededTime[right];
                maximumTime = std::max(maximumTime, neededTime[right]);
                right++;
            }

            ans += ttlTime - maximumTime;
            left = right;
        }
        return ans;
    }
};
