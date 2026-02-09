#include <string>
#include <unordered_map>

/*
 * Goal: Check whether t is an anagram of s or not
 * Anagram: A string is formed by rearranging the order of the character
 *
 * Intuition:
 * In order to form an anagram from a string, both of the string must have the same number of character for each of the
 * character Use a hash map to keep track of the freq of each char
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool isAnagram(std::string s, std::string t)
    {
        std::unordered_map<char, int> map_s, map_t;

        // Base case
        if (s.length() != t.length())
            return false;

        for (const auto ch : s)
            map_s[ch]++;
        for (const auto ch : t)
            map_t[ch]++;

        return map_s == map_t;
    }
};
