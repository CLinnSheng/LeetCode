#include <string>
#include <vector>

/*
 * Goal: Return an array of string that is a substring of another word.
 *
 * Intuition:
 * By brute force we checking every single word in the words array with another word. And then when checking substring
 * we checking all possible substring Time Complexity: O(m^2 * n^2)
 *
 * How can we optimize this?
 * If we observe the
 * */
class Solution
{
  public:
    std::vector<std::string> stringMatching(std::vector<std::string> &words)
    {
        std::vector<std::string> answer;

        for (int i{}; i < words.size(); i++)
            for (int j{}; j < words.size(); j++)
                if (i != j && words[j].find(words[i]) != std::string::npos)
                {
                    answer.emplace_back(words[i]);
                    break;
                }

        return answer;
    }
};
