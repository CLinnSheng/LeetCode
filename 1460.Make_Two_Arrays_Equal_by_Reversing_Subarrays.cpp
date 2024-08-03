#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
/*
Intuition: Need to reverse the arr to equal to target
We dont really need to reverse it, just check whether the number of each element is equal or not
*/
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<int, int> map_target;
        unordered_map<int, int> map_arr;

        if (target.size() != arr.size())    return false;

        for (auto &t : target)
            map_target[t]++;
        for (auto &a : arr)
            map_arr[a]++;

        return map_target == map_arr;
    }
};