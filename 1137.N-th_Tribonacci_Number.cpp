#include <array>
class Solution
{
  public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;

        std::array<int, 3> dp;
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        for (int i = 3; i <= n; i++)
        {
            int nextVal{dp[0] + dp[1] + dp[2]};

            // Shift everything forward
            dp[0] = dp[1];
            dp[1] = dp[2];
            dp[2] = nextVal;
        }
        return dp[2];
    }
};
