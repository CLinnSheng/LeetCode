#include <algorithm>
#include <functional>
#include <vector>

/*
 * given a 2d array of coordinates, rectangles where rectangles[i] = [startx,starty,endx,endy]
 * (startx, starty) --> bottom left corner
 * (endx, endy) --> top right corner
 *
 * Rectangles do not overlap. Determine if is possible to make eihter two horizontal or two verticals cuts on the grid
 * such that: Each of the three resulting sections formed by the cuts contains at least one rectangle Every rectangle
 * belongs to exactly one section
 *
 *
 * Intuition:
 * Do we really need to find out which section does the rectangle belongs to?
 * Do we really need to know how to place the two horizontal or vertical cuts?
 * So we basically just need to find the nubmer of non overlapping rectangle.
 * so if we have number of non overlapping rectangle more than 3 then is valid because we can anyhow put the 2 vertical
 * or horizontal cut.
 * How do we find it? --> use interval algorithm.
 * Basically just iterate the  y coordinate for horizontal cut and then x coordinate for vertical cut. Must be in a
 * ascending order or descending order. then check whether the new rectangle overlapp with the old rectangle or not
 *
 * Time Complexity: O(nlgn)
 * */
class Solution
{
  public:
    bool checkValidCuts(int n, std::vector<std::vector<int>> &rectangles)
    {
        std::vector<std::vector<int>> xCoords, yCoords;
        for (const auto &rectangle : rectangles)
        {
            xCoords.emplace_back(std::vector<int>{rectangle[0], rectangle[2]});
            yCoords.emplace_back(std::vector<int>{rectangle[1], rectangle[3]});
        }

        std::sort(xCoords.begin(), xCoords.end());
        std::sort(yCoords.begin(), yCoords.end());

        std::function<int(const std::vector<std::vector<int>> &)> findNonOverlapping =
            [&](const std::vector<std::vector<int>> &coords) {
                int prev{-1}, cnt{};

                for (const auto &coord : coords)
                {
                    if (coord[0] >= prev)
                        cnt++;
                    prev = std::max(prev, coord[1]);
                }

                return cnt;
            };

        return std::max(findNonOverlapping(xCoords), findNonOverlapping(yCoords)) >= 3;
    }
};
