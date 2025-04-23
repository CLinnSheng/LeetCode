/*
 * Each number from 1 to n is grouped according to the sum of its digit
 *
 * Goal: Return the number of groups that have the largest size
 *
 * Intuition:
 * Since each value from 1 to n is grouped according to the sum of its digit.
 * Then we only need to iterate through from 1 to n, and store the frequency of particular sum in a hashmap
 * Then find the maximum frequency and count how many map has the same frequency
 * Time Complexity: O(n)
 * */
#include <unordered_map>
class Solution
{
  public:
    int countLargestGroup(int n)
    {
        int ans{};
        int maxSize{};
        std::unordered_map<int, int> map;

        for (int i{1}; i <= n; i++)
        {
            int temp{i}, digitSum{};
            while (temp)
            {
                digitSum += temp % 10;
                temp /= 10;
            }

            map[digitSum]++;
            maxSize = std::max(maxSize, map[digitSum]);
        }

        for (const auto &[_, freq] : map)
            if (freq == maxSize)
                ans++;

        return ans;
    }
};
