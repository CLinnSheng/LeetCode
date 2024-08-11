#include <bits/stdc++.h>
using namespace std;

/*
Intuition: Checking for valid parenthesis where '(' close with ')'
we can use stack to store the left half and check with the right half
*/
class Solution {
    public:
        bool isValid(string s) {

            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);

            deque<char> stack;
            
            for (int i = 0; i < s.length(); i++) 
                switch(s[i]) {
                    case '(':
                    case '{':
                    case '[':
                        stack.emplace_back(s[i]);
                        break;

                    case ')':
                        if (stack.empty() || stack.back() != '(')
                            return false;
                        else
                            stack.pop_back();
                        break;

                    case ']':
                        if (stack.empty() || stack.back() != '[')
                            return false;
                        else
                            stack.pop_back();
                        break;

                    case '}':
                        if (stack.empty() || stack.back() != '{')
                            return false;
                        else
                            stack.pop_back();
                }
                
            return (stack.size()) ? false : true;
        }
        
};