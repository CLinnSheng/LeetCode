#include <string>

/*
 * Given a 0-indexed binary string having an even length
 * Beautiful String definition:
 *  - each substring has an even length
 *  - Contain only 1's or only 0's
 *
 * Can change any character in s to 0 or 1
 * Goal: Return the minimum number of changes required to make the string s
 * beautiful
 *
 * Intuition: Since each substring has an even length, so the minimum length of
 * substring. Therefore, we will break the string into blocks of substring with
 * length equal to 2,
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution {
public:
  int minChanges(std::string s) {

    std::size_t len{s.length()};
    int ans{};

    for (int i{}; i < len; i += 2)
      if (s[i] != s[i + 1])
        ans++;

    return std::move(ans);
  }
};
