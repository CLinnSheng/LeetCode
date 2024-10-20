#include <climits>
#include <vector>

/*
 * Goal: Find the cheapest path within k moves
 * Intuition: At first thought, im thinking of using dijkstra algorithm but it
 * has to do some modifications on it because we got a constraint we can only
 * has k stop. So it will not be so efficient. THen im thinking of switching to
 * bellman ford algorithm which will be much more efficient Time Compleixty:
 * O(E*k) Space Compleixty: O(V)
 * */
class Solution {
public:
  int findCheapestPrice(int n, std::vector<std::vector<int>> &flights, int src,
                        int dst, int k) {

    std::vector<int> prices(n, INT_MAX);
    prices[src] = 0;

    // iterate k + 1 times because the number of stops is the number of nodes
    // between start and end noe (not inclusive)
    for (int i = 0; i <= k; i++) {
      // have a temp prices because of the 'k' stops if not we might move more
      // than 1 step at once
      std::vector<int> temp(prices.begin(), prices.end());

      for (const auto &flight : flights) {
        int s = flight[0];
        int d = flight[1];
        int w = flight[2];

        // only move the node we hav reached
        if (prices[s] == INT_MAX)
          continue;

        int cost = prices[s] + w;
        if (cost < temp[d])
          temp[d] = cost;
      }

      prices = std::move(temp);
    }
    return prices[dst] == INT_MAX ? -1 : prices[dst];
  }
};
