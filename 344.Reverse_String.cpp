#include <vector>

/*
 * Goal: Reverse the string
 * Constraint: O(1) memory
 *
 * Intuition:
 * Since we cannot have extra memory to copy the string
 * We can only word on the original variable that hold the string
 * we can done it by using 2 pointer 1 point at the front while the other 1 point at the back
 * */
class Solution
{
  public:
    void reverseString(std::vector<char> &s)
    {
        int left{}, right(s.size() - 1);

        while (left < right)
        {
            auto temp{s[left]};
            s[left] = s[right];
            s[right] = temp;

            left++;
            right--;
        }
    }
};
