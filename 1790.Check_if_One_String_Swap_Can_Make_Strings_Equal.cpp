#include <array>
#include <string>
using std::string;

/*
 * Goal: Return true if possible to make both strings equal by performing at most one
 * string swap on exactly one of the strings.
 * Constraint: We can only have 1 maximum swap
 *
 * Intuition:
 * In order to let 2 strings equal is by having the same number of characters for each character
 * Use a hash map
 * And we can also track the number of diff char at each index.
 *
 * */
class Solution
{
  public:
    bool areAlmostEqual(string s1, string s2)
    {
        if (s1 == s2)
            return true;

        std::array<int, 26> map1{}, map2{};
        int diffChar{};

        for (int i{}; i < s1.length(); i++)
        {
            if (s1[i] != s2[i])
                diffChar++;

            if (diffChar > 2)
                return false;

            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        for (int i{}; i < 26; i++)
            if (map1[i] != map2[i])
                return false;
        return true;
    }
};
