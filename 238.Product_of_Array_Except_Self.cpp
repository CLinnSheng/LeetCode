#include <cstddef>
#include <vector>

/*
 * Goal: Return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 *
 * Intuition:
 * The brute force will just simply iterate throught the nums array twice at the second loop we just skip when i == j,
 * so we can compute the product.
 *
 * Optimization:
 * From the brute force approach, we can observe that we need information from the past and also future.
 * The only way can do that is actually precompute the multiplicatoin.
 * So, we gonna have one prefix and another suffix multiplication
 * Time Complexity: O(n)
 *
 * We can further optimize the space complexity because we dont really need the information of every single index, we
 * only just need the information of the previous multiplication
 * */
class Solution
{
  public:
    std::vector<int> productExceptSelf(std::vector<int> &nums)
    {
        size_t size = nums.size();
        std::vector<int> answer(size, 1);
        // Brute Force
        // for (int i{}; i < size; i++)
        // {
        //     for (int j{}; j < size; j++)
        //     {
        //         if (i == j)
        //         {
        //             continue;
        //         }
        //         answer[i] *= nums[j];
        //     }
        // }
        //

        // Prefix & Suffix O(n)
        // std::vector<int> prefix(size, 1), suffix(size, 1);
        // for (int i{1}; i < size; i++)
        // {
        //     prefix[i] = prefix[i - 1] * nums[i - 1];
        //     suffix[size - i - 1] = suffix[size - i] * nums[size - i];
        // }
        //
        // for (int i{}; i < size; i++)
        // {
        //     answer[i] = prefix[i] * suffix[i];
        // }

        // Space Optimization O(1)
        // Just iterate the array twice
        for (int i{1}; i < size; i++)
        {
            answer[i] = answer[i - 1] * nums[i - 1];
        }

        int suffix = 1; // Need to track
        for (int i(size - 2); i >= 0; i--)
        {
            suffix *= nums[i + 1];
            answer[i] *= suffix;
        }

        return answer;
    }
};
