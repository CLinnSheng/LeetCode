#include <array>
#include <string>
#include <vector>
/*
 * Check whether the words are sorted lexicographically according to the alien language
 *
 * First thing is we need to build our own dictionary so we know which character come first --> array
 * */
class Solution
{
  public:
    bool isAlienSorted(std::vector<std::string> &words, std::string order)
    {
        std::array<int, 26> dictionary;
        for (int i{}; i < 26; i++)
        {
            dictionary[order[i] - 'a'] = i;
        }

        // Check the words
        for (int i{}; i < words.size() - 1; i++)
        {

            for (int j{}; j < words[i].length(); j++)
            {
                // If same prefix then second word must be longer than first word
                // This condition only trigger when trying to access beyond second word and having the same prefix
                if (j == words[i + 1].length())
                {
                    return false;
                }

                if (words[i][j] != words[i + 1][j])
                {
                    if (dictionary[words[i + 1][j] - 'a'] < dictionary[words[i][j] - 'a'])
                    {
                        return false;
                    }
                    // break and check next word
                    break;
                }
            }
        }
        return true;
    }
};
