#include <cstddef>
#include <string>
#include <unordered_map>
#include <vector>
/*
 * Goal: return the zigzag string with the given number of rows
 * eg: abcdefg
 * a     g
 * b   f
 * c e
 * d
 *
 * Intuition: actually we can treat the characters as number for example if
 * number of rows is 3 then abcdefg will be so the string in zigzag will be 1 a
 * e 2 b d f 3 c   g so we return aebdfcg
 *
 * so what we can do is we use a hash data structure to store the index and the
 * character
 *
 * Time Complexity: O(nlgn) because we using map instead of unordered_map
 * Space Complexity: O(n)
 *
 * we can optimize it by using vector to reduce it to O(n)
 * */
class Solution {
public:
  std::string convert(std::string s, int numRows) {

    std::size_t len{s.length()};
    if (numRows == 1 || len < numRows)
      return s;

    std::vector<std::string> rows(std::min(numRows, static_cast<int>(len)));

    int currRow{};
    bool isDescend = false;

    for (const char &c : s) {
      rows[currRow] += c;
      if (currRow == 0 || currRow == numRows - 1)
        isDescend = !isDescend;

      currRow += isDescend ? 1 : -1;
    }

    std::string ans{};

    for (const auto &s : rows)
      ans += s;

    // std::map<int, std::string> hash;
    //
    // std::size_t len{s.length()};
    // int currIndex{};
    // bool movingDownward = true;
    //
    // for (int i{}; i < len; i++) {
    //   if (movingDownward && currIndex < numRows) {
    //     hash[currIndex] += s[i];
    //
    //     if (currIndex == numRows - 1) {
    //       movingDownward = false;
    //       currIndex--;
    //       continue;
    //     }
    //     currIndex++;
    //
    //   } else {
    //     hash[currIndex] += s[i];
    //
    //     if (currIndex == 0) {
    //       movingDownward = true;
    //       currIndex++;
    //       continue;
    //     }
    //     currIndex--;
    //   }
    // }
    //
    // std::string ans{};
    // for (const auto &[_, val] : hash)
    //   ans += val;

    return ans;
  }
};
