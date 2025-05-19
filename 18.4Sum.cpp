#include <algorithm>
#include <vector>

/*
 * Find fourplets such that nums[a] + nums[b] + nums[c] + nums[d] = target
 * where a, b, c & d are distinct and  0 <= a,b,c,d < n
 *
 * Intuition:
 * The appraoch is similar to 2sum and 3sum.
 * Basically how we implement 2sum in 3sum we will just do the same thing but with additional pointer.
 * In 3sum we fix 1, now in 4sum we fix 2
 * One tricky thing is now the arrray contain negative element as well and the target can be negative or positive.
 * So we cannot do like how 3sum does straight away break when the first pivot element is greater than target because
 * negative + negative will become smaller in value. Time Complexity: O(n^3) Space Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> fourSum(std::vector<int> &nums, int target)
    {
        std::vector<std::vector<int>> answer;
        int n(nums.size());
        std::sort(nums.begin(), nums.end());

        for (int i{}; i < n - 3; i++)
        {
            // Prevent the duplicate of the triplet + this pivot
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            // 3 Sum
            for (int j{i + 1}; j < n - 2; j++)
            {
                // Prevent the duplicate of the duplet + this pivot
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;

                long long prev2Sum(nums[i] + nums[j]);
                int left{j + 1}, right{n - 1};
                while (left < right)
                {
                    long long sum(prev2Sum + nums[left] + nums[right]);
                    if (sum > target)
                        right--;
                    else if (sum < target)
                        left++;
                    else
                    {
                        answer.push_back({nums[i], nums[j], nums[left], nums[right]});
                        left++;
                        right--;

                        // try other possible while fixing the first 2 index
                        while (left < right && nums[left] == nums[left - 1])
                            left++;
                        while (left < right && nums[right] == nums[right + 1])
                            right--;
                    }
                }
            }
        }
        return answer;
    }
};
