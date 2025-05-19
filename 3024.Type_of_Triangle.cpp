#include <string>
#include <unordered_set>
#include <vector>

/*
 * "equilateral": equal side
 * "isoceles": 2 equal sides
 * "scalene": "all sides are different lengths"
 * Goal: Return a string representing the type of triangle that can be formed or none
 *
 * Intuition:
 * Since need to return string based on the length, we can use a hash map to map the string
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * */
class Solution
{
  public:
    std::string triangleType(std::vector<int> &nums)
    {
        if ((nums[0] + nums[1] > nums[2]) && (nums[0] + nums[2] > nums[1]) && (nums[1] + nums[2] > nums[0]))
        {
            std::unordered_set<int> unique;
            for (const auto &num : nums)
                unique.insert(num);

            return unique.size() == 1 ? "equilateral" : unique.size() == 2 ? "isosceles" : "scalene";
        }

        return "none";
    }
};
