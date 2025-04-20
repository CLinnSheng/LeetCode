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
        std::vector<std::vector<std::string>> answer;

        std::unordered_map<std::string, std::vector<std::string>> map;

        for (const auto &str : strs)
        {
            std::string temp{str};
            // sort the string
            std::sort(temp.begin(), temp.end());

            map[temp].emplace_back(str);
        }

        for (const auto &[_, vec] : map)
            answer.emplace_back(vec);

        return answer;
    }
};
