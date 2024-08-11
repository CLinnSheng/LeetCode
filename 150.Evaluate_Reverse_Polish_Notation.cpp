#include <bits/stdc++.h>
using namespace std;

/*
Intuition: From the operation, we can tell order is important and we can use a stack to solve this problem
we only insert number into the stack and then whenever a operation is met pop two previousn number in the stack to undergoes the operation
*/
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        deque<int> stack;

        for (auto &token : tokens)
            if (token == "+") {
                int firs = stack.back(); stack.pop_back();
                int sec = stack.back(); stack.pop_back();
                stack.emplace_back(sec + firs);
            }
            else if (token == "-") {
                int firs = stack.back(); stack.pop_back();
                int sec = stack.back(); stack.pop_back();
                stack.emplace_back(sec - firs);
            }            
            else if (token == "*") {
                int firs = stack.back(); stack.pop_back();
                int sec = stack.back(); stack.pop_back();
                stack.emplace_back(sec * firs);
            }            
            else if (token == "/") {
                int firs = stack.back(); stack.pop_back();
                int sec = stack.back(); stack.pop_back();
                stack.emplace_back(sec / firs);
            }            
            else    stack.emplace_back(stoi(token));
            
        return stack.back();
    }
};
