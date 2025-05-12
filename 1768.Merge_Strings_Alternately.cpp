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
        std::string answer{};
        int len1(word1.length()), len2(word2.length());
        bool turn{};
        int ptr1{}, ptr2{};

        while (ptr1 < len1 && ptr2 < len2)
        {
            answer += turn ? word2[ptr2++] : word1[ptr1++];
            turn = !turn;
        }

        while (ptr1 < len1)
            answer += word1[ptr1++];

        while (ptr2 < len2)
            answer += word2[ptr2++];

        return answer;
    }
};
