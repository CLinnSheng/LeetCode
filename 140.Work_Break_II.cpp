#include <functional>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Add space in s to construct a sentence where each word is a valid dictionary word
 * So we are trying to split the string s such that each word is a valid dictionary word
 * First think to efficeintly check whether is it a valid dicitionary word.
 * Lets store the wordDict in a hashset instead -> O(1)
 * We want to find all the possible combination --> Backtracking
 * At each index we will determine want to split or not by checking is it a valid word
 *
 * Time Complexity: O(n * 2^n)
 * 2^n possible combination because at each index we can either choose to split or not
 * And then for each combination we will do a linear time of creating the substr
 * Space Complexity: O(2^n)
 * */

class Solution
{
  public:
    std::vector<std::string> wordBreak(std::string s, std::vector<std::string> &wordDict)
    {
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::vector<std::string> ans;
        std::string currStr{};

        std::function<void(const int)> backtracking = [&](const int index) {
            if (index == s.length())
            {
                ans.push_back(currStr);
                return;
            }

            for (int i{index}; i < s.length(); i++)
            {
                // O(n)
                std::string substr = s.substr(index, i - index + 1);

                if (words.count(substr))
                {
                    auto prev = currStr;

                    currStr += currStr.empty() ? substr : " " + substr;
                    backtracking(i + 1);

                    //  backtracking
                    currStr = prev;
                }
            }
        };
        backtracking(0);
        return ans;
    }
};
