#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
Goal: Design an algorithm for both encoding and decoding string
Given that strs[i] contains only UTF-8 characters
eg: ':', '#', '$'
Basically all symbols, characters & alphabets

Intuition: Since we want to keep track of every single string, so it best to have include the length of every single string
But the constraint is the string itself might contain letters in the front
The solution for it will be create a unique identity, so that we know how many characters for it
and when to start reading it

    string encode(vector<string>& strs) {

        string encode_string = "";
        
        for (const auto& str : strs)
            encode_string += to_string(str.length()) + "#" + str;
        
        return encode_string;
    }

    vector<string> decode(string s) {

        vector<string> decode_strings;
        
        for (int i = 0; i < s.length();) {
        
            // Remember the length of each string is also in the form of str and it might contains more than 1 character
            int end_length = i;

            while (s[end_length] != '#')
                end_length++;
                
            int length = stoi(s.substr(i, end_length - i));
            
            decode_strings.emplace_back(s.substr(end_length + 1, length));
            i = end_length + 1 + length;
        }
        
        return decode_strings;
    }
};
