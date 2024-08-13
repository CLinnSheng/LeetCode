#include <bits/stdc++.h>
using namespace std;

/*
Intuition: Since anagram is a word or phrase formed by rearranging the letters
we can track the number of characters in both string
*/
class Solution {
public:
    bool isAnagram(string s, string t) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<char, int> freq;

        for (const auto &c : s)
            freq[c]++;

        for (const auto &c : t)
            freq[c]--;

        for (const auto &hash : freq)
            if (hash.second)
                return false;

        return true;
    }
};