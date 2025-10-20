#include <string>
#include <vector>

/*
 * Initially the value is 0.
 * Goal: Return the final value of x after performing all the operations
 *
 * Intuition:
 * Just check on the middle elment of each string
 * */
class Solution
{
  public:
    int finalValueAfterOperations(std::vector<std::string> &operations)
    {
        int ans{};

        for (const auto &operation : operations)
        {
            if (operation[1] == '+')
                ans++;
            else
                ans--;
        }

        return ans;
    }
};
