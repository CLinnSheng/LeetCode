#include <climits>
#include <cstdlib>
#include <vector>

/*
 * Given a m*n matrix and we are able to choose any 2 adjacent elements of
 * matrix and multiply it by -1 Goal: Find the maximum summation of the matrix's
 * element
 *
 * Intuition:
 * At first thought, is by using greedy to scan through the matrix and choose
 * the best pair to multiply it by -1 when we encounter it Greedy and
 * backtracking but this is very costly because O(2^n^2) & also very hard to
 * code it.
 *
 * But if we observe, we can see for any matrix with odd number of negative
 * numbers can reduced to minimum 1 no matter what and for even number we can
 * keep choosing 2 adjacent element to mutiply by 1 until there is no negative
 * number So we just simply scan through to matrix, find out the minimum abs
 * value element and the number of negative elements
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(1)
 * */
using ll = long long;

class Solution {
public:
  ll maxMatrixSum(std::vector<std::vector<int>> &matrix) {
    ll ans{};
    int smallestVal{INT_MAX};
    int numberOfNegativeElement{};

    for (const auto &row : matrix)
      for (const auto &element : row) {
        ans += std::abs(element);
        smallestVal = std::min(smallestVal, std::abs(element));
        numberOfNegativeElement += element < 0 ? 1 : 0;
      }

    if (numberOfNegativeElement % 2)
      // this is the tricky part, we have to times 2 instead of just 1
      ans -= 2 * smallestVal;

    return ans;
  }
};
