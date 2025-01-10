#include <algorithm>
#include <array>
#include <string>
#include <vector>

/*
 * Goal: Return an array of all the universal strings in words1 (Return in any order)
 * Universal String: A string b is a subset of string a if every letter in b occurs in a including multiplicty.
 * or in simpler term a string a from words1 is universal if for every string b in words2, b is a subset of 1.
 *
 * Intuition:
 * We need to check if every letter in b occurs in a or not.
 * So the first thing we need to count all the maximum number of characters of each string from words2
 * And then just iterate thorugh words1 and check every single string from words1 of the count of character is it the
 * same or greater than it
 *
 * Constrains:
 * Only contains lower case letters
 * length of each string is in between 1 to 10
 *
 * Time Complexity: O(m + n)
 * Space Complexity: O(1)
 * */
class Solution
{
  private:
    // O(26) -> O(1)
    bool isSubset(const std::array<int, 26> &source, const std::array<int, 26> &target)
    {
        for (int i{}; i < 26; i++)
            if (source[i] < target[i])
                return false;
        return true;
    }

  public:
    std::vector<std::string> wordSubsets(std::vector<std::string> &words1, std::vector<std::string> &words2)
    {
        std::vector<std::string> answer;
        std::array<int, 26> alphabet_count{};

        // O(10m) -> O(m)
        for (const auto &word : words2)
        {
            std::array<int, 26> temp{};
            // O(10)
            for (const auto &ch : word)
            {
                temp[ch - 'a']++;
                alphabet_count[ch - 'a'] = std::max(alphabet_count[ch - 'a'], temp[ch - 'a']);
            }
        }

        // O(10n) -> O(n)
        for (const auto &word : words1)
        {
            std::array<int, 26> source{};
            // O(10)
            for (const auto &ch : word)
                source[ch - 'a']++;

            // O(1)
            if (isSubset(source, alphabet_count))
                answer.emplace_back(word);
        }
        return answer;
    }
};
