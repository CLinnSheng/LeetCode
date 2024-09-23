/*
 * Given that u can climb either 1 or 2steps at a time
 * Goal: Return the number of distinct ways to climb to the top which is n
 *
 * Intuition: At every step we either came from stepping 1 step or 2 step
 * so we can make use of the computed steps to count for the next step
    Time Complexity: O(n)
    Space Complexity :O(1)
 * */
class Solution {
public:
  int climbStairs(int n) {

    if (n == 2)
      return 2;
    if (n == 1)
      return 1;

    int first = 1;
    int second = 2;
    int res = 0;

    // Bottom up approach
    for (int i = 2; i < n; i++) {
      res = first + second;
      first = second;
      second = res;
    }
    return res;
  }
};
