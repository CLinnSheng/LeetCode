#include <vector>
using std::vector;

/*
 * Goal: Return the prefix common array of A & B
 * Prefix Common Array: array C such that C[i] is equal to the amount of numbers that present
 * or before the index i in both A & B.
 *
 * Intuition: Use unordered set to store the character for each earray.
 * Then compare the 2 set if equal then increase the cnt.
 * but using set couldnt solve the problem if the character doesnt appear at the same time
 *
 * So the bettwer way is usep map, for each iteration we will check if the number of occurence is equal to 2 which
 * that means the array exists from both array
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution
{
  public:
    vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
    {
        int size(A.size()), commonCount{};
        vector<int> answer(size), freqCount(size + 1, 0);

        for (int i{}; i < size; i++)
        {
            // we check every each element from each array to handle cases
            // that the character dont come at the same time
            freqCount[A[i]]++;
            if (freqCount[A[i]] == 2)
                commonCount++;

            freqCount[B[i]]++;
            if (freqCount[B[i]] == 2)
                commonCount++;

            answer[i] = commonCount;
        }
        return answer;
    }
};
