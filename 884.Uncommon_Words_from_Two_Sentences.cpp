#include <string>
#include <unordered_map>
#include <vector>
#include <ios>
#include <iostream>

/*
Goal: Return a list of uncomon words
Intuition: Have a set data structure that store all the words, when it found another just delete it from the structure

Time Complexity: O(nmlgnm)
Space Complexity: O(n + m)
*/

class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::unordered_map<std::string, bool> storage;

        int i = 0;
        while (i < s1.size()) {
            int pos = s1.find(" ", i);
            if (pos == std::string::npos) pos = s1.size(); // Handle last word
            auto temp_string = s1.substr(i, pos - i);
            storage[temp_string] = storage.count(temp_string)? false : true;
            i = pos + 1;
        }
        
        // Process s2
        i = 0;
        while (i < s2.size()) {
            int pos = s2.find(" ", i);
            if (pos == std::string::npos) pos = s2.size(); // Handle last word
            auto temp_string = s2.substr(i, pos - i);
            storage[temp_string] = storage.count(temp_string)? false : true;
            i = pos + 1;
        }
         
        
        std::vector<std::string> ans;
        
        for (auto const& [word, val] : storage)
            if (val == true)
                ans.emplace_back(word);
                
        return ans;
    }
};