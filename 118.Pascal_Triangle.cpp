#include <vector>
/*
 * Intuition:
 * Solve it recursively and the sample answer is actually from the level 1. So this hint us to solve recursively from
 * the bottom. And then form the next row with the inforation from the previous rows
 Time Complexity: O(n^2)
 * */
class Solution
{
  public:
    std::vector<std::vector<int>> generate(int numRows)
    {
        // Base Case
        if (numRows == 0)
            return {{}};
        if (numRows == 1)
            return {{1}};

        std::vector<std::vector<int>> prevRows{generate(numRows - 1)};
        std::vector<int> nxtRow(numRows, 1);

        // first and last element no need to do computation
        for (int i{1}; i < numRows - 1; i++)
            nxtRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];

        prevRows.emplace_back(nxtRow);

        return prevRows;
    }
};
