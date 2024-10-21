#include <functional>
#include <string>
#include <unordered_set>

/*
 * Goal: Return the number of unique substrings that the given string can be
 * split into
 *
 * Intuition: For every character we can choose to include it or not, so this
 * leading me to thinking to use dfs and backtracking to solve it We will be
 * using a set data structure to keep track what substrings we have, we will
 * backtack when we encounter the same set
 *
 * Time Complexity: O(2^n * n^2)
 * Space Complexity: O(2^n * n) At worst the recursive call stack can go up to n
 * and the hash set at worst will have O(2^n) different substring & and each
 * substring is O(N) O(2^n * n + n (recursiv call stack)) -> O(2^n * n)
 * */

class Solution {
public:
  int maxUniqueSplit(std::string s) {

    std::unordered_set<std::string> encounteredSubset;

    std::function<int(const int)> dfs_backtracking = [&](const int currIndex) {
      // Base Case
      if (currIndex == s.length())
        return 0;

      int res{};

      for (int i{currIndex}; i < s.length(); i++) {
        std::string temp{s.substr(currIndex, i - currIndex + 1)};

        if (encounteredSubset.count(temp))
          continue;

        // dfs
        encounteredSubset.emplace(temp);
        res = std::max(res, 1 + dfs_backtracking(i + 1));

        // backtracking
        encounteredSubset.erase(temp);
      }

      return res;
    };
    return dfs_backtracking(0);
  }
};
