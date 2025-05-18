#include <algorithm>
#include <vector>

/*
 * Goal: Return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k & j != k && nums[i] + nums[j] +
 * nums[k] == 0
 * NOTE: Cannot contain duplicate triplets
 *
 * Intuition:
 * The most straightaway approach will be using triple loops to try out all the possible triplets.
 * How can we optimize this? From O(n^3) --> O(n^2) or even better
 *
 * The approach i can think of is actually using how we solve Two Sum
 * So we need to sort it first to simplify the process.
 * Since the array is sorted, we dont have to consider the num that is already greater than 0.
 * So what we will do is basically the same as Two Sum but with another pointer that act as the pivot.
 * We also need to handle duplicate triplets
 * Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> threeSum(std::vector<int> &nums)
    {
        std::vector<std::vector<int>> answer;
        int n(nums.size());
        std::sort(nums.begin(), nums.end());

        for (int i{}; i < n - 2; i++)
        {
            // Dont have to consider element greater than 0
            if (nums[i] > 0)
                break;

            // Handle duplicate
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int left{i + 1}, right{n - 1};
            while (left < right)
            {
                int sum{nums[left] + nums[right] + nums[i]};

                if (sum > 0)
                    right--;
                else if (sum < 0)
                    left++;
                else
                {
                    answer.push_back({nums[i], nums[left], nums[right]});

                    // need to change both left and right because if we only change one for example
                    // left, the sum will definitely go higher so is impossible if we dont change right as well
                    left++;
                    right--;
                    // Dont straight away break because there might be other way
                    while (left < right && nums[left] == nums[left - 1])
                        left++;
                }
            }
        }
        return answer;
    }
};
