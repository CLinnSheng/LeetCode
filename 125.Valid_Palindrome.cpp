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
        // 2 pointer 1 from the front and 1 from the back
        // skip blank spaces and also make sure to convert to either upper or lower case
        int left{}, right(s.length() - 1);

        while (left <= right)
        {
            while (!std::isalnum(s[left]))
                left++;
            while (!std::isalnum(s[right]))
                right--;

            if (left > right)
                break;

            if (std::toupper(s[left]) != std::toupper(s[right]))
                return false;

            left++;
            right--;
        }
        return true;
    }
};
