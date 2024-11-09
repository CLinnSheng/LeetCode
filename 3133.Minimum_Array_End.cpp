#include <utility>
using ll = long long;

/*
 * Given n & x, construct an array of positive integers of size n.
 * But the array must be in ascending order & result of bitwise AND between all
 * elements in the array equal to x
 *
 * Intuition:
 * Since need to be in ascending order and thus the x must be the first element
 * in the array. Since all elements in the array has to go through bitwise AND
 * and therefore that means at minimum each element in the array must have the
 * same set bit as the x. So we just need to add 1 to x every single time for
 * the next element and OR it with X to make sure it has to same set bit
 * position
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 *
 * Actually we can optimize this and solve it in a clever way because if u
 * notice that we only mess with the '0' bit in x so we basically need to add 1
 * n times to all the '0' bit in x but instead of having adding '1' operation we
 * can actually add it according to the bit for example if n is 5 which is 100
 * we need to iterate until n - 1 which is 011 so we just need to add '1' & '1'
 * to corresponding '0' bit in x which saves up a lot of computational time
 * instead of adding 1 by 1
 *
 * */
class Solution {
public:
  ll minEnd(int n, int x) {
    // ll ans{x};
    //
    // for (int i{}; i < n - 1; i++) {
    //   ans++;
    //   ans |= x;
    // }
    //
    // return std::move(ans);
    ll ans{x};
    int pointer_x{1}, pointer_n{1};

    while (pointer_n <= n - 1) {
      // set the bit for '0' in x
      if (!(pointer_x & x)) {
        // only set for the particular '0' bit in x
        if (pointer_n & n - 1)
          ans |= pointer_x;
        pointer_n <<= 1;
      }
      pointer_x <<= 1;
    }
    return std::move(ans);
  }
};
