#include <vector>
/*
 * Easiest way is to use a hashset but this will ended up in O(n)
 * How can we make it in O(1)?
 * That means we cannot use any container or array
 * So just a single variable
 * We can use XOR because XORing the same number will result in 0, so we can easily find out the number that appears
 * only  once
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
