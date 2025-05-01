#include <climits>
#include <unordered_map>
#include <vector>
/*
 * Given integer array of size n
 * Goal: Find all elements that appear more than n/3 times
 *
 * Intuition:
 * The simplest method is to track the frequency of each element by using a hash map
 * Then iterate through the map and find all that n/3 times
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * How can we optimze the time complexity to O(1)?
 * We can make use of the bm voting algorithm in majority element I
 * Just have to tweek abit
 */
class Solution
{
  public:
    std::vector<int> majorityElement(std::vector<int> &nums)
    {
        // int n(nums.size());
        //
        // std::vector<int> ans;
        //
        // std::unordered_map<int, int> freq;
        // for (const auto &num : nums)
        //     freq[num]++;
        //
        // for (const auto &[val, cnt] : freq)
        //     if (cnt > (n / 3))
        //         ans.emplace_back(val);
        //
        // return ans;

        int n(nums.size());
        int cnt1{}, cnt2{};
        int num1{INT_MAX}, num2{INT_MAX};
        std::vector<int> answer;

        for (const auto &num : nums)
        {
            if (num1 == num)
                cnt1++;
            else if (num2 == num)
                cnt2++;
            else if (cnt1 == 0)
            {
                num1 = num;
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                num2 = num;
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }

        // since we got the 2 most element but we need to check again it might not more than n/3 times
        cnt1 = cnt2 = 0;
        for (const auto &num : nums)
            if (num == num1)
                cnt1++;
            else if (num == num2)
                cnt2++;

        if (cnt1 > n / 3)
            answer.emplace_back(num1);
        if (cnt2 > n / 3)
            answer.emplace_back(num2);

        return answer;
    }
};
