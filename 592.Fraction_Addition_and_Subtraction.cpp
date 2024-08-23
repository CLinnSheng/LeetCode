#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
String expression with 0-9, +, - or /
Goal: Return the final result in irreducible fraction (string)

Intuition: Have to parse the string for char '/' and add the current num with the next num
to simplify it we change the both number to the same base denominator 
num = num * currDenom + curNum * denom
denom = denom * currDenom
we sum up 1 by 1 by using the common denom and then only find the irregular fraction at the end
*/
class Solution {
    
    public:
        string fractionAddition(string expression) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            if (expression.length() == 0)
                return "0/1";
                
            // to store every single val in the expression
            vector<string> nums;
            
            // for computation purpose
            int num = 0, denominator = 1;
            
            // make it consistent for every single num as the first num wont have '+' if it is a positive number
            if (expression[0] != '-')
                expression = '+' + expression;
            
            // storing all the values in nums
            for (int i = 0; i < expression.length();) {
                int j = i + 1;
                
                while (j < expression.length() && expression[j] != '+' && expression[j] != '-')
                    j++;
                    
                nums.emplace_back(expression.substr(i, j - i));
                i = j;
            }
            
            for (const string &s : nums) {
                int pos = s.find('/');
                int curNum = stoi(s.substr(1, pos - 1));
                int curDenom = stoi(s.substr(pos + 1));
                
                if (s[0] == '-')
                    curNum *= -1;
                    
                num = num * curDenom + curNum * denominator;
                denominator *= curDenom;
                
            }
            
            int gcd = abs(find_gcd(num, denominator));
            
            num /= gcd;
            denominator /= gcd;
            
            return to_string(num) + "/" + to_string(denominator);
        }
        
        int find_gcd(int a, int b) {
            if (a == 0)
                return b;
                
            return find_gcd(b % a, a);
        }
};