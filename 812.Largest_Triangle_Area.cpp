#include <cmath>
#include <vector>
/*
 * Goal: Return the area of the largest Triangle
 *
 * Intuition:
 *
 * */
class Solution
{
  private:
    double area(std::vector<int> &a, std::vector<int> &b, std::vector<int> &c)
    {
        return 0.5 * std::abs(a[0] * b[1] + b[0] * c[1] + c[0] * a[1] - a[1] * b[0] - b[1] * c[0] - c[1] * a[0]);
    }

  public:
    double largestTriangleArea(std::vector<std::vector<int>> &points)
    {
        int n(points.size());
        double ans{};

        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    ans = std::max(ans, area(points[i], points[j], points[k]));
                }
            }
        }
        return ans;
    }
};
