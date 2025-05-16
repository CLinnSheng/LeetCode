#include <string>
#include <vector>

/*
 * Subsequence of words is alternating if for any 2 consecutive string in the sequence
 * Their corresponding elements at the same indices in groups are different.
 * TAKE NOTE:: groups are binary array
 *
 * Goal: Return the longest alternating subsequence from words
 *
 * Intuition:
 * We need to be greedy, include the string whenever is possible.
 * Edge cases like: 01111111, 000000, 111111101. Is always better to select the words whenever is possible.
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<std::string> getLongestSubsequence(std::vector<std::string> &words, std::vector<int> &groups)
    {
        std::vector<std::string> ans;
        int prevIndex{-1};

        for (int i{}; i < words.size(); i++)
            if (groups[i] != prevIndex)
            {
                ans.emplace_back(words[i]);
                prevIndex = groups[i];
            }

        return ans;
    };
};
