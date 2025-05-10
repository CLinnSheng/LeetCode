#include <cctype>
#include <cwctype>
#include <string>
/*
 * Goal: Check whether the string is palindrome or not
 *
 * Intuition:
 * Palindrome it reads the same forward and backward, so what we can do is split into half and one pointer moving right
 * another pointer moving left from the the start
 * Constraint: only consider alphabet and characters
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    bool isPalindrome(std::string s)
    {
        int left{}, right(s.length() - 1);

        while (left <= right)
        {
            if (!std::isalnum(s[left]))
            {
                left++;
                continue;
            }
            if (!std::isalnum(s[right]))
            {
                right--;
                continue;
            }

            if (towlower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};
