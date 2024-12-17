#include <algorithm>
#include <queue>
#include <string>
#include <unordered_map>

/*
 * Goal: Return the lexicographically largest repeatLimitedString possible
 * Constraint: Using the charactes of s such that no letter appear more than
 * repeat Limit times in a row.
 *
 * Intuition:
 * Since we need to create the lexicographically largest string possible
 * So we need to have the all the largest character in the front.
 * Therefor, we can make use of heap data structure to always get the largest
 * characetr & a hash map data structure to keep track of the count of
 * character, so that we know how much to add into it.
 *
 * Time Complexity: O(nlgn)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  std::string repeatLimitedString(std::string s, int repeatLimit) {

    // a hash map to keeptrack of the count of characters left
    std::unordered_map<char, int> count;
    for (const auto &ch : s)
      count[ch]++;

    // heap data strucutre to help us to get the largest character every single
    // time
    std::priority_queue<char> maxHeap;
    for (const auto &[character, freq] : count)
      maxHeap.emplace(character);

    std::string ans{};

    while (!maxHeap.empty()) {
      char ch{maxHeap.top()};
      maxHeap.pop();

      // determine how much to append while still following the rules
      int minUse{std::min(repeatLimit, count[ch])};
      ans.append(minUse, ch);
      // update the hash
      count[ch] -= minUse;

      // Push back to the heap if this character havent used finish
      // and check whether there is any character left
      // if no we can use this character anymore because this is the constraint
      if (count[ch] > 0 && !maxHeap.empty()) {
        char next_ch{maxHeap.top()};
        maxHeap.pop();

        ans.append(1, next_ch);
        count[next_ch]--;

        if (count[next_ch] > 0)
          maxHeap.emplace(next_ch);

        maxHeap.emplace(ch);
      }
    }
    return ans;
  }
};
