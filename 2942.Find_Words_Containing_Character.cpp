#include <string>
#include <vector>

/*
 * Goal: Return an array of indices containing the character x for every word in words
 *
 * Intuition:
 * Since the words size and words[i] len is not big we can solve it through brute force
 * which it just loop through the words and loop through every word in words
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<int> findWordsContaining(std::vector<std::string> &words, char x)
    {
        std::vector<int> answer;

        for (int index{}; index < words.size(); index++)
            for (int i{}; i < words[index].length(); i++)
                if (words[index][i] == x)
                {
                    answer.emplace_back(index);
                    break;
                }

        return answer;
    }
};
