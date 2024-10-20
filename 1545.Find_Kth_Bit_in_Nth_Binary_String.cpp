/*
 * Given n & k, binary string Sn is formed as below: (3steps)
 * 1. S1 = "0"
 * 2. Si = Si-1 + "1" + reverse(invert(Si - 1)) for i > 2
 * eg:
 * S1 = 0
 * S2 = 0 1 1
 * S3 = 011 1 001
 * S4 = 01111001 1 01100001
 * The length of each level will be 2^n - Si-1
 *
 * Intuition:
 * - The middle of the string will be always "1"
 * - The characters before the mid level will be the original characters that do
 * not undergoes any invert which means is also equal to its previous level So,
 * we start from the highest level and check the k and go down to the base case
 *  The time complexity will be O(n) because we just go down the level and not
 * really dive into the string Space Complexity: O(1)
 *
 * */
#include <cmath>
class Solution {
public:
  char findKthBit(int n, int k) {
    if (k == 1)
      return '0';
    int length = std::pow(2, n) - 1;
    bool invert = false;

    while (length > 1) {
      int middle = length / 2 + 1;

      // If k is middle, then it shuold be '1' by default else '0'
      if (middle == k)
        return invert ? '0' : '1';
      else if (k > middle) {
        invert = !invert;
        k = 1 + length - k;
      }

      length /= 2;
    }

    // If we reach until only left 1 character in the string, then the first
    // character should be '0' always or else '1'
    return invert ? '1' : '0';
  }
};
