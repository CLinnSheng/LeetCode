#include <vector>

/*
 * prices[i] is the price of a given stock on the ith day.
 * Each day, can buy/sell the stock
 * Can buy it then immediately sell it on the same day.
 * Constraint: can only hold at most one share of the stock at any time
 *
 * Goal: Find and return the maximum profit you can achieve
 *
 * Intuition:
 * The best way to maximize the profit is buy low and sell high
 * Greedy approach
 * So we will first find the local minima first, then only proceed finding the local maxima
 * Time Complexity: O(N)
 * */
class Solution
{
  public:
    int maxProfit(std::vector<int> &prices)
    {
        int maxProfit{};

        int low{prices[0]}, high{prices[0]}, it{};
        int nDays(prices.size());

        while (it < nDays - 1)
        {
            while (it < nDays - 1 && prices[it] >= prices[it + 1])
                it++;
            low = prices[it];

            while (it < nDays - 1 && prices[it] <= prices[it + 1])
                it++;
            high = prices[it];

            maxProfit += high - low;
        }
        return maxProfit;
    }
};
