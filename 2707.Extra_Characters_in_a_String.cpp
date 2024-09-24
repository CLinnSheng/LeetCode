#include <ios>
#include <iostream>
#include <stirng>
#include <vector>

/*
 * break s into one or more non-overlapping substrings such that each substring
is present in dictionary. There may be some extra characters in s which are not
present in any of the substrings.

Return the minimum number of extra characters left over if you break up s
optimally.

Intuition: First come in mind is use sliding window method to solve but the
problem is we do not know when to move the left pointer We need to keep track of
the smallest s on every single index --> This lead to using dp where dp[i] is
the smallest number in [0:i]

1) Bottom up approach
we have to build up from the right because is easier to detect whether the
substr is in the dictioanry or not or else if from the left we are limited by
the left pointer for example aaleet well leet is in the library, our left
pointer is always fixed at index 0, so will be v tedious and hard to check if
start from the left

*/
class Solution {
public:
  int minExtraChar(std::string s, std::vector<std::string> &dictionary) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int len = dictionary.size();
    if (len == 0)
      return 0;

    std::vector<int> dp(len + 1, 0);

    for (int i = 1; i <= len; i++) {
      // assume the character added is an extra char
      dp[i] = dp[i - 1] + 1;
    }
  }
};
