#include <string>
#include <vector>

/*
 * Given a string s, and an integer t representing the number of transformations to perform.
 * In one transformation, every character in s is replaced according to the rules:
 * i. 'z' -> 'ab'
 * ii. Otherwise replace it with the next character. For instance, 'b' -> 'c'
 *
 * Goal: Return the length of the resulting string after t transformations.
 *
 * Intuition:
 * Do we really have to keep track of the character at every index?
 * Not really, what we need to know is just the frequency of each character. We dont need to know how it will change
 * inplace. So we need to take care of cases of z. So when z transofrm we will increase both 'a' and 'b' by 1
 * Time Complexity: O(t)
 * Space Complexity: O(1)
 *
 * */
class Solution
{
  private:
    const int MOD = 1e9 + 7;

  public:
    int lengthAfterTransformations(std::string s, int t)
    {
        std::vector<long long> freq(26, 0);

        for (const auto &ch : s)
            freq[ch - 'a']++;

        while (t)
        {
            std::vector<long long> nxtFreq(26, 0);

            for (int i{}; i < 26; i++)
            {
                if (freq[i] != 0)
                {
                    if (i != 25)
                        nxtFreq[i + 1] = (nxtFreq[i + 1] + freq[i]) % MOD;
                    else
                    {
                        nxtFreq[0] = (nxtFreq[0] + freq[i]) % MOD;
                        nxtFreq[1] = (nxtFreq[1] + freq[i]) % MOD;
                    }
                }
            }

            freq = nxtFreq;

            t--;
        }

        int answer{};
        for (const auto &i : freq)
            answer = (answer + i) % MOD;

        return answer;
    }
};
