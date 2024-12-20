#include <algorithm>
#include <cctype>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

/*
 * Goal: Return an array of string where answer[i] is the correcto word for query = queries[i]
 * Operation on queries:
 *
    When the query exactly matches a word in the wordlist (case-sensitive), you should return the same word back.
    When the query matches a word up to capitlization, you should return the first such match in the wordlist.
    When the query matches a word up to vowel errors, you should return the first such match in the wordlist.
    If the query has no matches in the wordlist, you should return the empty string.

    Intuition:
    Use a hash map & set data structure to easily check whether does it contain in the wordlist or not
    the checking only takes O(1) for both hash map and set
    To deal with vowel errors, we just simply replace the vowel with a *, so any vowel character can be place on the *
    Time Complexity: O(n)
    Space Complexity: O(n)
 * */
class Solution
{
  private:
    bool checkIsVowel(const char &c)
    {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    std::string changeVowelWord(std::string s)
    {
        for (int i{}; i < s.length(); i++)
            if (checkIsVowel(s[i]))
                s[i] = '*';
        return s;
    }

  public:
    std::vector<std::string> spellchecker(std::vector<std::string> &wordList, std::vector<std::string> &queries)
    {
        std::vector<std::string> ans;
        std::unordered_set<std::string> exactWord;
        std::unordered_map<std::string, std::string> capWord;
        std::unordered_map<std::string, std::string> vowelWord;

        int len(wordList.size());

        for (int i{}; i < len; i++)
        {
            exactWord.insert(wordList[i]);

            std::string temp{wordList[i]};
            std::transform(temp.begin(), temp.end(), temp.begin(), [](const char &c) { return std::tolower(c); });

            // we only update the hashmap once for matches word up to capitlization & vowel erros
            // because we only need to return the first such match in the wordlist
            if (capWord.count(temp) == 0)
                capWord[temp] = wordList[i];

            std::string temp_vowel{changeVowelWord(temp)};
            if (vowelWord.count(temp_vowel) == 0)
                vowelWord[temp_vowel] = wordList[i];
        }

        for (const auto &query : queries)
        {
            std::string temp{query};
            std::transform(temp.begin(), temp.end(), temp.begin(), [](const char &c) { return std::tolower(c); });

            // now checking all the 3 possible ways
            if (exactWord.count(query))
                ans.emplace_back(query);
            else if (capWord.count(temp))
                ans.emplace_back(capWord[temp]);
            else if (vowelWord.count(changeVowelWord(temp)))
                ans.emplace_back(vowelWord[changeVowelWord(temp)]);
            else
                ans.emplace_back("");
        }
        return ans;
    };
};
