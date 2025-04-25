#include <vector>

/*
 * Goal: Find the majority in the element that appears more than [n/2] times
 *
 * Intuition:
 * The most straight away approach is by using hash map
 * Store it in the hash map and iterate the hash map again to find out whose has n/2 times
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 *
 * But there's a much more clever way which will only take O(1) space
 * If we observe there is only one elment which is majority.
 * So if we count from the to the right where the count is current count of the majority element.
 * We will decrement it it whenever it is not equal to the current majority element. So in just simply says the majority
 * element will be surviving at last
 * */
class Solution
{
  public:
    int majorityElement(std::vector<int> &nums)
    {
        int freq{}, ans{};

        for (const auto &num : nums)
        {
            if (freq == 0)
            {
                ans = num;
            }

            freq += ans == num ? 1 : -1;
        }

        return ans;
    }
};
