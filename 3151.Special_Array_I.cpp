#include <vector>
using std::vector;

class Solution
{
  private:
    bool checkParity(const int &num1, const int &num2)
    {
        return (num1 % 2 == num2 % 2);
    }

  public:
    bool isArraySpecial(vector<int> &nums)
    {
        if (nums.size() == 1)
            return true;

        for (int i{}; i < nums.size() - 1; i++)
            if (checkParity(nums[i], nums[i + 1]))
                return false;

        return true;
    }
};
