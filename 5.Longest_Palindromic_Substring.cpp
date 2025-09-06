#include <string>
#include <vector>

/*
 * Given a string & find the longest palindrome.
 *
 * Intuition:
 * The naive approach is actually trying out every single possible substring.
 * And then check whether is it palindrome or not
 * The time complexity will be O(N^3) --> N^2 (Double loop) + N (Checking palindrome)
 *
 * If you notice on how we check the substring is it a palindrome or not.
 * We actually check from the first and last letter then slowly move towards the center.
 * We can observe that if the previous substring of [i + 1, j - 1] is palindrome and then str[i] == str[j] then [i, j]
 * definitely is a substring This reduce the time complexity to O(n^2) We can use dp/memoziation
 */
class Solution
{
  public:
    std::string longestPalindrome(std::string s)
    {
        int len(s.length());

        // Base Case
        if (len == 1)
            return s;

        int maxLen{}, startingIndex{};
        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

        // Start from the back, is much more easier
        for (int i{len - 1}; i >= 0; i--)
            for (int j{i}; j < len; j++)
            {
                // Check the character
                // Check the string [i + 1, j -1]
                if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;

                    if (j - i + 1 > maxLen)
                    {
                        maxLen = j - i + 1;
                        startingIndex = i;
                    }
                }
            }
        return s.substr(startingIndex, maxLen);
    }
};
