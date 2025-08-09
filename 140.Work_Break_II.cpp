#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Add space in s sto construt a sentence where each word is a valid dictionary word
 * Goal: Return all possible sentences in any order
 *
 * Intuition:
 * This is also actually a tree dicision problem, at every index we determine whether is this a valid word or not. If it
 * is we will continue to dfs or else we will just backtrack until we reach the last index For checking we can use a
 * hash set so we can achieve in O(1)
 * Time Complexity: O(n * 2^n) --> n is due to the building of the substr
 * */
class Solution
{
  public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::unordered_set<std::string> dict(wordDict.begin(), wordDict.end());
        std::vector<std::string> answer;

        std::function<void(const int &, const std::string)> dfs_backtracking = [&](const int &index,
                                                                                   const std::string currStr) {
            if (index == s.length())
            {
                answer.emplace_back(currStr);
                return;
            }

            for (int i{index}; i < s.length(); i++)
            {
                std::string subStr{s.substr(index, i - index + 1)};

                // Checking
                if (dict.find(subStr) != dict.end())
                {
                    if (currStr.size())
                        dfs_backtracking(i + 1, currStr + " " + subStr);
                    else
                        dfs_backtracking(i + 1, subStr);
                }
            }
        };
        dfs_backtracking(0, "");
        return answer;
    }
};
