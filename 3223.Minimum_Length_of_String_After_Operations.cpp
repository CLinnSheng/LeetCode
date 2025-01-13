#include <string>
#include <unordered_map>
using std::string;

/*
 * Goal: Return the minimum length of the final string s that you can achieve
 *
 * Operation: (any number of time or as much as possible because we're trying to find the minimum)
 * i. Choose an index i such that there is at least one character at the left and also at least one character to the
 * right that is equal to s[i] ii. Delete the closest character to the left of s[i] iii. Delete the closest character to
 * the right of s[i]
 *
 * Intuition:
 * Since the operation involve finding character that has at least 1 same character on left and right side.
 * We know the frequency of each character does matters & then for an operation to carry on the frequency of
 * character must be at least 3.
 * We dont really need to know the exact position of the character, because at worst they are all lump together like
 * this aaa. In any case if the character have frequency more than 3, is legit to carry on the operation
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    int minimumLength(string s)
    {
        std::unordered_map<char, int> freqCount;
        for (const auto &c : s)
            freqCount[c]++;

        int length{};
        for (auto &[_, cnt] : freqCount)
        {
            // we know that we must have at least 3 characters of it
            // so we will keep on deleting if it has more than 3
            while (cnt >= 3)
                cnt -= 2;
            length += cnt;
        }
        return length;
    }
};
