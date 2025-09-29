/*
 * Given an integer n break it into the sum of k positive integers where k>= 2 and maximize the product of these
 * integers.
 *
 * Intuition:
 * Ok so at each stage we need to choose the positive integers that we want to break the n. So we can choose to break
 * from 1 until n - 1
 * So, this is actually a recursive problem. And we will take the 1 that produce the largest product.
 * We can improve it by using caching. The array will be 1d because we only pass 1 information when doing the recursion
 * Time Complexity: O(n^2)
 * */
#include <algorithm>
#include <vector>
class Solution
{
  private:
    int dfs(const int n, const int originalN, std::vector<int> &caching)
    {
        if (n == 1)
            return 1;
        if (caching[n] != -1)
            return caching[n];

        // If we choose not to split this number, then the product will just simply be itself
        int maxProduct{n == originalN ? 0 : n};
        for (int i{1}; i < n; i++)
        {
            int product{dfs(i, originalN, caching) * dfs(n - i, originalN, caching)};
            maxProduct = std::max(maxProduct, product);
        }
        return caching[n] = maxProduct;
    }

  public:
    int integerBreak(int n)
    {
        std::vector<int> caching(n + 1, -1);
        return dfs(n, n, caching);
    }
};
