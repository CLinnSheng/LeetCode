#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    const vector<string> belowTen{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
    const vector<string> belowTwenty{"Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    const vector<string> belowHundred{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

    string numberToWords(int num) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        if (num == 0)   return "Zero";

        return convert(num);
    }

    // a recursive function that checks for < 10, < 20, < 100, < 1000, < 1000000, < 1000000000 and billion
    string convert(int num){
        if (num < 10)
            return belowTen[num];

        if (num < 20)
            return belowTwenty[num - 10];

        if (num < 100)
            return belowHundred[num / 10] + (num % 10? " " + convert(num % 10) : "");

        if (num < 1000)
            return convert(num / 100) + " Hundred" + (num % 100? " " + convert(num % 100) : "");
        
        if (num < 1000000)
            return convert(num / 1000) + " Thousand" + (num % 1000? " " + convert(num % 1000) : "");

        if (num < 1000000000)
            return convert(num / 1000000) + " Million" + (num % 1000000? " " + convert(num % 1000000) : "");

        
        // lastly will be billions
        return convert(num / 1000000000) + " Billion" + (num % 1000000000? " " + convert(num % 1000000000) : "");
    }
};