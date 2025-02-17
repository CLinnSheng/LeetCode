#include <string>
#include <unordered_map>

/*
 * n tiles where each tile has one letter printed on it.
 * Goal: Return the number of possibile non-empty sequences of letters you can make using the letters
 *
 * Intuition:
 * By using brute force way of trying every single letter at each position.
 * and then backtrack if we cant go on with the current combination.
 * Have a hash map to map the character with the frequency
 * and then a hash set to store the combinations.
 *
 * Actually we dont need a hash set to store the unique combiniations, because we are iterating through the map
 * so we wont have duplicate combinations
 *
 * HINT: DRAW  IT OUT IN A TREE DECISION GRAPH, WILL HAVE A BETTER UNDERSTANDING
 * Time Complexity: O(N!) because trying all possible combinations --> N factorial
 * */
class Solution
{
  private:
    void helper(int &answer, std::unordered_map<char, int> &map)
    {
        for (auto &[key, val] : map)
            if (val > 0)
            {
                answer++;
                val--;
                helper(answer, map);
                val++;
            }
    }

  public:
    int numTilePossibilities(std::string tiles)
    {
        std::unordered_map<char, int> map;
        int answer{};

        for (const auto &tile : tiles)
            map[tile]++;

        helper(answer, map);

        return answer;
    }
};
