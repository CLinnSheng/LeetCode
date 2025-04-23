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
        // int n(nums.size());
        // std::vector<int> answer(n);
        // std::vector<int> prefix(n), suffix(n);
        //
        // // Precompute
        // prefix[0] = 1;
        // suffix[n - 1] = 1;
        //
        // for (int i{1}; i < n; i++)
        //     prefix[i] = prefix[i - 1] * nums[i - 1];
        // for (int i{n - 2}; i >= 0; i--)
        //     suffix[i] = suffix[i + 1] * nums[i + 1];
        //
        // for (int i{}; i < n; i++)
        //     answer[i] = prefix[i] * suffix[i];
        //
        // return answer;

        // Optimze Space Complexity
        int n(nums.size());
        std::vector<int> answer(n, 1);

        for (int i{1}; i < n; i++)
            answer[i] = answer[i - 1] * nums[i - 1];

        int postfix{1};
        for (int i{n - 1}; i >= 0; i--)
        {
            answer[i] = answer[i] * postfix;
            postfix *= nums[i];
        }

        return answer;
    }
};
