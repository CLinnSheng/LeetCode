#include <vector>

/*
 * Goal: Return a list of integers from 1 to n whose sum is 0.
 *
 * Intuition:
 * Just add complement number for example +7 and -7
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<int> sumZero(int n)
    {
        if (n == 1)
            return {0};

        std::vector<int> answer;
        int iteration{n / 2};
        int curr{1};

        for (int i{}; i < iteration; i++)
        {
            answer.emplace_back(curr);
            answer.emplace_back(curr * -1);
            curr++;
        }

        if (n % 2)
            answer.emplace_back(0);

        return answer;
    }
};
