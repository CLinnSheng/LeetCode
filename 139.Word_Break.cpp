#include <string>
#include <vector>

/*
 * Given a string s & a dictionary of strings wordDict, return true if s can be
 * segmented into a space-seperated sequence of one or more dictionary words
 * Note: The same word in the dictionary can be reused multiple times
 *
 * Intuition:
 * eg s = "leetcode" & wordDict = ["leet", "code"]
 * leetcode can be segmented as leet & code
 *
 * We can use brute force by checking at every single index whether it can be
 * formed by the string from the word or not for example an index i will be
 * iterate through the string s then keep checking the substring from 0 & i does
 * it contain in the dict if we found it then the starting index will be
 * changing from 0 to i But there is a problem with this which is if the
 * substring that lead to true is at 5 instead of 4
 *
 * How do we solve this issues. We can actually use dynamic programming to check
 * every single possible We will iterate from the back & then check whether does
 * it cointain in the dict or not Then we will also need to check the previous
 * word before this word whether it contain or not
 *
 * Time Complexity: O(m*n*L)
 * Space Complexity: O(n)
 * */

class Solution
{
  public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        int len(s.length());
        std::vector<bool> dp(len + 1, false);
        dp[len] = true;

        // O(n)
        for (int i{len - 1}; i >= 0; i--)
            // O(m)
            for (const auto &word : wordDict)
            {
                int len_dictWord(word.length());
                // check whether does the string start from index i is from the dict or not
                // O(L)
                if (i + len_dictWord <= len && s.substr(i, len_dictWord) == word)
                    dp[i] = dp[i + len_dictWord];
                if (dp[i])
                    break;
            }

        return dp[0];
    }
};
