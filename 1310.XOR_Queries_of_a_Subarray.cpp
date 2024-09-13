#include <iostream>
#include <vector>
#include <ios>

/*
Given arr is an array of positive integers & queires is a 2d array where queries[i] = [lefti, righti]

Goal: Return an array answer where answer[i] is the answer to the ith query
Constraints:
    1 <= arr.length, queries.length <= 3 * 104
    1 <= arr[i] <= 109
    queries[i].length == 2
    0 <= lefti <= righti < arr.length

Intuition:
By brute force: we can iterate through the queries and compute the sum
This will lead to time complexity of O(n * q)

However a more clever way is compute the prefix sum of the array.
One Key Point is remeber XOR operation is commutative & x ^ y ^ x = y
So lets say one of the quieries is [1, 3]
and the prefix sum on index 3 + 1 is a ^ b ^ c ^ d & 1 is  a
where [1, 3] = b ^ c ^ d 
and b ^ c ^ d = a ^ b ^ c ^ d ^ a 
              = a ^ b ^ a ^ c ^  d
              = b ^ c ^ d

Time Complexity: O(n + q) n for counting the prefix sum and q to iterate through the queries
Space Complexity: O(n) n for the number of elements in the prefix sum arrays
*/

class Solution 
{
public:
    std::vector<int> xorQueries(std::vector<int>& arr, std::vector<std::vector<int>>& queries) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
  
        std::vector<int> prefixSum(arr.size() + 1, 0);
        
        for (int i = 1; i < prefixSum.size(); i++)
            prefixSum[i] = prefixSum[i - 1] ^ arr[i - 1];
        
        std::vector<int> ans;
        
        for (const auto& query : queries)
            ans.emplace_back(prefixSum[query[1] + 1] ^ prefixSum[query[0]]);
            
        return ans;
    }
};