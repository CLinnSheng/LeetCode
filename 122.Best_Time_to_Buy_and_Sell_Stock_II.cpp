#include <vector>

/*
 * Same as the orignal version but this 1 allow
 * to have as many trascantion as possible
 *
 * Intuition:
 * We need to buy low & sell high and as many transaction as possible
 * So we will be greedy and try to get as many transaction as possible
 * whenever we found a local minimum then we will proceed to find the local maximum
 *
 * Time Complexity: O(N)
 * Space Complexity: O(1)
 * */

class Solution
{
  public:
    int maxProfit(std::vector<int> &prices)
    {
        int profit{};

        int days(prices.size());
        int low{prices[0]}, high{prices[0]}, it{};

        while (it < days - 1)
        {
            // finding the local minimum price
            while (it < days - 1 && prices[it] >= prices[it + 1])
                it++;
            low = prices[it];

            // finding the local maximum price
            while (it < days - 1 && prices[it] <= prices[it + 1])
                it++;
            high = prices[it];

            profit += high - low;
        }
        return profit;
    }
};
