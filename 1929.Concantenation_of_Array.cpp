#include <vector>

/*
 * Goal: Return concatenation of the 2 arrays
 *
 * Intuition:
 * Just simply create an array of 2*n and then ans[n + i] = ans[i]
 * */
class Solution
{
  public:
    std::vector<int> getConcatenation(std::vector<int> &nums)
    {
        int n(nums.size());
        std::vector<int> answer(n);

        for (int i{}; i < n; i++)
        {
            answer[i] = nums[i];
            answer[i + n] = nums[i];
        }

        return answer;
    }
};
