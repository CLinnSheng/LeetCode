#include <bits/stdc++.h>
using namespace std;
/*
Goal: Find kth distinct string in an array
We can use a hash map to store the frequency of each char
and then iterate the array again so that we can find the exact kth distinct element
*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        unordered_map<string, int> freq;

        for (const auto &str : arr)
            freq[str]++;

        for (const auto &str : arr) {
            if (freq[str] == 1)
                k--;
            if (!k)
                return str;
        }

        return "";
    }
};