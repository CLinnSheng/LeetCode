#include <algorithm>
#include <unordered_set>
#include <vector>

/*
 * A subsequence of num is square streak if:
 *  -Length of subsequence is at least 2
 *  -after sorting the subsequence, each element is the square of its previous
 * number Goal: Return the longestSquareStreak
 *
 * Intuition: we can use a hash set data structure to store all the number from
 * the arrays. So we can easily check whether the square of next number is
 * exists in the set or not by O(1)
 *
 * Time Complexity: O(n) -> we iterate through the array and at worst an array
 * contain all the square of just the first num Space Complexity: O(n)
 * */
class Solution {
public:
  int longestSquareStreak(std::vector<int> &nums) {

    std::vector<int>::iterator maxElement_it =
        std::max_element(nums.begin(), nums.end());
    long long maxElement{*maxElement_it};
    std::unordered_set<int> set(nums.begin(), nums.end());

    int ans{};

    for (const auto &num : nums) {
      int longestStreak{};
      long long currNum{num};

      while (set.count(currNum)) {
        if (currNum > maxElement)
          break;
        longestStreak++;
        currNum *= currNum;
      }

      ans = std::max(ans, longestStreak);
    }

    return ans < 2 ? -1 : ans;
  }
};
