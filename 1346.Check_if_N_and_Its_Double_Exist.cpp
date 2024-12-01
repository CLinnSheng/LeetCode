#include <unordered_set>
#include <vector>

/*
 * Goal: Check if there exists 2 indices i & j such that
 * i != j
 * 0 <= i,j < arr.length
 * arr[i] == 2 * arr[j]
 *
 * Intuition: Has a hash set to store the number and while looping through the
 * array check whether its 2 * arr[i] exists or arr[i] / 2 exists or not and
 * also make sure is an even number
 *
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  bool checkIfExist(std::vector<int> &arr) {
    std::unordered_set<int> nums;

    for (const auto &num : arr)
      if (nums.count(num * 2) || (nums.count(num / 2) && !(num % 2)))
        return true;
      else
        nums.insert(num);
    return false;
  }
};
