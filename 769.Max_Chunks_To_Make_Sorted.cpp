#include <vector>

/*
 * Given an array of length n consisting integers in the range of [0, n - 1]
 * Need to split the array into some number of chunks so that individually
 * sorted each chunk. After concatenating them, the result should equal to the
 * sorted array Goal: Return the largest number of chunks we can make to sort
 * the array
 *
 * Intuition:
 * an array eg: [4, 5, 3, 0, 1, 2]
 * if we split the chunks at index 1 the array will be splitted into 4 &
 * 5,3,0,1,2 after sorted each individual chunk the array is 4,0,1,2,3,5 which
 * is invalid So we can see it if we want to split it at a specific index let
 * say 0 then the chunk must contain 0 in order for the final array to be
 * correct
 *
 * The way to verify whether the chunk is valid or not is by checking whether
 * the maximum value in the chunk is equal to the index or not
 *
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */

class Solution
{
  public:
    int maxChunksToSorted(std::vector<int> &arr)
    {
        int res{};
        int maximumValue_Chunk{-1};

        for (int i{}; i < arr.size(); i++)
        {
            maximumValue_Chunk = std::max(maximumValue_Chunk, arr[i]);
            if (maximumValue_Chunk == i)
                res++;
        }
        return res;
    }
};

