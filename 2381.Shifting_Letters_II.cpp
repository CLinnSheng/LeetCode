#include <string>
#include <vector>

/*
 * Given a string s of lowercase letter & a 2d array shifts
 * where shifts[i] = [starti, endi, directioni].
 * For every i shift the characters in s from the index starti to the index endi (inclusive).
 * Directioni = 1 (forward) = 0 (backward)
 * Goal: Return the final string after all such shifts to s are applied.
 *
 * Intuition:
 * The formula for moving forward & backward is first by changing it into int where 0 -> a
 * so for every operation we (_var + +/-1 + 26) % 26
 * we can do it naively by looping through the string & loop through the shifts
 * Time Complexity: O(n * m)
 * Space Complexity: O(m)
 *
 * However this exceeded the time complexity
 * Is there any way to optimize it to linear time?
 * We can actually see we computed multiple times for some of the range
 * We can actually optimize it by using prefix sum kinda like line sweeping algorithm
 * */
class Solution
{
  public:
    std::string shiftingLetters(std::string s, std::vector<std::vector<int>> &shifts)
    {
        int len(s.length());
        std::string ans(len, ' ');

        std::vector<int> prefixDiff(len, 0);
        for (const auto &shift : shifts)
        {
            prefixDiff[shift[0]] += shift[2] == 1 ? 1 : -1;
            if (shift[1] + 1 < len)
                prefixDiff[shift[1] + 1] += shift[2] == 1 ? -1 : 1;
        }

        int diff{};
        for (int i{}; i < len; i++)
        {
            diff = (diff + prefixDiff[i]) % 26;
            ans[i] = 'a' + (s[i] - 'a' + diff + 26) % 26;
        }

        return ans;
    }
};
