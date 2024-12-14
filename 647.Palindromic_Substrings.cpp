#include <string>
#include <vector>

/*
 * Goal: Return the number of palindrom substrings.
 *
 * Intuition:
 * By using naive approach, we will be having double for loop to check every
 * single possible substrings is it a palindrome or not. this will take O(n^2) &
 * then checking the palindrom will be taking another O(n) So the total time
 * complexity will be O(n^3)
 *
 * We can further optimize this by using dynamic programming because we have
 * been repeating checking some of the same substring we can use dp to optimize
 * it to O(n^2)
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * */
class Solution {
public:
  int countSubstrings(std::string s) {

    int len(s.length());
    std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

    int ans{};

    for (int i{len - 1}; i >= 0; i--)
      for (int j{i}; j < len; j++)
        if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1])) {
          dp[i][j] = true;
          ans++;
        }

    return ans;
  }
};
