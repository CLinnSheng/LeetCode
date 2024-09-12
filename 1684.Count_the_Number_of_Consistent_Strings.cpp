#include <string>
#include <unordered_set>
#include <vector>
#include <iostream>
#include <ios>

/*
Given a string "allowed" contained distinct character
A string is consistent if all characters in the string appear in the string allowed
Goal: Find out the number of stings in words that has the string allowed

Intuition: Since we need to check does every characters from each string from words is it exist in the allowed string or not
We can use set data structure to store the characters from string "allowed" and then iterate through the array of strings to chcek whether does each string is consistent or not

Time Complexity: O(m + n * k)
- m is the length of string allowed as we iterate through to populate the set data strucutre
- n is the number of string in the words and k is longest string in words (at here we considering the worst case)

Space Complexity: O(m)
*/

class Solution 
{
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        std::unordered_set<char> characters;
        for (const auto& c : allowed)
            characters.insert(c);
            
        int cnt = 0;
        
        for (const auto& word : words)
        {
            bool consistent = true;
            
            for (const auto& c : word)
                if (characters.count(c) == 0)
                {
                    consistent = false;
                    break;
                }
            
            if (consistent) cnt++;
        }
        
        return cnt;
    }
};