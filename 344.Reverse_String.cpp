#include <utility>
#include <vector>

/*
 * Goal: Reverse the string
 * Constraint: O(1) memory
 *
 * Intuition:
 * Since we cannot have extra memory to copy the string
 * So we cannot have a vector of the same size which will cause O(n)
 * what we can do is using 2 pointer change internally
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    void reverseString(std::vector<char> &s)
    {
        int left{}, right(s.size() - 1);

        while (left <= right)
        {
            std::swap(s[left], s[right]);
            left++;
            right--;
        }
    }
};
