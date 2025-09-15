#include <sstream>
#include <string>
#include <unordered_set>
class Solution
{
  public:
    int canBeTypedWords(std::string text, std::string brokenLetters)
    {
        int answer{};
        std::stringstream ss(text);

        std::unordered_set<char> set;
        for (const auto letter : brokenLetters)
            set.insert(letter);

        std::string temp;
        bool brokenChar{false};
        while (ss >> temp)
        {
            for (const auto ch : temp)
            {
                if (set.count(ch))
                {
                    brokenChar = true;
                    break;
                }
            }
            if (!brokenChar)
                answer++;
            brokenChar = false;
        }

        return answer;
    }
};
