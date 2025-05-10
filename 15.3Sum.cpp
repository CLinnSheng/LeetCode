#include <algorithm>
#include <vector>
using std::vector;

/*
 * Goal: Return all the triplets such that it sums up to 0
 *
 * Intuition:
 * Key observation the array is not sorted.
 * Brute force way will take O(n^3) which is triple loop
 *
 * How can we optimize it? Can we reduce a loop?
 * Actually this is somehow similar to 2sum.
 * What we can do is fix 1 nubmer the apply the algo from 2sum.
 * The array must be sorted in order to apply the algo from 2sum
 * But theres a constraint must be distinct triplets
 * Time Complextiy: O(n^2)
 * */
class Solution
{
  public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        vector<vector<int>> answer;
        std::sort(nums.begin(), nums.end());

        for (int i{}; i < nums.size() - 2; i++)
        {
            // Since the array is sorted, the number after ith must be graeter than 0 if ith already cgraeter than 0
            // then no point on keep checking forward
            if (nums[i] > 0)
                break;

            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left{i + 1}, right(nums.size() - 1);
            while (left < right)
            {
                int sum{nums[i] + nums[left] + nums[right]};

                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else
                {
                    answer.push_back({nums[i], nums[left], nums[right]});
                }
            }
        }
        return answer;
    }
};
