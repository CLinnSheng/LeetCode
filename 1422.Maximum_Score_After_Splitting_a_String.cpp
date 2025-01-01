#include <algorithm>
#include <string>
#include <vector>

/*
 * Goal: Return the maximum score after splitting the string into 2 non empty substrings.
 * Score is the number of zeros in the left substring & number of ones in the right substrings.
 *
 * Intuition:
 * We can solve it naively through double looping through the string has the time complexity of O(n^2)
 * We can optimize this by actually preprocessing the socre at every index
 * So we can solve it in linear time
 * */
class Solution
{
  public:
    int maxScore(std::string s)
    {
        int ones{}, zeros{};
        int len(s.length());

        // precompute the number of 1s in the string
        for (int i{}; i < len; i++)
            if (s[i] == '1')
                ones++;

        // then iterate the string to find out the maximum scores
        int ans{};
        // take note split into 2 non-empty substring
        // so just loop until len - 1
        for (int i{}; i < len - 1; i++)
        {
            if (s[i] == '1')
                // because at index ith, from 0 to ith we only care about the zeros
                ones--;
            else
                zeros++;

            ans = std::max(ans, zeros + ones);
        }
        return ans;
    }
};
