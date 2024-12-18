#include <deque>
#include <vector>

/*
 * Special Discount:
 * Buy ith item will receive a discount equivalent to price[j] where j i s the
 * minimum index such j > i and prices[j] <= prices[i]. Otherwise you will not
 * receive any discount at all
 *
 * Goal: Return an array where answer[i] is the final price you will pay for the
 * ith item of the shop after the special discount
 *
 * Intuition:
 * By naive approach use a double loop to find the index where the prices is
 * smaller than the outer loop Time Complexity: O(n^2) Space Complexity: O(n)
 *
 * Instead of double looping to find out the next smaller item.
 * Take note that we are finding the next samller item for each item, so we can
 * use stack. A monotomic stack which is increasing to hold those items that
 * havent undergo discount
 * This will be more efficient because we dont have to check every single index
 * for each price As the one at the top of the stack couldnt get a discount that
 * means those at lower which has smaller value also cannot have discount also
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  std::vector<int> finalPrices(std::vector<int> &prices) {

    std::deque<int> stack;
    std::vector<int> ans(prices.begin(), prices.end());

    for (int i{}; i < prices.size(); i++) {
      while (!stack.empty() && prices[i] <= prices[stack.back()]) {
        int index{stack.back()};
        stack.pop_back();
        ans[index] -= prices[i];
      }
      stack.emplace_back(i);
    }
    return ans;
  }
};
