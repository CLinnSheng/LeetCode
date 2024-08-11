#include <bits/stdc++.h>
using namespace std;

/*
need to generate all variables of n parenthesis
we can use backtracking and dfs to find all possible answers
the condition for backtracking will be simply n of left and right parenthesis
*/
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        function<void(int, int, vector<string>&, string)> dfs = [n, &dfs](int n_open, int n_close, vector<string>& ans, string str) {
            if (n_open == n_close && n_close == n) {
                ans.push_back(str);
                return;
            }
            if (n_open < n) dfs(n_open + 1, n_close, ans, str + "(");
            if (n_close < n_open)   dfs(n_open, n_close + 1, ans, str + ")");
        };

        vector<string> ans;

        dfs (0, 0, ans, "");
        
        return ans;
    }
};