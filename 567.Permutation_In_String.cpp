#include <bits/stdc++.h>
#include <ios>
#include <unordered_map>

/*
Given two string s1 & s2
Goal: Check whether is s2 contains a permuation of s1
Intuition: Easy way to deal with permutation is by tracking the frequency of each char using hash data structure
Use sliding window of size s1 slide through s2
Keep checking is there 26 matches along the way
Time Complexity: O(l1 + (l2 - l1))
*/

class Solution {
public:
    bool checkInclusion(std::string s1, std::string s2) {

        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        int length1 = s1.length(), length2 = s2.length();

        if (length1 > length2) return false;

        std::unordered_map<int, int> map1, map2;
        int matches = 0; // To check whether a permutation of s1 is in s2

        // Base Case: The first 2 character
        for (int i = 0; i < length1; i++) {
            map1[s1[i] - 'a']++;
            map2[s2[i] - 'a']++;
        }

        // Checking the first 2 character
        for (int i = 0; i < 26; i++)
            if (map1[i] == map2[i])
                matches++;


        // Left & Right pointer of sliding window
        // r is length 1 because we will checking it first before sliding the window
        int l = 0, r = length1;

        while (r < length2) {

            if (matches == 26) return true;

            // Moving the right pointer
            int index = s2[r] - 'a';
            map2[index]++;
            // if is it a new character that are not appear in s1
            if (map2[index] == map1[index]) matches++;
            else if (map2[index] == map1[index] + 1) matches--;


            // Moving the left pointer
            index = s2[l] - 'a';
            map2[index]--;
            // if we delete the character that is found in s1
            if (map1[index] == map2[index]) matches++;
            else if (map1[index] - 1 == map2[index]) matches--;

            l++; r++;
        }

        return matches == 26;
    }
};
