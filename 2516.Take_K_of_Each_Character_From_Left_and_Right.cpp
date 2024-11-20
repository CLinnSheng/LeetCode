#include <string>
/*
Given that string s consisting of charactrers 'a', 'b' & 'c'. Each minute may take either from the left
or right character of s.
Goal: Return the minimum numbert of minutes needed for you to take at least k of each character or return -1 if not possible

Intuition: Since need to take k of each character
first we check whether is it possible or not
REMEMBER we are trying to minimize the characters we will take
it will be very hard to determine the leftmost & rightmost part because we can really predict the future.
A clever way will be solving in a reversible way, instead of minimizing the leftmost & rightmost which is  the nubmer of characters take we just focus on the middle part and try to maximize it
Since we are trying to find a maximum contiguous array, this can be solve by using sliding window.
We will keep moving the right pointer and move the left pointer when the array is not valid
Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    int takeCharacters(std::string s, int k) {
        std::vector<int> charCount(3, 0);
        for (const char& c : s)
            charCount[c - 'a']++;

        // Checking whether is it possible
        for (int i{}; i < 3; i++)
            if (charCount[i] < k)
                return -1;

        int left{}, right{};
        std::vector<int> window(3, 0);
        int windowSize{};

        for (; right < s.length(); right++) {
            window[s[right] - 'a']++;

            // Moving the left pointer of the window
            // Shrinking the window if contain one of the char contain too much such that the one out of the window is less than k.
            while (left <= right && charCount[0] - window[0] < k || charCount[1] - window[1] < k || charCount[2] - window[2] < k) {
                window[s[left] - 'a']--;
                left++;
            }
            windowSize = std::max(windowSize, right - left + 1);
        }
        return s.length() - windowSize;
    }
};