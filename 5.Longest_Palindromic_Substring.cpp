#include <cstdint>
#include <string>
#include <vector>

/*
 * Given a string s return the longest palindrome substring in struct
 * Intuition: We want to find substring within a string s but with a condition
 * that the substring must be a palindrome Naive Approach will be using a double
 * loop that will lead to O(n2) and everytime checking the substring is a
 * palindrome will take O(N) The only possible way is to reduce the time
 * complexity of checking palindrome as if 'a' is a palindrome then 'xax' is
 * palindrome or not just check the value of x is it equal or not so basically
 * we using the stored result --> dp We cannot do anything about the O(n2)
 * because theres the way to form substring
 *
 */
class Solution {
public:
  std::string longestPalindrome(std::string s) {

    std::int32_t len = s.length();

    if (len == 0)
      return "";
    if (len == 1)
      return s;

    std::vector<std::vector<int>> dp(len, std::vector<int>(len, 0));

    for (int i = 0; i < len; i++)
      dp[i][i] = 1;

    std::pair<int, int> index = {0, 0};

    for (int i = 0; i < len - 1; i++)
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = 1;
        index = {i, i + 1};
      }

    // from here we building up the dp, so x + "aa" + x the checking will be
    // very simple just check whether x1 equal to x2 and the inner str is
    // palindrome or not from the dp
    for (int sub_str_len = 2; sub_str_len < len; sub_str_len++)
      for (int start = 0; start < len - sub_str_len; start++) {
        int end = start + sub_str_len;
        if (s[start] == s[end] && dp[start + 1][end - 1]) {
          dp[start][end] = true;
          index = {start, end};
        }
      }
    return s.substr(index.first, index.second - index.first + 1);
  }
};
