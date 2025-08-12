#include <algorithm>
#include <string>
#include <vector>

/*
 * Alien language - English lowercase but in different order. Order of the alphabet is some permutation of lowercase
 * letter Goal: Return true if the given words are sorted lexicographically in the alien language
 *
 * Intuition:
 * We can either create a custom comparator or comparing the adjacent words
 * The time complexitty will be O(mlgn) & O(m * n)
 * */
class Solution
{
  public:
    bool isAlienSorted(std::vector<std::string> &words, std::string order)
    {
        // Build the dictionary
        std::vector<int> alphabets(26, 0);
        for (int i{}; i < 26; i++)
            alphabets[order[i] - 'a'] = i;

        // Custom comparator
        // return std::is_sorted(words.begin(), words.end(), [&](const std::string &word1, const std::string &word2) {
        //     for (int i{}; i < std::min(word1.length(), word2.length()); i++)
        //         if (word1[i] != word2[i])
        //             return alphabets[word1[i] - 'a'] < alphabets[word2[i] - 'a'];
        //
        //     return word1.length() < word2.length();
        // });

        // Compare side by side
        for (int i{}; i < words.size() - 1; i++)
        {
            for (int j{}; j < words[i].length(); j++)
            {
                // Same prefix but shorter length means it should be at the front
                if (j == words[i + 1].length())
                    return false;

                if (words[i][j] != words[i + 1][j])
                {
                    if (alphabets[words[i][j] - 'a'] > alphabets[words[i + 1][j] - 'a'])
                        return false;
                    break;
                }
            }
        }
        return true;
    }
};
