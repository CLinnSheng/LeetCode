#include <algorithm>
#include <iostream>
#include <string>
#include <ios>
#include <vector>

/*
Goal: Return the longest substring containing each vowel an even number of times
Constraint: The substring must contain all 5 vowels (a, e, i, o, u) at even number of tiems 0 also included

Intuition: We cant use sliding window because we cant tell in the further right hand side whether there exists another a if a already odd
We can use bitmask data structure to store the count of each vowel
we want to store the bitmask at every indices of vowel, because we want to find the longest so we just take the longest minus the shortest
How bitmask work, if we already have odd a at i then i + 1 is also a so i ^ i + 1 equal to 0 means we have even a right now

Time Complexity: O(n)
Space Complexity: O(32) because of 32 possible combinations of vowel count and --> O(1)
*/

class Solution 
{
public:
    int findTheLongestSubstring(std::string s) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // Store the masks of all letters in the array
        std::vector<int> characters(26, 0);
        characters['a' - 'a'] = 1;
        characters['e' - 'a'] = 2;
        characters['i' - 'a'] = 4;
        characters['o' - 'a'] = 8;
        characters['u' - 'a'] = 16;
        
        // Store the prefix XOR value at every vowel index, have 32 combinations because of 2^5
        std::vector<int> mp(32, -1);
        int max_length = 0;
        int curr_prefix_XOR = 0;
        
        for (int i = 0; i < s.length(); i++)
        {
            
            curr_prefix_XOR ^= characters[s[i] - 'a'];
            
            // only update if the index is an vowel, so we dont have to run for every characters
            if (mp[curr_prefix_XOR] == -1 && curr_prefix_XOR != 0)
                mp[curr_prefix_XOR] = i;
                
            max_length = std::max(max_length, i - mp[curr_prefix_XOR]);
        }
        
        return max_length;
    }
};