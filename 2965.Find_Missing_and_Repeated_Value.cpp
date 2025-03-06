#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Each integer appears exactly once except a which appears twice and b which is missing.
 * Goal: Return a 0-indexed integer array ans of size 2 where ans[0] equals to a and ans[1] equals to b
 *
 * Intuition:
 * Just use a hash map to store the freq of each val
 *
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid)
    {
        vector<int> answer(2, -1);
        int n(grid.size());
        std::unordered_map<int, int> map;

        for (const auto &vec : grid)
            for (const int &num : vec)
                map[num]++;

        for (int i{1}; i <= n * n; i++)
            if (map.find(i) == map.end())
                answer[1] = i;
            else if (map[i] == 2)
                answer[0] = i;

        return answer;
    }
};
