#include <algorithm>
#include <vector>
/*
 * Goal: Find the largest perimeter triangle
 *
 * Intuition:
 * Need to find a valid triangle where A + B > C and at the same time A + B + C has to be the largest perimeter
 * We can sort the array and then just iterate through the array from the back because the first 1 we encounter will be
 * the largest perimeter triangle
 * */
class Solution
{

  public:
    int largestPerimeter(std::vector<int> &A)
    {
        std::sort(A.begin(), A.end());
        for (int i(A.size() - 3); i >= 0; i--)
            if (A[i] + A[i + 1] > A[i + 2])
                return A[i] + A[i + 1] + A[i + 2];
        return 0;
    }
};
