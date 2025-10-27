#include <vector>
/*
 * Goal: Find the total number of distinct combinations that total up to amount
 * Assumption: Unlimited number of each coin that each value in coins is unique
 *
 * Intuition:
 * At every single amount, we can either to choose of the coin inside the coins array
 * So is a decision tree problem
 * Time Complexity: O(2^n)
 *
 * From the brute force approach, we can see some computation is repetitive for example at x sum we already got the
 * number of combinatoin we can form for it but we still continue to compute it
 * So what we can do is use caching
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    int dfs(int currAmt, std::vector<int> &coins, int index, std::vector<std::vector<int>> &cache)
    {
        // Base case
        // Possible combination
        if (currAmt == 0)
        {
            return 1;
        }

        // Cannot form so return and try others
        if (currAmt < 0 || index == coins.size())
        {
            return 0;
        }

        if (cache[currAmt][index] != -1)
        {
            return cache[currAmt][index];
        }

        int combination{};

        // This implementation is wrong because we treating (2, 1) & (1 , 2) not the same
        // but is the same combination
        // for (const auto coin : coins)
        // {
        //     combination += dfs(currAmt - coin, coins, index + 1);
        // }

        // Skip this coin
        int path1 = dfs(currAmt, coins, index + 1, cache);

        // Include this coin
        int path2 = dfs(currAmt - coins[index], coins, index + 1, cache);

        return cache[currAmt][index] = path1 + path2;
    }

  public:
    int change(int amount, std::vector<int> &coins)
    {
        std::vector<std::vector<int>> cache(amount + 1, std::vector<int>(coins.size() + 1, -1));
        return dfs(amount, coins, 0, cache);
    }
};
