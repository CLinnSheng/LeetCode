#include <string>
#include <vector>

/*
 * Intuition: Building the string according to the lsp matrix
 * lcp[i][j] stands for the substring[i,n] & substring[j, n] and the value
 * represent the length of the equal prefix so if lcp[i][j] > 0 means that s[i]
 * == s[j]
 *
 * after building the string, we must validate the string through the lcp matrix
 * 1. if (s[i] == s[j])
 *    then lcp[i][j] == 1 + lcp[i + 1][j + 1] because
 * 2. else
 *    then lcp[i][j] must equal to 0 because they have no common prefix
 * Time Complexity: O(n^2)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  std::string findTheString(std::vector<std::vector<int>> &lcp) {

    int len = lcp.size();
    if (lcp[0][0] != len)
      return "";

    std::string ans(len, '\0');
    int index = 0;
    char currentChar = 'a';

    for (; index < len; index++) {
      if (ans[index])
        continue;

      if (currentChar > 'z')
        return "";

      ans[index] = currentChar;

      for (int i = index; i < len; i++)
        if (lcp[index][i])
          ans[i] = ans[index];

      currentChar += 1;
    }

    if (ans.find('\0') != std::string::npos)
      return "";

    for (int i = len - 1; i >= 0; i--)
      for (int j = len - 1; j >= 0; j--) {
        if (ans[i] == ans[j]) {
          if (i == len - 1 || j == len - 1) {
            if (lcp[i][j] != 1)
              return "";
          } else if (lcp[i][j] != lcp[i + 1][j + 1] + 1)
            return "";
        } else if (lcp[i][j])
          return "";
      }
    return ans;
  }
};
