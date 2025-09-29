#include <algorithm>
/*
 * Goal Find the least number of perfect square that sum up to n
 *
 * Intuition:
 * We have to keep recursively to solve the problem until we can reach n by keep trying from the least perfect square
 * and then just take the minimum
 * We can improve it by using caching since this is a recursive problem and we can see there is some overlapping problem
 * The caching will be 1d array because we only pass 1 information while doing the recursive
 * Time Complexity: O(n^2)
 *
 * */
#include <vector>
class Solution
{

  private:
    int dfs(const int n, std::vector<int> &caching)
    {
        // Base Case reach sum
        if (n == 0)
            return 0;

        if (caching[n] != -1)
            return caching[n];

        // Maximum possible nubmer of perfect square just simoply all consist of 1
        int res{n};
        for (int i{1}; i * i <= n; i++)
            res = std::min(res, 1 + dfs(n - i * i, caching));
        return caching[n] = res;
    }

  public:
    int numSquares(int n)
    {
        std::vector<int> caching(n + 1, -1);
        return dfs(n, caching);
    }
};
