/*
 * Finding how many stpes to reach the top
 * So each time we can either climb 1 or 2 steps
 * Brute force way is just at every index we tried both steps
 * If you notice there is overlapping of subproblem
 * We can solve it by using caching and make use of the past time
 * Time Complexity: O(n)
 * */
#include <vector>
class Solution
{
  public:
    int climbStairs(int n)
    {
        // Base Case
        if (n == 1)
        {
            return 1;
        }

        if (n == 2)
        {
            return 2;
        }

        std::vector<int> steps(n + 1, 0);
        steps[1] = 1;
        steps[2] = 2;

        for (int step{3}; step <= n; step++)
        {
            steps[step] = steps[step - 1] + steps[step - 2];
        }

        return steps[n];
    }
};
