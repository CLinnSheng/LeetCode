#include <vector>
/*
 * prices[i] price of stock on the ith day
 * May buy and sell one stock multiple times with the following restrictions:
 * 1. After selling your stock cannot buy another one on the next day
 * 2. Own at most one stock at a time
 * Can complete as many transactions as possible
 * Goal: Return the maximum profit
 *
 * Intuition:
 * So at each day we can choose to buy or not buy if we havent own a stock yet.
 * Then this go the same for selling, where we can choose to sell or not
 * Time Complexity: O(2^n)
 * Space Complexity: O(n) --> Maximum recursive call stack is n
 *
 * Observe from the brute force, we can see many repetitive computation.
 * We can optimize it through caching
 * Every recursive call we passing 2 information which is index and canBuy
 * Therefore, our caching will be a 2d array
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    int dfs(std::vector<int> &prices, bool canBuy, int index, std::vector<std::vector<int>> &caching)
    {
        // Base Case
        if (index >= prices.size())
        {
            return 0;
        }

        if (caching[index][canBuy] != -1)
        {
            return caching[index][canBuy];
        }

        // 2 options either skip or do action over here
        int skip = dfs(prices, canBuy, index + 1, caching);

        if (canBuy)
        {
            int buy = dfs(prices, false, index + 1, caching) - prices[index];
            return caching[index][canBuy] = std::max(buy, skip);
        }
        else
        {
            int sell = dfs(prices, true, index + 2, caching) + prices[index];
            return caching[index][canBuy] = std::max(sell, skip);
        }
    }

  public:
    int maxProfit(std::vector<int> &prices)
    {
        std::vector<std::vector<int>> caching(prices.size(), std::vector<int>(2, -1));
        return dfs(prices, true, 0, caching);
    }
};
