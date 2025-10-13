#include <algorithm>
#include <string>
#include <vector>

/*
 * In one operation, select any index such that words[i - 1] and words[i] are anagrams and deletes words[i] from words
 * Keep perform as long as any index statisfies this conditions
 *
 * Goal: Return words after performing all operation
 *
 * Anagram: Word or phrase formed by rearranging the letters
 *
 * Intuition:
 * We can just sort each string and then compare
 * string.
 *
 * Time Complexity: O(nLlgL)
 * */
class Solution
{
  public:
    std::vector<std::string> removeAnagrams(std::vector<std::string> &words)
    {
        std::vector<std::string> answer;
        answer.push_back(words[0]);

        for (int i{1}; i < words.size(); i++)
        {
            std::string str1{answer.back()}, str2{words[i]};
            std::sort(str1.begin(), str1.end()), std::sort(str2.begin(), str2.end());

            if (str1 != str2)
                answer.push_back(words[i]);
        }
        return answer;
    }
};
