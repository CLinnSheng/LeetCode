#include <algorithm>
#include <vector>

/*
 * Goal: Find the subarray that has the largest product
 *
 * Intuition:
 * The brute force will be just simply try out all possible subarray combination
 * but this will take O(N^2)
 *
 * How can we optimize it?
 * The element in nums can be negative or positive, so this make the decision for inlcude the element become more
 * complicated. As negative * negative -> positive And also greater negative element * negative -> much more greater
 * positive element So this lead us to think about always include more element as much as possible Another key
 * observation is traversing the array in different direction will result in different answer eg: -1 -2 -3 left: -1 -> 2
 * -> -6 right: -3 -> 6 -> -1 maximum product from left is 2 where from right is 6 So we can actually maintain a prefix
 * and suffix array Time Complexity: O(n)
 *
 * Another approach is actually using kadane.
 * First the question only ask us to find the maximum product from the subarray but not finding the subarray
 * So, we only care about the end result. Since we mention we want try to include more element as possible and having
 * very least negative value is not a bad thing. So we can actually maintain a current max value and curr min value
 * */
class Solution
{
  public:
    int maxProduct(std::vector<int> &nums)
    {
        int n(nums.size());

        if (n == 1)
            return nums[0];

        int answer{};

        // Approach 1
        // int prefix{}, suffix{};
        //
        // for (int i{}; i < nums.size(); i++)
        // {
        //     prefix = nums[i] * (prefix == 0 ? 1 : prefix);
        //     suffix = nums[n - i - 1] * (suffix == 0 ? 1 : suffix);
        //
        //     answer = std::max(answer, std::max(prefix, suffix));
        // }

        int maxVal{1}, minVal{1};
        for (const auto num : nums)
        {
            // Still need to compare with num in case both maxVal and minVal is negative
            // so we have a new subarray starting from num
            int temp{maxVal};
            maxVal = std::max(num * maxVal, std::max(num, num * minVal));
            minVal = std::min(num * temp, std::min(num, num * minVal));

            answer = std::max(maxVal, answer);
        }
        return answer;
    }
};
