#include <algorithm>
#include <string>
#include <vector>

/*
 * Can choose any character in the string and change it to any letter up to k times.
 * Goal: Return the length of the longest substring containing the same letter you can get after performing the above
 * operatoin
 *
 * Intuition:
 * Is the same as longest substring without repeating characters question.
 * We can same apply sliding window algo but with a little tweak to handle repeating characters
 * Allow to replace characters up to k times.
 * So we need keep track of the most frequent characters.
 * Then we can compute out the number of character need to be replaced (Window Size) - Most frequent characeters
 * So if exceed then we move the left pointer in order for the window to be valid
 * We also being greedy at the same time
 *
 * */
class Solution
{
  public:
    int characterReplacement(std::string s, int k)
    {
        std::vector<int> characters(26, 0);
        int left{}, right{}, currCnt{};
        int n(s.length());
        int maxLen{};

        while (right < n)
        {
            characters[s[right] - 'A']++;
            currCnt = std::max(
                currCnt, characters[s[right] - 'A']); // currCnt keeping track of the current most repeating characters.
            // So we will be greedy here by replacing all those not has lesser number of repeating characters

            if (right - left + 1 - currCnt > k) // number of characters need to replaced greater than k
                characters[s[left++] - 'A']--;

            maxLen = std::max(maxLen, right - left + 1);
            right++;
        }

        return maxLen;
    }
};
