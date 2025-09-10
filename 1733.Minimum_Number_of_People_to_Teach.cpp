#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <vector>
/*
 * m users, 2 users can communicate with each other if know a common language
 * languages[i] - set of languages ith user know
 * friendships[i] = [ui, vi] denote a friendship between user ui and vi
 * Can choose one language & teach it to some users so that all fren can communicate
 *
 * Goal: Return the minimum number of users need to teach
 *
 * Intuition:
 * eg: languages = [[2], [1,3], [1,2], [3]]
 * friendships = [[1,4], [1,2], [3,4], [2,3]]
 * 1 -> 4,2 (2)
 * 2 -> 1,3 (1,3)
 * 3 -> 2,4 (1,2)
 * 4 -> 1,3 (3)
 * First friendship either 1 or 4 or 2 need to learn new language
 * 2nd friendship either 1 or 2 need to learn new language
 * 3rd friendship either 3 or 4 need to learn new language
 * 4th friendship either 1 & 3 or 4 learn a new language
 * We try to find the language that learn by the user that can maximize the number of people involve
 *
 * We can be greedy? -> by selecting the most popular language then check whether does all the communication can work or
 * not. if cant then proceed to the next language
 * Time Complexity: O(M*N)
 * */
class Solution
{
  public:
    int minimumTeachings(int n, std::vector<std::vector<int>> &languages, std::vector<std::vector<int>> &friendships)
    {
        std::unordered_set<int> cannotCommunicate;

        // Find out those who cannot communicate
        for (const auto &friendship : friendships)
        {
            bool canCommunicate{false};
            std::unordered_map<int, int> map;

            for (const auto &language : languages[friendship[0] - 1])
            {
                map[language]++;
            }

            for (const auto &language : languages[friendship[1] - 1])
            {
                if (map.count(language))
                {
                    canCommunicate = true;
                    break;
                }
            }

            // Insert into the set
            if (!canCommunicate)
            {
                cannotCommunicate.insert(friendship[0]);
                cannotCommunicate.insert(friendship[1]);
            }
        }

        std::vector<int> knowLanguage(n + 1, 0);
        int maxCnt{};
        for (const auto &fren : cannotCommunicate)
        {
            // Loop through the language it know then get the most common language they speak
            for (const auto &language : languages[fren - 1])
            {
                knowLanguage[language]++;
                maxCnt = std::max(maxCnt, knowLanguage[language]);
            }
        }

        return cannotCommunicate.size() - maxCnt;
    }
};
