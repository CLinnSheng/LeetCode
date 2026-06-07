
#include <cmath>
#include <vector>
/*
 * Return an array of output where output[i] is the number of 1's in the binary representation of i
 * Brute force way is for every number we will count it
 * This will result in O(n^2)
 * How can we achieve it in O(n)?
 * To reduce to  O(n) means that we have to find simpler way to find the number of 1 for each number
 * In order to do this we need to use the information of the previous element
 * Theres a pattern
 * 0 -> 0 arr[0] = 0
 * 1 -> 01 arr[1] = 1 / arr[1 - 2^0] + 1
 * 2 -> 10 arr[2] = 1 / arr[2 - 2] + 1
 * 3 -> 11 arr[3] = 2 / arr[3 - 2] + 1
 * 4 -> 100 arr[4] = 1 / arr[4 - 4] + 1
 * 5 -> 101 arr[5] = 2 / arr[5 - 4 + 1
 * 6 -> 110
 * 7 -> 111
 * 8 -> 1000
 * 9 -> 1001
 * 10 -> 1010
 * 11 -> 1011
 * 12 -> 1100
 * 13 -> 1101
 * 14 -> 1110
 * 15 -> 1111
 * SO whenever the number is a power of 2 we increase the index
 * */
class Solution
{
  public:
    std::vector<int> countBits(int n)
    {
        int pow{1};
        std::vector<int> ans(n + 1, 0);

        if (n >= 1)
        {
            ans[1] = 1;
        }

        for (int i{1}; i <= n; i++)
        {
            if (pow * 2 == i)
            {
                pow *= 2;
            }
            ans[i] = 1 + ans[i - pow];
        }
        return ans;
    }
};
