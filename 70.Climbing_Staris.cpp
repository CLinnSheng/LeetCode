/*
 * Given that u can climb either 1 or 2steps at a time
 * Goal: Return the number of distinct ways to climb to the top which is n
 *
 * Intuition: At every step we either came from stepping 1 step or 2 step
 * so we can make use of the computed steps to count for the next step
    Time Complexity: O(n)
    Space Complexity :O(1)
 * */
#include <vector>
class Solution
{
  public:
    int climbStairs(int n)
    {
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;

        std::vector<int> steps(n + 1);
        steps[1] = 1;
        steps[2] = 2;

        for (int i{3}; i <= n; i++)
            steps[i] = steps[i - 1] + steps[i - 2];
        return steps[n];
    }
};
