#include <string>
#include <vector>

/*
 * Goal: Return the number of palindrom substrings.
 *
 * Intuition:
 * By using naive approach, we will be having double for loop to check every
 * single possible substrings is it a palindrome or not. this will take O(n^2) &
 * then checking the palindrome will be taking another O(n) So the total time
 * complexity will be O(n^3)
 *
 * This is similar to longest palindromic, we can actually use the same algo and have another variable that track the
 * total nubmer of palindromic substring We can further optimize this by using dynamic programming because we have been
 * repeating checking some of the same substring we can use dp to optimize it to O(n^2)
 *
 * Time Complexity: O(n^2)
 * Space Complexity: O(n^2)
 * */
class Solution
{
  public:
    int countSubstrings(std::string s)
    {
        int answer{}, len(s.length());
        if (len == 1)
            return 1;

        std::vector<std::vector<bool>> dp(len, std::vector<bool>(len, false));

        for (int i{len - 1}; i >= 0; i--)
            for (int j{i}; j < len; j++)
            {
                // first & last character must match and if the substr [i + 1, j - 1] is a substring
                // then [i, j] is also a palindromic substring
                // edge cases where 1 character & 2 character no need to check [i + 1, j- 1]
                if (s[i] == s[j] && (j - i + 1 <= 2 || dp[i + 1][j - 1]))
                {
                    dp[i][j] = true;
                    answer++;
                }
            }
        return answer;
    }
};
