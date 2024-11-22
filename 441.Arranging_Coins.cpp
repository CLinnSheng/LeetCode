/*
 * Given n coins and need to build a staircase.
 * staircase consists of k rows where the ith row has exactly i coins. The last
 * row can be incomplete
 *
 * Intuition: Have a variable to keep track of the row and then just reduce the
 * n and check whether is it greater than the tracker
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */

class Solution {
public:
  int arrangeCoins(int n) {
    int cnt{};

    while (n >= cnt + 1) {
      cnt++;
      n -= cnt;
    }

    return cnt;
  }
};
