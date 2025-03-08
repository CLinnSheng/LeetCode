#include <climits>
#include <string>
using std::string;

/*
 * Goal: Return the minimum number of operations needed such there is at least one occurence of k consecutive blocks
 *
 * Intuition:
 * Since we need to find k consecutive blocks, we can use a sliding window of size k.
 * so we will keep track of the number of white block within the subarray, that will be the number of blocks need to
 * recolor Time Complexity: O(n)
 * */
class Solution
{
  public:
    int minimumRecolors(string blocks, int k)
    {
        int len(blocks.length());
        if (k > len)
            return -1;

        int left{}, right{};
        int nWhite{}, nRecolor{INT_MAX};

        for (; right < len; right++)
        {
            // current right pointer is white, then increase the number of white
            if (blocks[right] == 'W')
                nWhite++;

            // if the window already reach k size, then we need to move the left pointer
            if (right - left + 1 == k)
            {
                // update the no of recolor
                nRecolor = std::min(nRecolor, nWhite);

                if (blocks[left] == 'W')
                    nWhite--;
                left++;
            }
        }
        return nRecolor;
    }
};
