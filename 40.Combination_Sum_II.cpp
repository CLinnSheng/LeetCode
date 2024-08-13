#include <bits/stdc++.h>
using namespace std;

/*
Since want to find permutation, we can use dfs and backtracking to try out diff combinations
dfs to search to find the combination that hit the target if not backtrack
Constraint is that is must be a unique combinatoi set (order doesnt matter)
ways to solve this is to sort the array because we wont repeat the same number anymore 
for example like [1, 2, 5] & and [2, 1 ,5] as [2, 1, 5] wont be appear if we sort the arrray because 2 comes after 1
duplicates are allow to be in the set so in order to have duplicate numbers allow we msut have this condition
if i == index and also arr[i] != arr[i - 1] to prevent producting the same set of combinations
*/

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> sub;

        sort(candidates.begin(), candidates.end());
        backtracking(ans, candidates, target, sub, 0, 0, n);

        return ans;
    }

    void backtracking(vector<vector<int>> &ans, vector<int> &cand, int target, vector<int> &sub, int index, int cur_sum, int size) {

// basecase
        if (cur_sum == target) {
            ans.emplace_back(sub);
            return;
        }

// backtrack
        if (cur_sum > target)
            return;

        
        for (int i = index; i < size; i++) {

            if (i == index || cand[i] != cand[i - 1]) {
            sub.emplace_back(cand[i]);
            backtracking(ans, cand, target, sub, i + 1, cur_sum + cand[i], size);

            // backtrack
            sub.pop_back();}
        }
    }
};