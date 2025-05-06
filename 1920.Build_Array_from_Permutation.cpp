#include <vector>

/*
 * Given a zero-based permutation nums. Build an array of the same length where ans[i] = nums[nums[i]] for each 0 <= i <
 * nums.length
 *
 * Intuition:
 * Very direct just iterate through the nums and push it into the answer
 * But how can we do it in O(1) space?
 *
 * Can we do it inplace while preserve the orignal value and also can know the updated changes?
 * We need to build our own data structure.
 * think of this in math if x is the original value then we times y.
 * If we want to get back x we just simply need to divide by y.
 * x * y, x = x * y / y
 *
 * */
class Solution
{
  public:
    std::vector<int> buildArray(std::vector<int> &nums)
    {
        // std::vector<int> answer;
        //
        // for (const auto &num : nums)
        //     answer.emplace_back(nums[num]);
        //
        // return answer;

        for (int i{}; i < nums.size(); i++)
            // we add the original value because we still want to access the original value
            // just simply mod by the factor
            nums[i] += (1001 * (nums[nums[i]] % 1001));

        // get the new value simply just divide by the factor we times
        for (int i{}; i < nums.size(); i++)
            nums[i] /= 1001;

        return nums;
    }
};
