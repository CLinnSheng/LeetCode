#include <string>
#include <vector>

/*
 * Goal: Delete thne minimum possible number of characters from s to make it
 * fancy Fancy String: no three consecutive characters are equal
 *
 * Intuition: Has a vector to store the same number of characters at a sequence
 * and then after that resize to 2 if any of them equal or greater than 3
 *
 * Edge cases: Where u remove a characters from a sequence more than 4 will
 * create a sequence of characters with more than 3 consecutive characters also
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * Alternative use a variable to keep track of the count to determine whether
 * include the characters or not
 * */
class Solution {
public:
  std::string makeFancyString(std::string s) {

    if (s.length() <= 2)
      return s;

    // std::string ans{};
    // std::vector<std::string> storage;
    // std::string temp{};
    //
    // for (int i{}; i < s.length(); i++) {
    //   if (temp.length() == 0)
    //     temp += s[i];
    //   else if (temp[0] != s[i]) {
    //     storage.emplace_back(temp);
    //     temp = s[i];
    //   } else
    //     temp += s[i];
    // }
    //
    // if (temp.length() != 0)
    //   storage.emplace_back(temp);
    //
    // for (std::string str : storage) {
    //   if (str.length() >= 3)
    //     str.resize(2, str[0]);
    //   ans += str;
    // }
    //
    std::string ans{s[0]};
    int cnt{1};
    char prevChar = s[0];

    for (int i{1}; i < s.length(); i++) {
      if (s[i] == prevChar)
        cnt++;
      else {
        cnt = 1;
        prevChar = s[i];
      }

      if (cnt < 3)
        ans += s[i];
    }
    return std::move(ans);
  }
};
