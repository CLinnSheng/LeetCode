#include <string>
#include <vector>

/*
 * Balanced: sum of the digit at even indices is equal to the sum of digits at odd indices.
 *
 * Goal: Return the number of distinct permutations of num that are balanced.
 *
 * Intuition:
 * Number of permutation will be n!
 * Since there might have duplicate characters, then the equation is just simply n! / (n1 * n2 * n3 * ..) where ni is
 * the frequency of each duplicate character
 *
 * But after that we need to filter out those arent balanced.
 * Another important observatoin is sum of at odd indices must equal to sum of at even indices, that means the total
 * must be divible by 2 in order to seperate into 2 evenly
 * */
class Solution
{
  private:
    const int MOD = 1e9 + 7;

  public:
    int countBalancedPermutations(std::string num)
    {
        std::vector<int> freq(10);
        int ttl{};
        for (const auto &_num : num)
        {
            freq[_num - '0']++;
            ttl += _num - '0';
        }
        if (ttl % 2)
            return 0;

        int len(num.length());
    }
};
