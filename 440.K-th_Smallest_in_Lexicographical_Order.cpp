#include <ios>
#include <iostream>
#include <vector>
/*
 * Goal: Return the kth lexciographically smallest integer in the range [1,n]
 *
 * Intuition: Since we want to find the kth smallest integer so is start from
 * the LHS of the tree A clever of reduce the time complexity is to find out
 * where the k would be for example will it be under  1 or 2? and then if it is
 * under 1 will it be under 10 or 11? After finding the possible range we would
 * still continue dfs to find the smaller range until we find the exact position
 *
 * Time Complexity: O(lg10 (n))^2 outer loop is log10n and the inner loop for
 * finding the range is also log10n Space Complexity: O(lg10n)
 */
class Solution {
public:
  int findKthNumber(int n, int k) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    auto find_range = [&n](size_t curr_num) {
      size_t neigh_num = curr_num + 1;
      size_t cnt = 0;

      while (curr_num <= n) {
        // less than or equal because we still want to include n also
        auto min = n + 1 > neigh_num ? neigh_num : n + 1;
        cnt += min - curr_num;
        curr_num *= 10;
        neigh_num *= 10;
      }

      return cnt;
    };

    size_t curr = 1;
    int i = 1;

    while (i < k) {

      auto range = find_range(curr);

      if (range + i <= k) {
        i += range;
        curr++; // can go to the next num because we know is still not enough to
                // reach k
      } else {
        i++;
        curr *= 10;
      }
    }
    return curr;
  }
};
