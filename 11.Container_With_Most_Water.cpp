#include <algorithm>
#include <vector>

/*
 * There are n vertical lines
 * Goal: Return the maximum amount of water a container can store
 *
 * Intuition:
 * The naive way will just simply have 2 nested loop that will try all possible sizes of container.
 * But this will take O(n^2)
 *
 * How can we optimize it? To O(n) or others?
 * Area = Length * Height
 * Since we cannot control the length but we can control the height.
 * We also need to be greedy at the same time.
 * We can use 2 pointer approach, every time we will move the pointer with the lower heights
 * Time Complexity: O(N)
 * */
class Solution
{
  public:
    int maxArea(std::vector<int> &height)
    {

        int maxArea{};
        int left{}, right(height.size() - 1);

        while (left < right)
        {
            int area{std::min(height[left], height[right]) * (right - left)};
            maxArea = std::max(area, maxArea);

            if (height[left] > height[right])
                right--;
            else
                left++;
        }

        return maxArea;
    }
};
