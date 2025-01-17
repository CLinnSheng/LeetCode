#include <vector>

/*
 * The given array is derived by XOR of adjacent values in a binary array orignal of the same length
 * Specifically for each index i in the range of [0, n -1]
 * if i = n - 1, then derived[i] = orignal[0] ^ orginal[n - 1]
 * otherwise derived[i] = orginal[i] ^ orignal[i + 1]
 *
 * Goal: Return true if such an array exists or false otherwise
 *
 * Intuition:
 * If we observe through dry run from the example both the orignal array & complement of original can derive out the
 * derived array. And for the operation of XOR for 1 the 2 adjacent value has to be different and for 0 it has to be the
 * same And the most critical part is actually the last value of derived because it involves the first element and the
 * last element from the original array. So actually, for the [0, n - 1] element of derived we definitely can derived
 * out but for the last element not neccessary. So we can stimulate the process by either starting as 0 or 1. It doesnt
 * matter Time Complexity: O(n) Space Complexity: O(1)
 * */
class Solution
{
  public:
    bool doesValidArrayExist(std::vector<int> &derived)
    {
        // we take first as '0'
        int first{}, last{};

        for (const auto &num : derived)
            // if it is a '1', then the next digit of the orignal array has to be different
            if (num)
                last ^= num;
        return first == last;
    }
};
