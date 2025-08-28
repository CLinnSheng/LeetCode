#include <cmath>
#include <vector>
/*
 * dimensions[i][0] --> Length and dimensions[i][i] --> width of the rectangle i
 *
 * Goal: Return the area of the rectangle having the longest diagonal.
 *
 * Intuition:
 * Just simply go through the array have a variable that holding the index of the longest diagonal, just in case we
 * encounter another 1 with the same diagonal length
 * */
class Solution
{
  public:
    int areaOfMaxDiagonal(std::vector<std::vector<int>> &dimensions)
    {
        int answer{};
        float maxDiagonalLength{};
        for (int i{}; i < dimensions.size(); i++)
        {
            float diagonalLength = std::sqrt(std::pow(dimensions[i][0], 2) + std::pow(dimensions[i][1], 2));
            int area{dimensions[i][0] * dimensions[i][1]};

            if (diagonalLength > maxDiagonalLength)
            {
                answer = area;
                maxDiagonalLength = diagonalLength;
            }
            else if (diagonalLength == maxDiagonalLength)
            {
                answer = std::max(area, answer);
            }
        }

        return answer;
    }
};
