#include <vector>

/*
 * Given a sorted array and an integer maximumBit. Perform following query n
 * times:
 * 1. find a non-negative integer from k < 2^maximumbit such that nums[0] XOR
 * nums[1] XOR ... nums[nums.length - 1] XOR k is maximize & k is the answer to
 * the ith query.
 * 2. Remove the last element from the current array nums.
 *
 * Goal: Return an array answer, where answer[i] is the answer to the ith query.
 *
 * Intuition:
 * The maximum number we can achieve in the array is actually 2^maximumbit - 1
 * So in order to get k number that XOR it to become 2^maximumbit - 1, we simply
 * just need to XOR the current arrayXOR because if a ^ b -> maxNumber then a ^
 * maximumNumber -> b Time Complexity: O(n) Space Complexity: O(1)
 * */
class Solution {
public:
  std::vector<int> getMaximumXor(std::vector<int> &nums, int maximumBit) {
    int currXORVal{};

    for (const int &num : nums)
      currXORVal ^= num;

    int maxVal{(1 << maximumBit) - 1};
    std::vector<int> ans;

    for (std::vector<int>::reverse_iterator it = nums.rbegin();
         it != nums.rend(); it++) {
      ans.emplace_back(currXORVal ^ maxVal);
      currXORVal ^= *it;
    }
    return std::move(ans);
  }
};
