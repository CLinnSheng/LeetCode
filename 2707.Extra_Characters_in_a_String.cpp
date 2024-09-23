#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Break s into one or more non-overlapping substring such that eac substring is
 present in dictionary.
 * Goal: Return the minimum number of extra charaters after break up
 *
 * Intuition: Since want to find the minimum number of extra character after
 breaking up
 * we can use dp to store the min number of character at every index
 * where dp[i] = min characters in the range [0,i]
  we build up the dp from the back because is easier
  Time Complexity: O(n^2)
  Space Complexity: O(n)
 };
 * */

class Solution {
public:
  int minExtraChar(string s, vector<string> &dictionary) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int length = s.length();
    if (length == 0)
      return 0;

    std::unordered_set<string> dictionary_;
    for (const auto &word : dictionary)
      dictionary_.insert(word);

    std::vector<int> dp(length + 1, 0);

    for (int start = length - 1; start >= 0; start--) {
      // we assume the new character added is not from the dict initially
      dp[start] = dp[start] + 1;

      for (int end = start; end < length; end++) {
        std::string sub_str = s.substr(start, end - start + 1);
        if (dictionary_.count(sub_str))
          // Since we found a word that exists in the dict
          // now we update the dp to see whether the current 1 is smaller or
          // after remove the word in the dict is smaller
          dp[start] = std::min(dp[start], dp[end + 1]);
      }
    }
    return dp[0];
  }
};
