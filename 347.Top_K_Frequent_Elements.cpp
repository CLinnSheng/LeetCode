#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
Goal: Return the k most frequent elements
Constraint: It might more than 1 k most frequent elements
Intuition: Since it involve with frequency, we can use hashtable to keep track the freq of each element
And then use another 2d array to store the count and its elements
array[i][j] is the element with count i

        
        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        unordered_map<int, int> freq;
        
        for (const auto& num : nums)
            freq[num]++;
            
        vector<int> ans;
        
        // maximum count is the size of the array
        vector<vector<int>> freq_element(nums.size() + 1);
        
        // Store all the element for each count
        for (const auto& [key, value] : freq)
            freq_element[value].emplace_back(key);
            
        
        // Now find the desire k most frqeuent elements
        for (int i = nums.size(); i >= 1; i--) 
            if (!freq_element[i].empty()) 
                for (const auto& num : freq_element[i])
                    if (k != 0) {
                        ans.emplace_back(num);
                        k--;
                    }
            
        
        return ans;
    }
};