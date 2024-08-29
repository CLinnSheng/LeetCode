#include <bits/stdc++.h>
#include <ios>
#include <iostream>

/*
Goal: Return the length of the longest repeating character replacement (number of replacement is k)
Intuition: Can use sliding window algorithm by keep tracking the number of each character 
We must always keep track of the longest repeating character in the window
How do we know when is time to shift the window? --> when the number of replacement character exceed k
Time Complexity: O(n)
*/

class Solution {
public:
    int characterReplacement(std::string s, int k) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::vector<int> alphabet(26, 0);
        
        int length = s.length(), start = 0, end = 0;
        int max_length = 0;
        int cnt = 0; // To keep track of the current longest repeating character
        
        if (length == 0) return 0;
        
        while (end < length) {
        
            alphabet[s[end] - 'A']++;
            
            // To keep track of the current longest repeating character
            cnt = std::max(cnt, alphabet[s[end] - 'A']);
            
            // To check if the number of character swapped exceed k
            // if exceed we shift the window (left pointer)
            if (end - start + 1 - cnt > k)
                alphabet[s[start++] - 'A']--;

            max_length = std::max(max_length, end - start + 1);

            end++;
        }
        
        return max_length;
    }
};