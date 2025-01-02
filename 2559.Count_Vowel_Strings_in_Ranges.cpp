#include <string>
#include <string_view>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return an array ans of size queries, length where answer[i] is the answer to the ith query
 * Each query ask us to find the number of strings oresent in the range li to ri (inclusive)
 * of words that start and end with a vowel
 *
 * Intuition:
 * We can solve it naively through a double inner loop
 * Theres some observation we can see is there are overlapping range
 * where if we done it naively we have been doing some things multiple things
 *
 * We can actually optimize it by preprocess to find the number of strings in the range from 0 to ith
 * Prefix/Preprocess
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * */
class Solution
{
  private:
    std::unordered_set<char> VOWELS{'a', 'e', 'i', 'o', 'u'};

    bool helper(const std::string_view &str)
    {
        return VOWELS.count(str[0]) && VOWELS.count(str[str.length() - 1]);
    }

  public:
    std::vector<int> vowelStrings(std::vector<std::string> &words, std::vector<std::vector<int>> &queries)
    {
        std::vector<int> answer;
        std::vector<int> prefixCount(words.size() + 1, 0);

        for (int i{1}; i <= words.size(); i++)
            prefixCount[i] = prefixCount[i - 1] + helper(words[i - 1]);

        for (int i{}; i < queries.size(); i++)
            answer.emplace_back(prefixCount[queries[i][1] + 1] - prefixCount[queries[i][0]]);

        return answer;
    }
};
