#include <cmath>
#include <functional>
#include <string>
#include <vector>
#define MOD 1000000007
/*
 *
You are given a list of strings of the same length words and a string target.

Your task is to form target using the given words under the following rules:
target should be formed from left to right.
To form the ith character (0-indexed) of target, you can choose the kth character of the jth string in words if
target[i] = words[j][k]. Once you use the kth character of the jth string of words, you can no longer use the xth
character of any string in words where x <= k. In other words, all characters to the left of or at index k become
unusuable for every string. Repeat the process until you form the string target.

Notice that you can use multiple characters from the same string in words provided the conditions above are met.

Return the number of ways to form target from words. Since the answer may be too large, return it modulo 10^9 + 7.
 *
 * Intuition:
 * Actually this is a decision tree problem. At every index we have 2 decisions whether we want to use
 * the current index or skip it.
 * So, we can solve it naively through dfs & backtracking
 * But the time complexity will be exceeded the time limit
 * So we can optimize it by using caching which is dynamic programming.
 * Besides that, we might face situation where more than 1 word at the same index has the same character
 * We no need to iterate through the whole words array, we can just use an array to keep track of the number of
 * character at the specific index from all the words.
 *
 * Time complexity: O(wordLength * targetLength + wordsLength * wordLength)
 * */

class Solution
{
  public:
    int numWays(std::vector<std::string> &words, std::string target)
    {
        int n_word(words.size()), len_word(words[0].length());
        int len_target(target.length());

        std::vector<std::vector<int>> freq_char(len_word, std::vector<int>(26, 0));
        // O(wordLength * wordsLength)
        for (const auto &word : words)
            for (int i{}; i < word.length(); i++)
                freq_char[i][word[i] - 'a']++;

        // Top-down approach
        // O(wordLength * targetLength)
        std::vector<std::vector<int>> dp(len_word, std::vector<int>(len_target, -1));
        std::function<long long int(const int &, const int &)> dfs_backtracking = [&](const int &index_word,
                                                                                      const int &index_target) {
            if (index_target == target.length())
                return 1;
            if (index_word == len_word || len_target - index_target > len_word - index_word)
                return 0;

            // check whether we solve this subproblem before or not
            if (dp[index_word][index_target] != -1)
                return dp[index_word][index_target];

            int ch{target[index_target] - 'a'};
            // Skip the current index_word
            auto count{dfs_backtracking(index_word + 1, index_target)};
            // Use the current index_word
            count += freq_char[index_word][ch] * dfs_backtracking(index_word + 1, index_target + 1);

            dp[index_word][index_target] = count % MOD;
            return dp[index_word][index_target];
        };
        return dfs_backtracking(0, 0);
    }
};
