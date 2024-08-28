#include <bits/stdc++.h>
#include <climits>
#include <cstdint>
#include <cwchar>
#include <string>
using namespace std;

/*
Goal: Return the palindrome that is the nearest to n
Intuition: We can split into half half in the middle and try generate a palindrome just based on half of the values
Palindrome that build from its original number will be the closest to n

        
        int length = n.length();
        int middle = (length % 2 == 0)? length / 2 - 1 : length / 2;
        long firstHalf = stol(n.substr(0, middle + 1));
        
        vector<long> palindromes;
        palindromes.emplace_back(generatePalindrome(firstHalf, length % 2 == 0));
        palindromes.emplace_back(generatePalindrome(firstHalf + 1, length % 2 == 0));
        palindromes.emplace_back(generatePalindrome(firstHalf - 1, length % 2 == 0));
        // Handling exception case
        palindromes.emplace_back(pow(10, length) + 1); 
        palindromes.emplace_back(pow(10, length - 1) - 1);
        
        long diff = LONG_MAX, res = 0;
        long exact = stol(n);
        
        for (const auto& palindrome : palindromes) {
            if (exact == palindrome)    continue;
            if (abs(palindrome - exact) < diff) {
                diff = abs(palindrome - exact);
                res = palindrome;
            }
            // Handling situation when we have the same abs diff, then we choose the 1 which is lower in value
            else if (abs(palindrome - exact) == diff)
                res = min(palindrome, res);
        }
        
        return to_string(res);
    }
    
private:
    long generatePalindrome(long left, bool even) {
        long res = left;
        
        if (!even)
            left /= 10;
        
        while (left > 0) {
            res = res * 10 + left % 10;
            left /= 10;
        }
        
        return res;
    }
};

/*
n = 139
middle = 1
firstHalf = 13
the reason we chose +1/-1 is because it is much closer to n for the generated palindrome
helper(13, false) + 1
    Since not even we break 13 to 1
    return 131
helper(14, false) - 1
    Since not even we break 14 to 1
    return 141
helper(12, false)
    return 121
Take care of the cases where the nearest is 9, 99, etc..
and also 1, 11, 111
*/