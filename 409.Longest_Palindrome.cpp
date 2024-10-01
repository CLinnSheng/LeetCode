/*
 * Goal: Find the longest palindrome that u can build from the letters of the
 * string Intuition: To build a palindrome u need a pair of same letters, so we
 * need to find the number of pairs of letters in the string, if u couldnt find
 * 1 the longest palindrome u can form autaoatically is 1 Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>

class Solution {
public:
  int longestPalindrome(std::string s) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::unordered_set<char> letters;
    int cnt = 0;

    for (const auto &c : s)
      if (letters.count(c)) {
        cnt += 2;
        letters.erase(c);
      } else
        letters.insert(c);
    return letters.empty() ? std::move(cnt) : std::move(cnt + 1);
  }
};
