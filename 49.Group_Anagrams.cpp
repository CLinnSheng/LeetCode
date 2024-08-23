#include <bits/stdc++.h>
#include <ios>
using namespace std;

/*
Given an array of strs
Goal: Group the anagrams together and return it
Anagram: word or phrase formed by rearranging the letters of different words or phrase
Intuition: Since want to group anagram, we can use hashtable of key with the sorted strs,
so that the same anagram will be group into same anagram group
Time Complexity: O(n), Space Complexity: O(n)
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if (strs.size() == 0)
            return {{""}};
        
        vector<vector<string>> ans;
        unordered_map<string, vector<string>> hashmap;
        
        for (const auto& str : strs) {
            string temp = str;
            sort(temp.begin(), temp.end());
            hashmap[temp].emplace_back(str);
        }
        
        for (const auto& [key, value] : hashmap)
            ans.emplace_back(value);
            
        return ans;
    }
};