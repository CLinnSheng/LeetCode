#include <string>

/*
 * Goal: Return the minimum number of swaps to make the string balance
 * Intuition: Keep track of the number of imbalance by comparing the number of
 * '[' & ']' if it is ordered in a way that it is imbalance, the value of
 * imbalance will be 0 in the end
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */

class Solution {
public:
  int minSwaps(std::string s) {
    int imbalance{};

    for (const auto &c : s) {
      if (c == '[')
        imbalance++;
      else if (imbalance)
        imbalance--;
    }
    return (imbalance + 1) / 2;
  }
};
