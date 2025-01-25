#include <string>
using std::string;

/*
 * Merge the string by adding letters in alternating oder, starting with word1. If a string
 * is longer than the other, append the additional letters onto the end of the merged string.
 *
 * Intuition:
 * Just using 2 pointer, each pointer on each string
 *
 * Time Complexity: O(n + m)
 * Space Complexity: O(n + m)
 * */

class Solution
{
  public:
    string mergeAlternately(string word1, string word2)
    {
        std::string ans{};

        int len1(word1.length()), len2(word2.length());
        int pointer1{}, pointer2{};
        bool turn_1{true};

        while (pointer1 < len1 && pointer2 < len2)
        {
            ans += (turn_1 ? word1[pointer1++] : word2[pointer2++]);
            turn_1 = !turn_1;
        }

        while (pointer1 < len1)
            ans += word1[pointer1++];

        while (pointer2 < len2)
            ans += word2[pointer2++];

        return ans;
    }
};
