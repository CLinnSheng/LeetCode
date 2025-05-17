#include <algorithm>
#include <string>
#include <string_view>
#include <vector>

/*
 * Both groups & words have the same length n.
 * Hamming Distance between 2 strings at which the corresponding characters are different but both of them must be
 * sharing the same length.
 *
 * Select the longest subsequence such that the subsequence following these rules:
 * i. Adjacent indices in the subsequence, their corresponding groups must be different
 * ii. Hamming distance must be 1
 *
 * NOTE:
 * i. string in words may be unequal in length.
 * ii. groups arent binary array can have any arbitary value.
 *
 * Intuition:
 * We cant be greedy at here like the first question the stirng in words are different in len,
 * and for every string in the subsequence we chose must be the same len.
 * So we need to try out all every single possible len of string in the words.
 * So, this lead use to naively try every single string.
 * So from this naive approach, the only way we could optimize is actually through dp.
 * so dp[i] means the longest subsequence we can build by including words[i].
 * We also need another array to keep track of all the indices of string in the subsequence
 *
 * How we build the dp?
 * So what we basically do is for every i we will find the longest subsequence from 0 to i (not include i)
 * Time Complexity: O(N^2 * L)
 * */
class Solution
{
  private:
    bool checkString(const std::string_view &s1, const std::string_view &s2)
    {
        if (s1.length() != s2.length())
            return false;

        int diff{};

        for (int i{}; i < s1.length(); i++)
        {
            diff += s1[i] != s2[i];
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

  public:
    std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string> &words, std::vector<int> &groups)
    {
        int n(words.size());
        std::vector<int> dp(n, 1), prevIndex(n, -1);
        // var to keep track the last string of the longest subsequence
        int maxIndex{};

        for (int i{1}; i < words.size(); i++)
        {
            for (int j{}; j < i; j++)
            {
                if (checkString(words[i], words[j]) && dp[j] + 1 > dp[i] && groups[i] != groups[j])
                {
                    dp[i] = dp[j] + 1;
                    prevIndex[i] = j;
                }
            }

            // Always keep track of the last string of the longest subsequence
            if (dp[i] > dp[maxIndex])
                maxIndex = i;
        }

        std::vector<std::string> ans;
        for (int i{maxIndex}; i >= 0; i = prevIndex[i])
            ans.emplace_back(words[i]);

        std::reverse(ans.begin(), ans.end());
        return ans;
    }
};
