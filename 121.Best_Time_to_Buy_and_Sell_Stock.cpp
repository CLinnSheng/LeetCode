#include <vector>

/*
 * prices[i] is the price on ith day.
 * Choose a single day to buy and choose another day to sell
 * Goal: Return the maximum profit you can achieve.
 *
 * Intuition:
 * We only can choose 1 day to buy and another day in the future to sell.
 * The brute force will just simply trying all possible combination of days to buy and sell
 * But this will take O(N^2)
 * How can we optimiz it?
 * Since the days is important we cannot just simply sort it.
 * There is one algo we can make use of is sliding window.
 * So we will maintain the window to find the best buy and selling price.
 * We will keep moving the right pointer as long as the sell day is lesser than buy day.
 * Only move the left pointer if and only if the buy price is greater than the sell day. (Means that we found a cheap
 * buy day)
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int maxProfit(std::vector<int> &prices)
    {
        int left{}, right{1};
        int days(prices.size());

        int maxProfit{};

        while (right < days)
        {
            if (prices[left] < prices[right])
                maxProfit = std::max(maxProfit, prices[right] - prices[left]);
            else
                left = right;

            right++;
        }

        return maxProfit;
    }
};
