#include <string>
#include <unordered_set>

/*
 * Goal: Find the length of the longest substring without duplicate characters.
 *
 * Intuition:
 * Key things is substring and no duplicate characters.
 * The naive approach will just simply use nested loop to try every single substring
 * But this is very expensive in terms of time complexity O(n^2)
 *
 * If you ovserve from the naive appraoch you can actually see there is overlapping while we checking
 * the subarray.
 * for example, a,b,c,d
 * a,b,c, --> a,b,c,d
 *
 * A clever way is we use sliding window algo, the sliding window will maintain the longest substring.
 * Whenever we found a duplicate characters, we will keep moving the left pointer until there is not duplicate
 * characters
 * */
class Solution
{
  public:
    int lengthOfLongestSubstring(std::string s)
    {
        int ans{};
        int left{}, right{};
        std::unordered_set<int> set;

        while (right < s.length())
        {
            if (set.count(s[right]))
            {
                while (!set.empty() && set.count(s[right]))
                    set.erase(s[left++]);
            }
            set.insert(s[right]);
            ans = std::max(ans, right - left + 1);
            right++;
        }

        return ans;
    }
};
