#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

/*
 * task: find the vowel with the maximum frequency & find the consonant with the maximum frequency
 *
 * goal: return the sum of the 2 frequencies
 *
 * intuition:
 * use a hash map to store the frequency of vowel and consonant
 * */
class Solution
{
  public:
    int maxFreqSum(std::string s)
    {
        std::unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u'};
        std::unordered_map<char, int> freq;

        for (const auto ch : s)
            freq[ch]++;

        int vowelcnt{}, consonantcnt{};
        for (const auto [c, cnt] : freq)
            if (vowels.count(c))
                vowelcnt = std::max(vowelcnt, cnt);
            else
                consonantcnt = std::max(consonantcnt, cnt);

        return vowelcnt + consonantcnt;
    }
};
