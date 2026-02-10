#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

/*
 * Goal: Given an array of strings, group the anagrams together.
 *
 * Constraints:
 * strs[i] only consists of lowercase English letters.
 *
 * Intuition:
 * The brute force way will be just simply loop through the array and check whether each string has the same number of
 * character with the string or not. But this is very inefficient. Time Complexity: O(n^3)
 *
 * What makes an anagrams is that each string has the same number of alphabets. So storing the number of alphabets in
 * each string is the key
 *
 * Are we able to furhter optimize it by maybe reducing the number of loop? Because to search thorugh the character is a
 * must action and cannot be avoidable. What we can do is has a hash map to store a vector of anagrams string. Since
 * anagram has the same number of character for every single character, then if we sort them then they must be the same
 * string.
 * Time Complexity: O(m*n lgn)
 *
 * We can further optimze it to O(n)
 * if we code our own key for the map which just simply use the number of character as a key.
 *
 * */
class Solution
{
  public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const auto &str : strs)
        {
            // Building our own key
            std::vector<int> freq(26, 0);

            for (const auto &ch : str)
                freq[ch - 'a']++;

            std::string key{};
            for (const auto &i : freq)
                key += "#" + std::to_string(i);

            map[key].push_back(str);
        }

        std::vector<std::vector<std::string>> answer;
        for (const auto &[_, strs] : map)
            answer.emplace_back(strs);

        return answer;
    }
};
