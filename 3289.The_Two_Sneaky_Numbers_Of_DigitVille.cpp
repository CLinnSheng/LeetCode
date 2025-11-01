#include <unordered_map>
#include <vector>
/*
 * Goal: Find the 2 number that appears more than once
 *
 * Intuition: Just use a hash map
 * */
class Solution
{
  public:
    std::vector<int> getSneakyNumbers(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        for (const auto i : nums)
        {
            map[i]++;
        }

        std::vector<int> res;
        res.reserve(2);

        for (const auto &[key, value] : map)
        {
            if (value > 1)
            {
                res.push_back(key);
            }
        }
        return res;
    }
};
