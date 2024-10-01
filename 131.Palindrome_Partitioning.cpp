#include <string>
#include <vector>

// Intuition: DFS and backtracking and also checking whether is it a palindrome
// at the same time Time Complexity: O(2^n * l) 2^n due to splitting and l is
// due to the palindrome checking Space Complexity: O(2^n)
class Solution {
public:
  bool checkPalindrome(const std::string &str) {
    int start = 0, end = str.length() - 1;

    while (start <= end)
      if (str[start++] != str[end--])
        return false;

    return true;
  }

  std::vector<std::vector<std::string>> partition(std::string s) {
    int len = s.length();
    if (len == 0)
      return {{}};

    std::vector<std::vector<std::string>> ans;
    std::vector<std::string> subset;

    dfs_backtracking(ans, subset, 0, s);
    return std::move(ans);
  }

  void dfs_backtracking(std::vector<std::vector<string>> &ans,
                        std::vector<string> &subset, int index,
                        const std::string &str) {
    if (index == str.length()) {
      ans.emplace_back(subset);
      return;
    }

    for (int i = index; i < str.length(); i++)
      if (checkPalindrome(str.substr(index, i - index + 1))) {
        subset.emplace_back(str.substr(index, i - index + 1));
        dfs_backtracking(ans, subset, i + 1, str);
        // back tracking
        subset.pop_back();
      }
  }
};
