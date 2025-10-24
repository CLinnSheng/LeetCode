#include <algorithm>
#include <string>
#include <vector>

/*
 * Subsequence ca be obtain by deleting some or no elements without changing the relative order of the remaining
 * character
 * Goal: Return the longest common subsequence
 *
 * Intuition:
 * At each step, we have 2 choices
 * 1. If character of the current index at both string are equal, then we move both indices forward and extend the
 * subsequence
 * 2. If not equal, we can explore both path by advancing one index at a time and recursively finding the longest
 * subsequence, then choose the one with the maximum subsequent length
 * Time Complexity: O(2^(m + n))
 *
 * Observe from the brute force way, we can actually we doing some repetitive computation
 * Therefor we can optimize it by using caching. And the information we passing down from the recursion is actually just
 * the indices of both string. So the caching gonna be 2d array.
 * Where caching[i][j] --> Longest subsequent from index i and index j
 * Time Complexity: O(m*n)
 * */
class Solution
{
  private:
    int dfs(const std::string &text1, const std::string &text2, int i, int j, std::vector<std::vector<int>> &caching)
    {
        // Base Case
        if (i == text1.length() || j == text2.length())
            return 0;

        // Check Caching
        if (caching[i][j] != -1)
        {
            return caching[i][j];
        }
        // 2 Path
        // If same then move 2 indices
        if (text1[i] == text2[j])
        {
            return caching[i][j] = 1 + dfs(text1, text2, i + 1, j + 1, caching);
        }

        // If not the same take the path that leads to longer subsequence
        return caching[i][j] = std::max(dfs(text1, text2, i + 1, j, caching), dfs(text1, text2, i, j + 1, caching));
    }

  public:
    int longestCommonSubsequence(std::string text1, std::string text2)
    {
        std::vector<std::vector<int>> caching(text1.length() + 1, std::vector<int>(text2.length() + 1, -1));
        return dfs(text1, text2, 0, 0, caching);
    }
};
