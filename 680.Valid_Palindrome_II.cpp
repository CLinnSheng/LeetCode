#include <string>
#include <string_view>

/*
 * Goal: Check whether the string still a palindrome after deleting at most one character from it
 *
 * Intuition:
 * By brute force is to try every single possible of string.
 * Time Complexity: O(n^2)
 *
 * To optimize it we only try the 2 possible strings when they are not equal (2 pointer)
 * Time Complexity: O(n) because at most we only check once
 * */
class Solution
{
  private:
    bool isPalindrome(const std::string_view &s)
    {
        int left{}, right{static_cast<int>(s.length()) - 1};

        while (left < right)
        {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }

  public:
    bool validPalindrome(std::string s)
    {
        if (isPalindrome(s))
            return true;

        int left{}, right{static_cast<int>(s.length()) - 1};
        while (left < right)
        {
            if (s[left] != s[right])
                return isPalindrome(s.substr(0, left) + s.substr(left + 1)) ||
                       isPalindrome(s.substr(0, right) + s.substr(right + 1));
            left++;
            right--;
        }
        return true;
    }
};
