#include <string>
#include <vector>
using std::string;
/*
 * Goal: Given three strings s1, s2, s3, write a function to check if the interleaving of s1 and s2 forms a s3
 *
 * Intuition:
 * At each index, we can either choose s1[i] or s2[i]
 * Time Complexity: O(2^n)
 *
 * Observation from brute force which is repetitive computation. Can improve by using caching
 *
 * */
class Solution
{
  private:
    bool dfs(std::string &s1, std::string &s2, std::string &s3, int index1, int index2, int index3,
             std::vector<std::vector<std::vector<int>>> &cache)
    {
        // Base Case
        if (index3 == s3.size())
        {
            // Se is only form if both index at the end of the string
            return (index1 == s1.size()) && (index2 == s2.size());
        }

        if (cache[index1][index2][index3] != -1)
        {
            return cache[index1][index2][index3];
        }

        if (index1 < s1.size() && s1[index1] == s3[index3])
        {
            if (dfs(s1, s2, s3, index1 + 1, index2, index3 + 1, cache))
            {
                return cache[index1][index2][index3] = true;
            }
        }
        if (index2 < s2.size() && s2[index2] == s3[index3])
        {
            if (dfs(s1, s2, s3, index1, index2 + 1, index3 + 1, cache))
            {
                return cache[index1][index2][index3] = true;
            }
        }

        return cache[index1][index2][index3] = false;
    }

  public:
    bool isInterleave(string s1, string s2, string s3)
    {
        std::vector<std::vector<std::vector<int>>> cache(
            s1.size() + 1, std::vector<std::vector<int>>(s2.size() + 1, std::vector<int>(s3.size() + 1, -1)));

        return dfs(s1, s2, s3, 0, 0, 0, cache);
    }
};
