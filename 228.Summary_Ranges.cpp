#include <cstddef>
#include <string>
#include <vector>

/*
 * Given a sorted unique integer array nums.
 * Return the smallest sorted list of ranges that cover all the number in the
 * array exactly. i. "a->b" where a != b ii. "a" if a == b
 * */
class Solution {
public:
  std::vector<std::string> summaryRanges(std::vector<int> &nums) {
    std::size_t len{nums.size()};
    if (!len)
      return {};

    std::vector<std::string> ans;
    int startingVal{nums[0]};

    for (int i{}; i < len - 1; i++)
      if (nums[i] != nums[i + 1] - 1) {
        if (nums[i] == startingVal)
          ans.emplace_back(std::to_string(startingVal));
        else
          ans.emplace_back(std::to_string(startingVal) + "->" +
                           std::to_string(nums[i]));

        startingVal = nums[i + 1];
      }

    ans.emplace_back(startingVal == nums[len - 1]
                         ? std::to_string(startingVal)
                         : std::to_string(startingVal) + "->" +
                               std::to_string(nums[len - 1]));

    return ans;
  }
};
