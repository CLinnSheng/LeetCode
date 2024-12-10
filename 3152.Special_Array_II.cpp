#include <vector>

/*
Goal: Return an array of booleans answer such that asnwer[i] is true if
nums[fromi...toi] is special An array is considered spcieal if every pair of its
adjacent elements contains numbers with different parity (Odd or Even) Task:
Check the subarray nums[fromi..toi] is special or not

Intuition:
1. Naive Approach
- Check every single query and then check from queries[i] = [fromi,toi]
- the time Complexity will be O(n^2)

2. Is there a more optimized way?
- From the naive approach, we can actually see there is repeating checking of a
specific range
- We can precompute the size of special array for every single index to the left
- So every single index will hold the maximum size of special array to the left
of its Time Complexity: O(n) Space Complexity: O(n)
*/
class Solution {
public:
  std::vector<bool> isArraySpecial(std::vector<int> &nums,
                                   std::vector<std::vector<int>> &queries) {
    int size(nums.size());

    // Takes O(n) for precompute the prefix
    std::vector<int> preCompute(size, 1);
    for (int i{1}; i < size; i++)
      if ((nums[i] & 1) != (nums[i - 1] & 1))
        preCompute[i] = preCompute[i - 1] + 1;

    std::vector<bool> ans(queries.size(), false);

    // O(n) go through the queries
    int index{};
    for (const auto &query : queries) {
      // Every value in the preCompute indicates the maximum size of special
      // array it can be made to the left of it So the minimum value for it to
      // be valid is equal to the the range which is query[1] - query[0] + 1 and
      // if the value of preCompute exceed the size also means the query is true
      // also
      if (preCompute[query[1]] >= (query[1] - query[0] + 1))
        ans[index] = true;

      index++;
    }

    return ans;
  }
};
