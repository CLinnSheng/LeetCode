#include <string>
#include <string_view>
#include <unordered_map>
using std::string;

/*
 * Goal: Return the number of vowel substrings in word.
 * eg: word = 'unicornarihan'
 * Output: 7
 * the substring not neccessarily need to have only 1 vowel for each vowel, it can have more than 1.
 *
 *
 * Intuition:
 * The most easiest way is actually brute force to try out find all the possible substring.
 * We can optimize this by skipping those consonant.
 * But this at worst also O(n^2)
 *
 * We can optiimze it by using sliding window because we only need to check the substring with only vowels. So whenever
 * the substring only contain vowels, we will keep moving the right pointer. Only until we met a consonant, then move
 * the left pointer to right pointer + 1, to explore new substring
 * but how do we deal with moving the window when it already has the 5 vowel, and the next few character also vowel.
 * So we can actually use a clever way which is find atmostK vowel - atmostK-1 vowel.
 * So the function will return all the posibilies from 0 to K number of vowel in a substring.
 * So the result will just return the number of substring with K vowel.
 * Time Complexity: O(n)
 * */
class Solution
{
  private:
    bool isVowel(const char &c)
    {
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    int atMostK(const std::string_view &word, const int &K)
    {
        int res{}, n(word.size());
        int left{}, right{};
        std::unordered_map<char, int> map;

        for (; right < n; right++)
        {
            // check whether is it vowel or not
            if (!isVowel(word[right]))
            {
                // not then move the left pointer to right pointer + 1
                // because we only want substring with vowel
                left = right + 1;
                map.clear();
                continue;
            }

            map[word[right]]++;

            // deal with window size greater than k
            while (map.size() > K)
            {
                map[word[left]]--;

                if (map[word[left]] == 0)
                    map.erase(word[left]);

                left++;
            }

            // all possibile substrings from 0 to K vowel
            res += right - left + 1;
        }
        return res;
    }

  public:
    int countVowelSubstrings(string word)
    {
        return atMostK(word, 5) - atMostK(word, 4);
    }
};
