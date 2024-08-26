#include <bits/stdc++.h>
#include <climits>
#include <ios>
#include <unordered_set>

/*
Goal: Find the longest consecutive sequence in the array
Eg: [100, 4, 200, 1, 3, 2]
Intuition: Store all the elements in a set
Then try to find the first eleemtn of the sequence in the array and try to find the whole sequence
Time Complexity is O(n2) because we need an inner loop to find its consecutive elements

Second way is we straight away sort it lead it to O(nlgn)
and then we try to find the consecutive elements straight from the array
Final Time complexity will just be O(nlogn)
*/
class Solution {
public:
    int longestConsecutive(std::vector<int>& nums) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        int size = nums.size();
        
        if (size == 0)  return 0;
        
        int max_len = 0, cnt = 1;
        
        std::sort(nums.begin(), nums.end());
        
        for (int i = 0; i < size - 1; i++) {
            if (nums[i] == nums[i + 1]) continue;
            if (nums[i] + 1 == nums[i + 1]) cnt++;
            else {
                max_len = std::max(max_len, cnt);
                cnt = 1;
            }
        }
        
        // in case the whole array is a complete sequence
        return std::max(max_len, cnt);
    }
};