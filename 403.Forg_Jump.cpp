#include <cmath>
#include <unordered_map>
#include <vector>
using std::vector;

/*
 * The frog can jump on a stone but it must not jump into the water.
 * The list of stones ar4e sorted in ascending order
 * Initially, the frog is on the first stone and assumes the first jump must be 1 unit
 * If the frog's last jump was k units, its next jump must be either k-1, k or k+1 units.
 *
 * Intuition:
 * First thought will be brute force using recursion at each step we can either choose we want to jump k - 1, k or k + 1
 * units
 * we need to use a map to store the number of hops to reach that stone and the value will be the index
 * the time complexity will be at most O(3^n) because we can see it like a tree decision problem.
 * At every node we have 3 decision
 *
 * We can optimize this by using memoziation which is top-down dp appraoch:w
 * Time Complexity: O(n^2)
 * */
class Solution
{
  private:
    bool helper(const vector<int> &stones, const int &index, const int &jump, vector<vector<int>> &dp)
    {
        // base cases
        if (index == stones.size() - 1)
            return true;

        if (dp[index][jump] != -1)
            return dp[index][jump];

        bool jump1{}, jump2{}, jump3{};

        // check whether from the current stone wether can we reach any stone if we jump k time, k + 1 time, or k - 1
        // time
        if (jump > 1 && map.find(stones[index] + jump - 1) != map.end())
            jump1 = helper(stones, map[stones[index] + jump - 1], jump - 1, dp);

        if (map.find(stones[index] + jump) != map.end())
            jump2 = helper(stones, map[stones[index] + jump], jump, dp);

        if (map.find(stones[index] + jump + 1) != map.end())
            jump3 = helper(stones, map[stones[index] + jump + 1], jump + 1, dp);

        return dp[index][jump] = jump1 || jump2 || jump3;
    }

    std::unordered_map<int, int> map;

  public:
    bool canCross(vector<int> &stones)
    {
        // top-down approach
        // // base cases for the first valid jump
        // if (stones[1] - stones[0] != 1)
        //     return false;
        //
        // // 2000 rows because of the constraint at max there is 2000 stones
        // // and for columns is the jump, at worst is 2000 because initially we start jump at 1,
        // // worst case will be + 1 for every jump, then will be 2000max jump in total
        // vector<vector<int>> dp(2000, vector<int>(2000, -1));
        // for (int i{}; i < stones.size(); i++)
        //     map[stones[i]] = i;
        // // since we assume the first jump must be 1 unit, we can start from index 1
        // return helper(stones, 1, 1, dp);

        // bottom up approach
        if (stones[1] - stones[0] != 1)
            return false;

        for (int i{}; i < stones.size(); i++)
            map[stones[i]] = i;

        // dp[i][j] stands for whether is it possitble to  reach stones i wich j jumps
        vector<vector<bool>> dp(stones.size(), vector<bool>(stones.size(), false));

        // we assume that the first jump is 1
        dp[1][1] = true;

        // try every single stone
        for (int i{1}; i < stones.size(); i++)
            // try every jump size
            for (int j{1}; j < stones.size(); j++)
            {
                // if not possilbe to jump to i with k jump, then straight away skip it, no point to check further
                if (!dp[i][j])
                    continue;

                int nxtStone;

                for (int step : {j - 1, j, j + 1})
                    if (step > 0 && map.find(stones[i] + step) != map.end())
                    {
                        nxtStone = map[stones[i] + step];
                        dp[nxtStone][step] = true;
                    }
            }

        // now check every single possible step whether can ireach the final stone or not
        for (int k{1}; k < stones.size(); k++)
            if (dp[stones.size() - 1][k])
                return true;

        return false;
    }
};
