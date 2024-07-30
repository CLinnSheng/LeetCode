#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int len1 = s.length(), len2 = t.length();

        if (!len2 || len2 > len1)   return "";

        vector<int> charCount(128, 0);
        for (char &c : t)
            charCount[c]++;
        
        // two pointer for the window
        int l = 0, r = 0;
        int counter = len2;
        // variable to keep tracks of minimum length and the starting index
        int min_index = 0, min_length = INT_MAX;

        for (; r < len1; r++){
            // if found one of the character in the target string
            if (charCount[s[r]]-- > 0)
                counter--;

            // means we found all the character in the target string
            while (counter == 0){
                if (r - l + 1 < min_length){
                    min_length = r - l + 1;
                    min_index = l;
                }

                // now we try to shift the window to the left by
                // moving the left pointer to check and see whether
                // this element is one of the characters in the target string or not
                if (++charCount[s[l++]] > 0)
                    counter++;
            }

        }

        return (min_length == INT_MAX)? "" : s.substr(min_index, min_length);
    }
};