#include <cstddef>
#include <functional>
#include <string>
#include <vector>

/*
 * Goal: Return the length of the longest special substring of s which occurs at
 * least thrice or -1 if no special substring occurs at least thrice Special: a
 * string is called special if it is made up of only a single character
 * Therefore the substring must be only made up of 1 characters
 *
 * Intuition:
 * 1. Naive Approach
 * Trying all every single possible special subarray & then store it in a
 * hashmap Time Complexity: O(n^2)
 *
 * 2. Optimize from naive approach
 * Instead of using double loop we can use sliding window because we dont have
 * to check if the subarray is not special On top of that because a special
 * subarray might contain more than 1 special subarray for eg: aaaa it contains
 * 3 special subarray, 'a', 'aa', 'aaa', 'aaaa' So to deal with this, we can
 * actually use binary search to try to find through the range of possible
 * length of special subarray
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  int maximumLength(std::string s) {

    std::size_t len{s.length()};
    // Possible range of
    int l{1}, r{(int)len};

    std::function<bool(const int &)> helper = [&](const int &x) {
      std::vector<int> cnt(26, 0);
      int ptr{};

      for (int i{}; i < len; i++) {
        while (s[i] != s[ptr])
          ptr++;
        if (i - ptr + 1 >= x)
          cnt[s[i] - 'a']++;
        if (cnt[s[i] - 'a'] > 2)
          return true;
      }
      return false;
    };

    // Try is it possible to do it with length of 1 subarray
    if (!helper(1))
      return -1;

    // O(lgn)
    while (l + 1 < r) {
      int middle{l + (r - l) / 2};
      // O(n)
      if (helper(middle))
        l = middle;
      else
        r = middle;
    }
    return l;
  }
};
