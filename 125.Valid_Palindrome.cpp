#include <cctype>
#include <ios>
#include <string>
#include <iostream>

/*
Palindrome: Reads the same forward and backward
Constraint: Have to delete all non-alphanumeric numbers, spaces and turn it into lowercase
Intuition: Have 2 pointers 1 pointing at the front while another pointing at the back, iterate through the array until start > end
skip it when not alphanumeric
Time Complexity: O(n)
*/

class Solution {
public:
    bool isPalindrome(std::string s) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int start = 0, end = s.length() - 1;
        
        while (start < end) {
            
            if (!isalnum(s[start])) start++;
            else if (!isalnum(s[end])) end--;
            else if (tolower(s[start++]) != tolower(s[end--])) return false;
            
        }
        
        return true;
    }
};