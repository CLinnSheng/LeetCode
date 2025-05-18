/*
 * Given m & n, consider an m * n grid where each cell is initially white
 * Can print the cell red, green, blue.
 * All cells must be painted
 *
 * Goal: Return the number of waysto color the grid with no 2 adjacent cells having the same color.
 *
 * Intuition:
 *
 * */
#include <math.h>
#include <numeric>
#include <vector>
using std::vector;

class Solution
{
  public:
    const int mod = 1e9 + 7;
    int dp[1005][250], rowValid[250][250];
    vector<int> good, pattern[250];
    int colorTheGrid(int m, int n)
    {
        int total = std::pow(3, m);

        for (int i = 0; i < total; i++)
        {
            int val = i, valid = 1;
            for (int j = 0; j < m; j++)
                pattern[i].push_back(val % 3), val /= 3;
            for (int j = 1; j < m; j++)
                if (pattern[i][j] == pattern[i][j - 1])
                    valid = 0;
            if (valid)
                good.push_back(i);
        }
        for (int i : good)
            dp[1][i] = 1;

        for (int i : good)
        {
            for (int j : good)
            {
                rowValid[i][j] = 1;
                for (int k = 0; k < m; k++)
                    if (pattern[i][k] == pattern[j][k])
                        rowValid[i][j] = 0;
            }
        }

        for (int col = 2; col <= n; col++)
            for (int i : good)
                for (int j : good)
                    if (rowValid[i][j])
                        dp[col][i] = (dp[col][i] + dp[col - 1][j]) % mod;

        return std::accumulate(dp[n], dp[n] + total, 0L) % mod;
    }
};
