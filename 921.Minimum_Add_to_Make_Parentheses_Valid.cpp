#include <cinttypes>
#include <cstdlib>
#include <deque>
#include <ios>
#include <iostream>
#include <string>

/*
 * Goal: Return the minimum number of moves required to make s valid
 * Intuition: Use a stack data structure to store the characters in the string
 * pop the element out of the stack if got opposite char
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int minAddToMakeValid(std::string s) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int len = s.length();
    if (len == 1)
      return 1;

    std::deque<char> stack;
    int i = 0;

    while (i < len) {
      if (stack.empty())
        stack.emplace_back(s[i]);
      else if (s[i] == ')' && stack.back() == '(')
        stack.pop_back();
      else
        stack.emplace_back(s[i]);
      i++;
    }
    return stack.size();
  }
};
