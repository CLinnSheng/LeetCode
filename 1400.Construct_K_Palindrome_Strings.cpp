#include <string>
#include <unordered_map>

/*
 * Goal: Find whether if u can use all the characteers in s to construct k palindrome string
 *
 * Intuition:
 * We need to construct k palindrome by using all the characters but the
 * characters doesnt have to follow the original sequence in s.
 * So we need to count the number of characters for each character.
 * A palindrome can construct by all even number character or with all even number and only 1 odd number character
 * So in order to check whether can construct k palindrome or not we need to check how many number of odd character is
 * there it must be at most k time Time Complexity: O(n) Space Complexity: O(n)
 * */
class Solution
{
  public:
    bool canConstruct(std::string s, int k)
    {
        if (s.length() < k)
            return false;

        std::unordered_map<char, int> charCount;
        for (const auto &c : s)
            charCount[c]++;

        int oddCount{};
        for (const auto &[_, freq] : charCount)
            if (freq % 2)
                oddCount++;

        return oddCount <= k;
    }
};
