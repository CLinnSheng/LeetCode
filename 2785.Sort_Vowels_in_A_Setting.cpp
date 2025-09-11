#include <algorithm>
#include <string>
#include <unordered_set>
#include <vector>

/*
 * Goals: Simply just return the string s with all the vowels sorted in a setting according to their ascii value
 *
 * Intuition:
 * s[i] can be upper or lower case
 * Since the question didnt ask for any specific setting just sorted according to ascii value. Then is easy, we just
 * need to find out all the vowels in the string and then put it into a vector and sort it. At the same time we need to
 * store all the index of the vowel character
 *
 * */
class Solution
{
  private:
    const std::unordered_set<char> VOWELS{'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};

  public:
    std::string sortVowels(std::string s)
    {
        std::vector<char> vowels;
        std::vector<int> index;
        for (int i{}; i < s.length(); i++)
            if (VOWELS.count(s[i]))
            {
                vowels.emplace_back(s[i]);
                index.emplace_back(i);
            }

        std::sort(vowels.begin(), vowels.end());
        for (int i{}; i < index.size(); i++)
            s[index[i]] = vowels[i];

        return s;
    }
};
