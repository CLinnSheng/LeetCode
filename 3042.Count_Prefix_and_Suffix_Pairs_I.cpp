#include <string>
#include <vector>

/*
 * Goal: Return the number of index pairs (i, j) such that i < j and isPrefixAndSuffix(words[i], words[j]) is true
 *
 * Intuition:
 * Using naive approach where we can simply solve it with double loop
 * but the time complexity will be O(N^2 * L)
 * */
class Solution
{
  public:
    int countPrefixSuffixPairs(std::vector<std::string> &words)
    {
        int answer{};

        for (int i{}; i < words.size(); i++)
            for (int j{i + 1}; j < words.size(); j++)
            {
                if (words[i] > words[j])
                    continue;

                if (words[j].find(words[i]) == 0 && words[j].rfind(words[i]) == words[j].length() - words[i].length())
                    answer++;
            }
        return answer;
    }
};
