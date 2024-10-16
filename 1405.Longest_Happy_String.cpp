#include <functional>
#include <queue>
#include <string>
#include <utility>
#include <vector>

/*
 * A string is happy:
 *
    s only contains the letters 'a', 'b', and 'c'.
    s does not contain any of "aaa", "bbb", or "ccc" as a substring.
    s contains at most a occurrences of the letter 'a'.
    s contains at most b occurrences of the letter 'b'.
    s contains at most c occurrences of the letter 'c'.
 *
 * Goal: Return the longest possible happy string
 *
 * Intuition:
 * To produce the longest happy string, we always choose the letter with the
 most count
 * eg: we got 4a and 1b
 * 1. Start from the longest
 *  aabaa
 * 2. Start from the lowest
 *  baa
 *
 *  We got make use of priority queue data structure
 *  We get the character of the most frequent and then check
 *  When we encounter 3 occurrences of letter, we will choose the next character
 *
 *  Time Complexity: O(nlgn)
 *  Space Complexity: O(n)
 * */
class Solution {
public:
  std::string longestDiverseString(int a, int b, int c) {
    std::priority_queue<std::pair<int, char>, std::vector<std::pair<int, char>>,
                        std::less<std::pair<int, char>>>
        maxHeap;

    if (a)
      maxHeap.emplace(a, 'a');
    if (b)
      maxHeap.emplace(b, 'b');
    if (c)
      maxHeap.emplace(c, 'c');

    std::string ans = "";

    while (!maxHeap.empty()) {
      auto [cnt, currentChar] = maxHeap.top();
      maxHeap.pop();

      int ans_len = ans.length();
      if (ans_len >= 2 && ans[ans_len - 1] == currentChar &&
          ans[ans_len - 2] == currentChar) {
        if (maxHeap.empty())
          break;

        auto [cntNxt, nxtChar] = maxHeap.top();
        maxHeap.pop();

        ans += nxtChar;
        cntNxt--;
        if (cntNxt)
          maxHeap.emplace(cntNxt, nxtChar);
      } else {
        ans += currentChar;
        cnt--;
      }

      if (cnt)
        maxHeap.emplace(cnt, currentChar);
    }
    return std::move(ans);
  }
};
