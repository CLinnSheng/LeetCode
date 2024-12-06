#include <unordered_set>
#include <vector>

/*
 * Given an integer array banned and 2 integer n & maxSum. Choose number of
 * integers with the following rules: from the range [1, n] each integer can be
 * chosen at most once Choosen integer should not be in the array banned sum of
 * the integer does not exceed maxSum
 *
 * Goal: Return the maximum number of integers can be choose following the
 * mentoined rules
 *
 * Intuition: Since we want to get the maximum number of integers that can be
 * choose while following the rule So we need to choose from the minimum from
 * the given range so that we can choose more number while not exceed the range
 * Use a hash set to keep track of the banned array, so every time we acceass
 * only O(1)
 *
 * Time Complexity: O(n)
 * Space Complexitya: O(n)
 * */
class Solution {
public:
  int maxCount(std::vector<int> &banned, int n, int maxSum) {
    std::unordered_set<int> banned_int(banned.begin(), banned.end());
    int ans{};
    int sum{};

    for (int i{1}; i <= n; i++) {
      if (banned_int.count(i))
        continue;
      if (sum + i > maxSum)
        break;
      ans++;
      sum += i;
    }
    return ans;
  }
};
