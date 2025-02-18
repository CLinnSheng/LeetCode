#include <deque>
#include <string>

/*
 * 'I' - Increasing where nums[i] < nums[i + 1]
 * 'D' - Decreasing where nums[i] > nums[i + 1]
 * Create a length n + 1 by following the conditions
 * NOTE: Each digit is used at most once [1 - 9]
 *
 * Goal: Return the lexicographically smallest possible string num that meets the condition
 *
 * Intuition:
 * Since we want to find the lexicographically smallest string, so at every place we try to place the smallest number
 * first So for Increasing index, we will just straight away place it because thats the way to build a small
 * lexicographical string but how about for decreasing? Is the same, we also try to build lexicographical small string
 * also while following the conditions. So we can store the element in the stack, so that the element still following
 * the Decreasing conditions
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    std::string smallestNumber(std::string pattern)
    {
        std::string answer{};
        int n(pattern.length());
        std::deque<int> stack;

        for (int i{}; i <= n; i++)
        {
            stack.emplace_back(i + 1);

            // only place it if Increasing
            // because for decreasing we need to make sure answer[i] > answer[i + 1]
            // and hence we only place it after we encounter another I because the top of the stack will be the largest
            if (pattern[i] == 'I')
                while (!stack.empty())
                {
                    answer += std::to_string(stack.back());
                    stack.pop_back();
                }
        }

        while (!stack.empty())
        {
            answer += std::to_string(stack.back());
            stack.pop_back();
        }

        return answer;
    }
};
