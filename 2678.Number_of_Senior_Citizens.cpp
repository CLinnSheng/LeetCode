#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
/*
Details has a string 15 while since we only need the information of
age so we just extract character at index 10 and 11
*/

    int countSeniors(vector<string>& details) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int ans = 0;

        for (auto &detail : details)
            if (stoi(detail.substr(11, 2)) > 60)
                ans++;

        return ans;
    }
};