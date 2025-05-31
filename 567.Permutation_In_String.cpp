#include <string>
#include <unordered_map>

/*
 * Goal: Check whether s2 contains a permutation of s1 or not
 *
 * Intuition:
 * We need to check whether s2 contians a permutation of s1 or not
 * so basically s2 must at least has the length of s1
 * In another word we are checking s1 is inside s2 or not but sequence doesnt matter
 * so what we really need is just the information of frequency for each character in s1.
 *
 * We can use a sliding window of size s1 to slide through s2
 * And have another array of 26 characters of hashmap to store the frequency of each character in s1
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool checkInclusion(std::string s1, std::string s2)
    {
        // Base Case
        if (s2.length() < s1.length())
            return false;

        std::unordered_map<int, int> map1, map2;
        for (int i{}; i < s1.length(); i++)
        {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        // Check for the first length1
        int matches{}; // Var to store the number of match character
        for (int i{}; i < 26; i++)
            if (map1[i] == map2[i])
                matches++;

        // Sliding Window
        int left{}, right(s1.length());
        while (right < s2.length())
        {
            if (matches == 26)
                return true;

            // Moving the window
            // right pointer
            int ch{s2[right] - 'a'};
            map2[ch]++;
            // Check whether is it a new character or not
            if (map1[ch] == map2[ch])
                matches++;
            else if (map1[ch] + 1 == map2[ch])
                matches--;

            // left pointer
            ch = s2[left] - 'a';
            map2[ch]--;
            // Check whether is the characer from s1 got remove or not
            if (map1[ch] == map2[ch])
                matches++;
            else if (map2[ch] + 1 == map1[ch])
                matches--;

            left++;
            right++;
        }
        return matches == 26;
    }
};
