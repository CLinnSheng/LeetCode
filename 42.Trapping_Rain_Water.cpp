#include <algorithm>
#include <vector>

/*
 * Given n non-negative integer representing an elevation map where the width of each bar is 1.
 * Goal: Compute how much water it can trap.
 *
 * Intuition:
 * One important key observation is the water trap is not just based on its left & right boundary.
 * Is actually based on the left max & right max.
 * for eg: 2,1,0,1,2
 * The water stored at the index having 0 is not 1 but actually 2.
 * So what we can do is have a prefix and suffix array that store the maximum left and right for each index.
 * Another approach without using any additional space is actually using 2 pointer.
 * Since we want to find the total water and we assume the water has to be maximum, so we will keep
 * moving the pointer with lesser heigher
 * Since we moving the pointer with lesser height, we only need to consider its side as the other side is definitely
 * greater than it Time Complexity: O(n)
 * */
class Solution
{
  public:
    int trap(std::vector<int> &height)
    {
        int waters{};
        int left{}, right(height.size() - 1);
        int leftMax{height[left]}, rightMax{height[right]};

        while (left < right)
        {
            if (leftMax < rightMax)
            {
                leftMax = std::max(leftMax, height[++left]);
                waters += leftMax - height[left];
            }
            else
            {
                rightMax = std::max(rightMax, height[--right]);
                waters += rightMax - height[right];
            }
        }

        return waters;
    }
};
