#include <bits/stdc++.h>
#include <climits>
#include <iostream>

/*
Given 2 strings s & t
Goal: Return the shortest substring of s that cointains every character in t

Intuition: Since we want to keep track of characters, we can use hash map data structure
& since gonna deal with substring of a particular length in s, we can use sliding window algo
1. Store the characters of t in a hash map first
2. Then we iterate through string s through a sliding window
3. We keep move the right pointer until we got all the characters of t
4. Then we keep move the left pointer until all characters are covered to find the min size
5. Repeat this process until l & r reach the end
*/
class Solution {
public:
// Goal: Find the minimum window(substring) with characters
// Intuition: Since involve with string, we can use hash map to
// keeptrack of the number of characters and a counter
// we try to find the range of consisting all character of t
// And then we adjust the window size from the left

    std::string minWindow(std::string s, std::string t) {
        
        std::ios_base :: sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int length1 = s.length(), length2 = t.length();
        
        // We finding t in s, length of t must be smaller than s
        if (length2 == 0 || length2 > length1) return "";
        
        std::unordered_map<char, int> freq;
        
        for (const auto& c : t)
            freq[c]++;
            
        int counter = length2;
        int left = 0, right = 0;
        int min_length = INT_MAX, min_index;
        
        while (right < length1) {
            
            // if found the characters of t ( > 0)
            if (freq[s[right]] > 0) counter--;
            
            // Update the hashmap & move the right pointer
            freq[s[right]]--;
            right++;
            
            // If found all the character of t in s
            // We need to move our left pointer for new window to check any other possible shorter substring
            while (counter == 0) {
                if (right - left < min_length) {
                    min_length = right - left;
                    min_index = left;
                }
                
                freq[s[left]]++;
                
                // if we delete one of the characters in t
                // > 0 because all the characters of t in the hashmap will be 0 if we found it in s
                // others character will be negative
                if (freq[s[left]] > 0) counter++;
                
                left++;
            }
        }
        
        return min_length == INT_MAX ? "" : s.substr(min_index, min_length);
    }
};
