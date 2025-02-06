#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Given an array nums of distinct integers, return the number of tuples (a, b, c, d) such that a * b = c * d and they
 * are all not equal
 *
 * Intuition:
 * from the example we know that the tuple (a, b, c, d) has 8 diff combinations
 * where
 * a * b = c * d
 * a * b = d * c
 * b * a = c * d
 * b * a = d * c
 * and another 4 just switching the left and right
 *
 * so basically we just need to found out all possible product from the nums.
 * Time Complexity: O(n^ 2)
 * */
class Solution
{
  public:
    int tupleSameProduct(vector<int> &nums)
    {
        if (nums.size() < 4)
            return 0;

        std::unordered_map<int, int> product_freq;
        for (int i{}; i < nums.size(); i++)
            for (int j{i + 1}; j < nums.size(); j++)
                product_freq[nums[i] * nums[j]]++;

        int answer{};

        for (const auto &[product, freq] : product_freq)
        {
            int pairs = freq * (freq - 1) / 2;
            answer += 8 * pairs;
        }
        return answer;
    }
};
