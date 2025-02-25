#include <climits>
#include <vector>
using std::vector;

/*
 * Goal: Return the number of subarrays with an odd sum.
 *
 * Intuition:
 * We can solve this by using brute force but with a time complexity of O(n^2)
 * How can we optimize it? Through the simulation of brute force, I observed we are doing some repeating work.
 * eg: [1,2,4] --> [1], [1,2], [1,2,4], [2,4]. Heres the thing at here for [2,4] can we use the information before we
 * have in [1,2,4] And also Even + Odd --> Odd We can do it in a clever way at i, if i is a odd number then we need to
 * know how many even number subarray before i.
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    int numOfSubarrays(vector<int> &arr)
    {
        int answer{};
        // EvenCnt is initially set to 1 because the initial value of sum is 0
        // so we can handle cases where the subarray with size 1
        // OddCnt & EvenCnt track their respective number of subarray
        int oddCnt{}, evenCnt{1}, sum{};

        for (const auto &val : arr)
        {
            sum += val;

            // if the current sum is odd
            // then we need to know how many odd subarray we have before this index
            if (sum % 2)
            {
                answer += evenCnt;
                oddCnt++;
            }
            // even then find the number of even subarray we have before this
            else
            {
                answer += oddCnt;
                evenCnt++;
            }
            answer %= int(1e9 + 7);
        }
        return answer;
    }
};
