// Time Complexity: Lets consider the worst case, the digit is map to number
// which have 4 characters, and then it has 4 possible string. SO this lead to
// O(4^n)
//  and every time we concatenate the string this is O(n)
//  Hence total time complexity is O(n * 4^n)
//  Space Complexity: O(4^n)
#include <string>
#include <vector>

class Solution {
public:
  const std::vector<std::string> number = {"",    "",    "abc",  "def", "ghi",
                                           "jkl", "mno", "pqrs", "tuv", "wxyz"};

  std::vector<std::string> letterCombinations(std::string digits) {
    int len = digits.length();
    if (len == 0)
      return {};

    std::vector<string> ans;

    std::function<void(const int, const std::string)> dfs_backtracking =
        [&](const int index, const std::string curr_words) {
          if (index == digits.length()) {
            ans.emplace_back(curr_words);
            return;
          }

          std::string pad_words = number[digits[index] - '0'];

          for (int i = 0; i < pad_words.length(); i++)
            dfs_backtracking(index + 1, curr_words + pad_words[i]);
        };

    dfs_backtracking(0, "");
    return std::move(ans);
  }
};
