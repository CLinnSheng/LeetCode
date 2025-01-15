#include <climits>
#include <unordered_map>
#include <vector>
using std::vector;

/*
 * Goal: Return all elements that appear more than n / 3 times
 *
 * Intuition: The most simplest & direct way is by using hash data structure
 * We just need to iterate through the arrays and record the count.
 * Then iterate the hash again & get all those with count more than n / 3 time
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * What if the interviewer ask is it possible to make it in O(1) for the space complexity
 * if we observe right there is only at most possible 2 elements to return
 * we can also use the BM voting algorithm like the first version question
 * we just need to be more cautious for the edge case
 * */
class Solution
{
  public:
    vector<int> majorityElement(vector<int> &nums)
    {
        int n(nums.size());

        // std::unordered_map<int, int> freq;
        // for (const auto &num : nums)
        //     freq[num]++;
        //
        // std::vector<int> answer;
        // for (const auto &[num, cnt] : freq)
        //     if (cnt > (n / 3))
        //         answer.emplace_back(num);
        //
        // return answer;

        // since at most 2 answer
        int n1{INT_MAX}, n2{INT_MAX};
        int cnt1{}, cnt2{};

        for (const auto &num : nums)
        {
            if (num == n1)
                cnt1++;
            else if (num == n2)
                cnt2++;
            // if goes to 0 then we change value
            else if (cnt1 == 0)
            {
                n1 = num;
                cnt1++;
            }
            else if (cnt2 == 0)
            {
                n2 = num;
                cnt2++;
            }
            else
            {
                cnt1--;
                cnt2--;
            }
        }
        // need to check again because the 2 majority element
        // might not be more than n / 3
        cnt1 = cnt2 = 0;
        for (const auto &num : nums)
            if (num == n1)
                cnt1++;
            else if (num == n2)
                cnt2++;

        std::vector<int> answer;
        if (cnt1 > (n / 3))
            answer.emplace_back(n1);
        if (cnt2 > (n / 3))
            answer.emplace_back(n2);

        return answer;
    }
};
