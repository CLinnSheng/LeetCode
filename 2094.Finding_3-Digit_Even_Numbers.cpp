#include <set>
#include <vector>

/*
 * Array may contain duplicates
 * Find all the unique integers that follow the requirements:
 * i. Consists of the concatenation of three elements from digits in any arbitrary oder
 * ii. No leading zeros
 * iii. Integer is even
 *
 * Goal: Return a sorted array of the unique integers.
 *
 * Intuition:
 * Brute force way will be trying all possible combinations
 * TIme Complexity: O(n^3)
 * */
class Solution
{
  public:
    std::vector<int> findEvenNumbers(std::vector<int> &digits)
    {
        std::set<int> nums;
        int n(digits.size());

        for (int i{}; i < n; i++)
            for (int j{}; j < n; j++)
                for (int k{}; k < n; k++)
                {
                    if (i == j || j == k || i == k)
                        continue;

                    // Check got meet requirements or not
                    int val{digits[i] * 100 + digits[j] * 10 + digits[k]};
                    if (val >= 100 && digits[k] % 2 == 0)
                        nums.insert(val);
                }

        return std::vector<int>(nums.begin(), nums.end());
    }
};
