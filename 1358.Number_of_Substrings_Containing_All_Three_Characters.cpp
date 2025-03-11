#include <string>
#include <vector>
using std::string;

/*
 * String s only contain characters a, b, and c.
 * Goal: Return the total number of substrings containing at least one occurence of all these characters a, b and c.
 *
 * Intuitoin:
 * When i see substring the first i come in mind is using sliding window.
 * And then from the example given, the substring doesnt need to be in the order of a,b,c and not unique.
 * This makes it easier.
 * So whenever we have the substring of a, b, c of at least 1. any characters append behind will also be valid.
 * So the number of substring will just simply be len - right
 *
 * Time Complexity: O(n)
 * */
class Solution
{
  private:
    bool checkString(const std::vector<int> &freq)
    {
        return freq[0] > 0 && freq[1] > 0 && freq[2] > 0;
    }

  public:
    int numberOfSubstrings(string s)
    {
        std::vector<int> freq(3, 0);
        int left{}, right{};
        int len(s.length());
        int answer{};

        while (right < len)
        {
            freq[s[right] - 'a']++;

            while (checkString(freq))
            {
                answer += len - right;

                // move the left pointer because we already find out all the possible substring from this window
                freq[s[left] - 'a']--;

                left++;
            }
            right++;
        }
        return answer;
    }
};
