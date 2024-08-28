#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>

/*
Goal: Return the longest substring without repeating chracters
Intuition: Non-repeating -> set & substring -> Sliding Window
Basically we can use set data structure & sliding window to solve it by keep expanding the window until found the repeated characters
when found the repeated characters keep reduce the size of window until no repeated characters
TKAE NOTE: SUBSTRING (CONSEQUENCE CHARACTERS)
*/

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        

        std::unordered_set<char> set;
        int left = 0, right = 0;
        int maxSize = 0;
        
        for (; right < s.length(); right++) {
            if (set.count(s[right]) == 0) 
                maxSize = std::max(maxSize, right - left + 1);
            
            else 
                // keep reduce the size until no repeated characters
                while (set.count(s[right]))
                    set.erase(s[left++]);
            set.insert(s[right]);
        }
                    
        return maxSize;
    }
};