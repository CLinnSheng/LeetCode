#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::vector;

/*
 * Return an array result of length n, where result[i] denotes the number of distinct colors after ith query.
 *
 *
 * Intuition:
 * We can have more than 1 ball having the same color, so what we really matters is how many color are there.
 * So we can have hashmap tracking the number of ball a color have, & each colored ball's color.
 *
 * */
class Solution
{
  public:
    vector<int> queryResults(int limit, vector<vector<int>> &queries)
    {
        // ballMap tracking whats the color of the current ball holding
        // colorMap tracking whats the number of ball holding the exact color
        std::unordered_map<int, int> ballMap, colorMap;
        vector<int> answer;

        for (const auto &query : queries)
        {
            int ball{query[0]}, color{query[1]};
            // check whether already colored or not
            if (ballMap.count(ball))
            {
                int prevColor{ballMap[ball]};
                colorMap[prevColor]--;

                if (colorMap[prevColor] == 0)
                    colorMap.erase(prevColor);
            }
            colorMap[color]++;
            ballMap[ball] = color;

            answer.emplace_back(colorMap.size());
        }
        return answer;
    }
};
