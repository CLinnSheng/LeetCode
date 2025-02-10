#include <algorithm>
#include <cctype>
#include <string>
#include <vector>
using std::string;

/*
 * Remove all digits by following this operation:
 * Delete the first digit & the closest non-digit character to its left
 *
 * Intuition:
 * For the delete operation, whenever we found a digit we need to a character also from its left.
 * So we will need 2 pointer, 1 pointing at the answer and another 1 pointing to the string s which will be iterate
 * through whenever we meet a non digit character, we will just as usual fill in the answer string but when we meet a
 * digit, we dont need to add it but we need to decrement the answer length by 1 because need to digit 1 non-digit
 * character
 * */
class Solution
{
  public:
    string clearDigits(string s)
    {
        int len{};
        for (int i{}; i < s.length(); i++)
        {
            if (std::isdigit(s[i]))
            {
                // meet a digit character
                // need to remove 1 non-digit character also so we simply just get the answer len and minus by 1
                len = std::max(len - 1, 0);
            }
            // we need to keep moving the current index i to the answer index
            else
            {
                s[len++] = s[i];
            }
        }

        // remove all the character that is greater than index len - 1
        s.resize(len);

        return s;
    }
};
