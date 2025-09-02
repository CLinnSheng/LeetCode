#include <vector>

/*
 * points (n x 2) representing the integer coordinates on a 2D plane, where points[i] = [xi, yi]
 * Pair of points(A, B) where
 * i. A is on the upper left side of B
 * ii. NO other points in the rectangle they make
 * Goal: Count the number of pair of points
 *
 * Intuition:
 * In naive way, we can just run the stimulation
 * */
class Solution
{
  public:
    int numberOfPairs(std::vector<std::vector<int>> &points)
    {
        int answer{}, n(points.size());

        for (int pt1{}; pt1 < n; pt1++)
        {
            for (int pt2{}; pt2 < n; pt2++)
            {
                if (pt1 != pt2)
                {
                    bool contains{false};
                    // A is on the upper left side of B
                    if (points[pt1][0] < points[pt2][0] && points[pt1][1] > points[pt2][1] ||
                        (points[pt1][0] < points[pt2][0] && points[pt1][1] == points[pt2][1]) ||
                        (points[pt1][0] == points[pt2][0] && points[pt1][1] > points[pt2][1]))
                    {
                        // Then loop again to check whether is there any point inside the rectangle
                        for (int pt3{}; pt3 < n; pt3++)
                        {
                            if (pt3 == pt1 || pt3 == pt2)
                                continue;

                            int x{points[pt3][0]}, y{points[pt3][1]};
                            if ((x >= points[pt1][0] && x <= points[pt2][0]) &&
                                (y >= points[pt2][1] && y <= points[pt1][1]))
                            {
                                contains = true;
                                break;
                            }
                        }
                        answer += !contains;
                    }
                }
            }
        }
        return answer;
    }
};
