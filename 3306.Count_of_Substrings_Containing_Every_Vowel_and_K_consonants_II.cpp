#include <string>
#include <string_view>
#include <unordered_map>
using std::string;

/*
 * Goal: Return the total number of substrings of word that contain every vowel and exactly k consonants.
 *
 * Intuition:
 * This is almost the same as finding every substrings of containing every vowel.
 * But this 1 need to add 1 more conditoins which is contain k consonants.
 * So we can use the same approach which is sliding window.
 * So this time we will keep moving the window until we met the 2 conditions.
 * But how exactly can we find it or moving the window if the window already met the 2 conditoins.
 * So, the clever things is over here. Once we find the window that meet the 2 conditions. Any characters behind it add
 * to the window, will also meet the 2 conditions no matter whether is it a vowel or consonants. So the window has
 * become at least K consonants and all vowels. So simply just take the length of word and then minus the right pointer
 * */
class Solution
{
  private:
    bool isVowel(const char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    long long atLeastK(const std::string_view &word, const int &k)
    {
        long long res{}, nConsonant{};
        int left{}, right{};
        std::unordered_map<char, int> map;

        for (; right < word.size(); right++)
        {
            // check whether is it a consonant or vowel
            if (isVowel(word[right]))
                map[word[right]]++;
            else
                nConsonant++;

            // checking the window
            while (map.size() == 5 && nConsonant >= k)
            {
                // number of possible substrings with at least k consonant starting from left
                res += word.size() - right;

                if (isVowel(word[left]))
                {
                    map[word[left]]--;

                    if (map[word[left]] == 0)
                        map.erase(word[left]);
                }
                else
                    nConsonant--;

                left++;
            }
        }
        return res;
    }

  public:
    long long countOfSubstrings(string word, int k)
    {
        return atLeastK(word, k) - atLeastK(word, k + 1);
    }
};
