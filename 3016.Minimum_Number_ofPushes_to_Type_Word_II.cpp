#include <bits/stdc++.h>
using namespace std;

/*
Goal: Find the minumum number of time to type the string of words
Intuition: We allow to bind the key to whatever characters that we want (2-9)
Means that 8 distinct character only need 8 pushes (each key bind to 1 word)
So we must bind the most frequent characters in the word first then proceed to the 2nd 1
number of pushes for a specific characer is n_key / 8 + 1, n_key is to track hw many character had binded
*/
class Solution{
    public:
        int minimumPushes(string word) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);

            if (!word.length()) return 0;

            // use a hashmap to store the frequency of each char in the owrd
            unordered_map<char, int> freq;
            for (auto const &c : word)
                freq[c]++;

            int push = 0;
            priority_queue<int> maxHeap;

            // iterate through the hash and store the freq into a maxHeap
            for (auto const &[character, cnt] : freq)
                maxHeap.emplace(cnt);

            int key_bind = 0;

            while (!maxHeap.empty()) {
                push += (key_bind / 8 + 1) * maxHeap.top();
                maxHeap.pop();
                key_bind++;
            }

            return push;
        
        }
};