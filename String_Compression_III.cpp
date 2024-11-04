#include <string>

/*
 * Goal: Compressed string into length + char eg: aaaabb -> 4a2b
 * Constraint: Maximum length of a character will be 9
 *
 * Intuition: Have a variable to keep track of the count of current character
 * and also another variable that store the conesecutive characters
 *
 * Time Complexity: O(n)
 * Space Complexity: O(N)
 * */

class Solution {
public:
  std::string compressedString(std::string word) {

    std::string comp{};
    char prevChar{word[0]};

    int cnt{1};

    int len(word.length());

    if (len == 1)
      return std::move(std::to_string(cnt) + prevChar);

    for (int i{1}; i < len; i++) {
      if (cnt == 9) {
        comp += std::to_string(9) + prevChar;
        cnt = 1;
        prevChar = word[i];
      } else {
        if (word[i] == prevChar)
          cnt++;
        else {
          comp += std::to_string(cnt) + prevChar;
          cnt = 1;
          prevChar = word[i];
        }
      }
    }
    return std::move(comp + std::to_string(cnt) + prevChar);
  }
};
