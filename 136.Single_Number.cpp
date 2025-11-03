#include <vector>
/*
 * Every integer appear twice except for one. Find that single one.
 *
 * Intuition:
 * We can use XOR because A XOR B XOR A = A
 * */
class Solution
{
  public:
    int singleNumber(std::vector<int> &nums)
    {
        int ans{};

        for (const auto num : nums)
        {
            ans ^= num;
        }
        return ans;
    }
};
