#include <vector>
using std::vector;

/*
 * Goal: Return the nums after the arrangement
 *
 * Intuition:
 * Since the order of the arrangement doesnt matter
 * What we need to do is just partition the number into 3 part lesser, equal and greater
 * Then in the end just append all together
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    vector<int> pivotArray(vector<int> &nums, int pivot)
    {
        vector<int> lesser, equal, greater;

        for (const auto &num : nums)
        {
            if (num == pivot)
                equal.emplace_back(num);
            else if (num > pivot)
                greater.emplace_back(num);
            else
                lesser.emplace_back(num);
        }

        lesser.insert(lesser.end(), equal.begin(), equal.end());
        lesser.insert(lesser.end(), greater.begin(), greater.end());

        return lesser;
    }
};
