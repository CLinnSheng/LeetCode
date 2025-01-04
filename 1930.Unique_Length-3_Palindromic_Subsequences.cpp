#include <string>
#include <unordered_map>
#include <unordered_set>

/*
 * Goal: Return the number of unique palindromes of length three that are a subsequences of s.
 *
 * Intuition:
 * We are finding the subsequences of s, so it doesnt need to be in a contiguous subarray.
 * And then the length of palindromes is 3, so we need to focus only on the first and the last character.
 * The easiest way is through brute force, by using 3 pointer
 * But the time complexity will be O(n^3)
 *
 * Is ther any way to optimize this to O(n^2) or even O(n)
 * Yes we can, instead of looping through the string, we can actually make use
 * of Hash set & Hash map to keep track of the count of character in the left & right hand side (precompute)
 * instead of looping it 3 times
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int countPalindromicSubsequence(std::string s)
    {
        // keep track of the palindromes included
        std::unordered_set<std::string> palindromesIncluded;
        // the right hand side we use hash map because we need to know how many left
        std::unordered_map<char, int> rightCount;
        // the left hand set we use hash set because we want to have unique palindomr, so we dont to iterate the same
        // character more than once
        std::unordered_set<char> leftCount;

        for (const auto &c : s)
            rightCount[c]++;

        for (int middle{}; middle < s.length() - 1; middle++)
        {
            rightCount[s[middle]]--;

            // loop through the left hand side to check got palindomre or not
            for (const auto &left : leftCount)
                if (rightCount[left] > 0 && !palindromesIncluded.count(std::string{left, s[middle]}))
                    palindromesIncluded.insert(std::string{left, s[middle]});
            leftCount.insert(s[middle]);
        }
        return palindromesIncluded.size();
    }
};
