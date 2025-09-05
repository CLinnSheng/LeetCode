#include <algorithm>
#include <climits>
#include <vector>
/*
 * Question is is similar to the first version
 * Only difference is that we need to optimize. Before that is O(n^3)
 * Now we need to optimize it to O(n^2)
 * Intuition:
 * We can reduce one loop by actually doing sorting, the points.
 * So that we make sure the next point is always outside of the box
 * */
class Solution
{

  public:
    int numberOfPairs(std::vector<std::vector<int>> &points)
    {
        std::sort(points.begin(), points.end(), [](const auto &A, const auto &B) {
            // point b x > point a x
            // or if same coordinate x, then point b y must be smaller than point a y
            return A[0] < B[0] || (A[0] == B[0] && A[1] > B[1]);
        });

        int ans{};
        for (int i{}; i < points.size(); i++)
        {
            const auto &pointA{points[i]};
            int xMin{pointA[0]};
            int xMax(INT_MAX);
            int yMax{pointA[1]};
            int yMin(INT_MIN);

            for (int j{i + 1}; j < points.size(); j++)
            {
                const auto &pointB{points[j]};
                if (pointB[0] >= xMin && pointB[0] < xMax && pointB[1] > yMin && point B[1] <= yMax)
            }
        }

        return ans;
    }
};
