#include <algorithm>
#include <vector>
/*
 * Goal: Return the number of triplets chosen from the array that can make triangle
 * Valid Triangle --> 3 sides a,b,c and the sum of any two sides must be greater than the third
 *
 * Intuition:
 * We can first sort the nums first such that it is much easier to handle
 * After that just loop through the array by fixing one side and make use of the property of sum of two side must
 * greater than another one, by finding the right boundary Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    int triangleNumber(std::vector<int> &nums)
    {
        int answer{};

        std::sort(nums.begin(), nums.end());
        for (int i{}; i < nums.size(); i++)
        {
            int k{i + 2};
            for (int j{i + 1}; j < nums.size() - 1 && nums[i] != 0; j++)
            {
                while (k < nums.size() && nums[i] + nums[j] > nums[k])
                {
                    k++;
                }
                answer += k - j - 1;
            }
        }
        return answer;
    }
};
