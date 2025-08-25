#include <climits>
#include <vector>

/*
 * Goal: Find the cheapest path within k moves
 *
 * NOTE: k means number of stops so if k = 1, we can traverse 3 nodes which mean the middle 1 is the stop
 *
 * Intuition: At first thought, im thinking of using dijkstra algorithm but it
 * has to do some modifications on it because we got a constraint we can only
 * has k stop. So it will not be so efficient. THen im thinking of switching to
 * bellman ford algorithm which will be much more efficient
 * Is a bit similar to BFS.
 * Time Complexity: O(E * K)
 * */
class Solution
{
  public:
    int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src, int dst, int k)
    {
        std::vector<int> prices(n, INT_MAX);
        prices[src] = 0;

        for (int i{}; i <= k; i++)
        {
            // Make a copy of the prices & make changes on the copy 1
            // because we traversing every single edge.
            std::vector<int> temp(prices.begin(), prices.end());

            for (const auto &flight : flights)
            {
                auto from{flight[0]}, to{flight[1]}, price{flight[2]};

                // Only BFS on the visited node.
                if (prices[from] == INT_MAX)
                    continue;

                auto flightPrice{prices[from] + price};
                if (temp[to] > flightPrice)
                {
                    temp[to] = flightPrice;
                }
            }

            prices = std::move(temp);
        }

        return prices[dst] == INT_MAX ? -1 : prices[dst];
    }
};
