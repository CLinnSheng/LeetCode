#include <string>

/*
 * Given a string s, return true if the s can be a palindrome after deleting at most one character from it
 *
 * Constraint: Only lowercase letter
 * Goal: Check whether the string is palindrome or not (can delete at most one character)
 *
 * Intuitoin:
 * The brute force way will just simply try all possibel string by deleting 1 character
 * Time Complexity: O(N^2)
 *
 * Is there any way to optimize it?
 * Do we really need to check every single possible string?
 * How about we only check when the left end and right end is not equal --> Then determine delete from which end
 * Time Complexity: O(n)
 * Because the isPalindrome only check once whenever we encounter a character has to be delete --> O(n)
 * The reason why the result is came out whenever there is a character has to be delete. So if got one mismatch and
 * by deleting it still cannot form palindrome then for sure the string is not palindrome, theres no point continue
 * */
class Solution
{
  private:
    // O(n)
    bool isPalindomre(const std::string &s)
    {
        int left{}, right(s.length() - 1);

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
        // if (isPalindomre(s))
        //     return true;
        // for (int i{}; i < s.length(); i++)
        // {
        //     std::string new_str = s.substr(0, i) + s.substr(i + 1);
        //     if (isPalindomre(new_str))
        //         return true;
        // }
        // return false;

        if (isPalindomre(s))
            return true;

        int left{}, right(s.length() - 1);
        // O(n)
        while (left < right)
        {
            if (s[left] != s[right])
                return (isPalindomre(s.substr(0, left) + s.substr(left + 1)) ||
                        isPalindomre(s.substr(0, right) + s.substr(right + 1)));

            left++;
            right--;
        }
        return false;
    }
};
