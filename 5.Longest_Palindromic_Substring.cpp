#include <cstdint>
#include <string>
#include <vector>

/*
 * Given a string & find the longest palindrome.
 *
 * Intuition: By using naive approach double for loop for every single possible
 * comibnation of string and then another for loop to check whether is this a
 * valid palindrome or not
 * Time Complexity: O(n^3)
 *
 * Actually we dont have to check the whole string whether is it a valid
 * palindrome, we can use a much more clever way if s[i] == s[y] and then check
 * whether s[i - 1] == s[y - 1] or not. We can use dp as there is overlapping
 * subproblem & memoziation is implemented Time Complexity: O(n^2) Space
 * Complexity: O(n^2)
 */
class Solution {
public:
  std::string longestPalindrome(std::string s) {
    int len(s.length());
    if (len == 1)
      return s;

    std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));
    int startingIndex;
    int longestLen{};

    for (int i{len - 1}; i >= 0; i--)
      for (int j{i}; j < len; j++)
        if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          if (j - i + 1 > longestLen) {
            longestLen = j - i + 1;
            startingIndex = i;
          }
        }

    return s.substr(startingIndex, longestLen);
  }
};
