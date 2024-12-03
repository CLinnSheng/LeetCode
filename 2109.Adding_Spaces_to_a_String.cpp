#include <string>
#include <vector>

/*
 * Goal: Return the string with spaces
 *
 * Intuition: Use 2 pointer approach
 * 1 pointer on the spaces array & another pointer on the string, s
 *
 * Time Complexity: O(s.length)
 * Space Complexity: O(s.length)
 *
 * */
class Solution {
public:
  std::string addSpaces(std::string s, std::vector<int> &spaces) {
    std::string ans;
    int spaces_ptr{};

    for (int i{}; i < s.length(); i++) {
      if (spaces_ptr < spaces.size() && i == spaces[spaces_ptr]) {
        ans += " ";
        spaces_ptr++;
      }
      ans += s[i];
    }
    return ans;
  }
};
