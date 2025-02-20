#include <string>
#include <unordered_set>
#include <vector>
using std::string;
using std::vector;

/*
 * Given an array of strings nums containing n unique binary string of each length
 * Goal: Return a binary string of length n that does not appear in nums.
 *
 * Intuition:
 * The array nums only cantain value with length "n"
 * First thought will be using brute force, by checking all possible combination with string n.
 * Time Complexity will be O(2^n)
 * But apparently the time complexity is not O(2^n) but n + 1 because we only check until found 1 doesnt appear in the
 * array. Use hash set to store the num in nums, so when we check just only need O(1)
 *
 * Time Complexity :O(n + 1)
 * */
class Solution
{
  private:
    string dfs_backtracking(const std::unordered_set<string> &set, std::string &str, const int &index)
    {
        // if reach the final index
        // then we need to check
        if (index == set.size())
            return set.count(str) ? "" : str;

        std::string answer = dfs_backtracking(set, str, index + 1);
        if (answer != "")
            return str;

        str[index] = '1';
        answer = dfs_backtracking(set, str, index + 1);
        if (answer != "")
            return str;

        return "";
    }

  public:
    string findDifferentBinaryString(vector<string> &nums)
    {
        std::unordered_set<string> set(nums.begin(), nums.end());
        std::string str(nums.size(), '0');

        return dfs_backtracking(set, str, 0);
    }
};
