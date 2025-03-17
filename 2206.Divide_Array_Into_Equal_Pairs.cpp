#include <unordered_map>
#include <vector>

/*
 * Array nums consisting of 2 * n integers
 * Need to divide nums into n pairs such that:
 * -each element belongs to exactly one piar
 * -the elements present in a pair are equal
 *
 *  Intuition:
 *  Just use hash map to store the count of each num, if all are even then fine
 * */
class Solution
{
  public:
    bool divideArray(std::vector<int> &nums)
    {
        std::unordered_map<int, int> map;
        for (const auto &num : nums)
            map[num]++;

        for (const auto &[key, val] : map)
            if (val % 2 != 0)
                return false;

        return true;
    }
};
