#include <cstring>
#include <string>
#include <strings.h>
#include <vector>
using ll = long long;

/*
 * Given 3 integers start, finish and limit.
 * x is called powerful if ends with s and each digit in x is at most limit
 * Goal: Return the total number of poweful integers in the range [start...finish]
 *
 * Intuition:
 * Observation:
 * i. start < finish and 's' can be at any where. It can be greater than finish or even smaller than s
 * ii. s[i] < limit. This is not neccessarily true for start & finish. They can have any digit that is greater than
 * limit iii. maxNumber is at most 10e15
 *
 * One Key Pattern is whenver ask us to find the number within a range eg [2, 50]
 * instead of finding 2 to 50. we can have a function find until a upper boundary
 * so [2, 50] = helper(50) - helper(1) --> so this will simply give us within the range
 *
 * Boundary Case:
 * i. When s > finish, then automatically can form any x. because we need s inclusive in x, so we cant form any number
 * within the range ii. When s < start, then count(start, finish) = count(1, finish) eg: start = 8, s = 10, finish = 20.
 * Since s > start so basically x from 1 to start will be result in 0 because we cant form it count(8, 20) = count(1,
 * 20) - count(1, 7) = count(1, 20) where count(1, 7) == 0
 *
 * Intuition:
 * So at every index we need to choose a digit --> Tree decision problem, so we can brute force it with dfs and
 * backtracking. Definitely can optimize with caching and using dp. But how many number we can choose from every index?
 * eg: limit=3, s=21, finish=21568
 * _ _ _ _ _ --> the first digit option will be min(limit, finish[0]) because we need to say within the range and also
 * less than or equal to limit and then the following digit will actually depends on the previous digit. If the previous
 * digit choose the boundary, then applying min(nums[1], limit again) if the previous digit is not the bonudary value,
 * then we can free to choose any number from 0 up to limit because it will always within the range. We can have a
 * boolean val to store whether the prev is at boundary or not
 * This will continue until the last len(s) digit. Because the last len(s) digit will be automically chosen to be s
 * But this will not be always true because it might greater than the finish where the boolean value is all true for all
 * index before the last len(s) index. But this is not a big deal, because this only occurs once, so just simply
 * subtract by 1
 *
 * Another observation for the solution pattern is if the start=1, then we can straight away use count(1, finish)
 * because count(0, 1) will result in 0
 *
 * Dry Run:
 * eg: start=1, finish=2332, s=33, limit=4
 * _ _ _ _ _ --> 1st index = std::min(limit, finish[0]) can have number from 0 up to 2
 * Let's say we choose anything that is not boundary, then the subsequence bool val will also be false.
 * Then for x[1] can be from 0 to limit, because we are not tight by the boundary. so we have 4 choices over here and
 * the lsat 2 index is the s. So important thing here is for every x[1] that is not tight by the boundary actually has
 * the same number of x can be produced. So we can see this is actually repeating subproblem, then we can solve it with
 * using dp. So for a particular position x[i] lets say is not tight by the bounded value will also equal to others
 * possible x[i] that is not tight by the bounded value. So two important parameters will be the position & also the
 * boolean value. then dp[position][bool] where dp[i][0/1] let us know at position ith the number of x can be formed if
 * it is bounded or not bounded.
 * Time Complexity: O(n * 2) --> O(n)
 * */
class Solution
{
  private:
    std::vector<std::vector<ll>> dp;

    bool checkSubtract(const std::string &numStr, const ll &numDigits, const std::string &suffix, int limit)
    {
        std::string suffix_num = numStr.substr(numDigits - suffix.length());
        bool subtract = std::stoll(suffix_num) < std::stoll(suffix);

        // this subtract only applies when all of it are at boundary
        // and also obey the limit value
        if (subtract)
            for (int index{}; index < numDigits - suffix.length(); index++)
                if (numStr[index] - '0' > limit)
                {
                    subtract = false;
                    break;
                }
        return subtract;
    }

    ll countValidNumbers(const std::string &numStr, const int &index, const ll &numDigits, int limit,
                         const std::string &suffix, bool is_tight)
    {
        // base case
        if (index == numDigits)
            return 1;

        // caching & memoziation
        if (dp[index][is_tight] != -1)
            return dp[index][is_tight];

        int low{}, high;
        int suffix_len(suffix.length());

        // reach suffix
        if (index >= numStr.length() - suffix_len)
        {
            int suffix_index = index - (numDigits - suffix_len);
            low = high = suffix[suffix_index] - '0';
        }
        else
        {
            high = is_tight ? std::min(limit, (numStr[index] - '0')) : limit;
        }

        ll ttl{};
        for (int digit{low}; digit <= high; digit++)
        {
            bool new_tight = is_tight && (digit == numStr[index] - '0');
            ttl += countValidNumbers(numStr, index + 1, numDigits, limit, suffix, new_tight);
        }

        return dp[index][is_tight] = ttl;
    };
    ll solveUpTo(const std::string &numStr, const ll &numDigits, int limit, const std::string &suffix)
    {
        dp = std::vector<std::vector<ll>>(16, std::vector<ll>(2, -1));
        ll res = countValidNumbers(numStr, 0, numDigits, limit, suffix, true);

        // Check Whether the last len(suffix) is smaller than suffix or not
        if (checkSubtract(numStr, numDigits, suffix, limit))
            res--;

        return res;
    }

  public:
    ll numberOfPowerfulInt(ll start, ll finish, int limit, std::string s)
    {
        ll suffixVal{std::stoll(s)};

        std::string fin_str{std::to_string(finish)};
        std::string start_str{std::to_string(start - 1)};

        ll fin_size(fin_str.length());
        ll start_size(start_str.length());

        ll upToFin = (finish >= suffixVal) ? solveUpTo(fin_str, fin_size, limit, s) : 0;
        ll upToStart = (suffixVal < start) ? solveUpTo(start_str, start_size, limit, s) : 0;

        return upToFin - upToStart;
    }
};
