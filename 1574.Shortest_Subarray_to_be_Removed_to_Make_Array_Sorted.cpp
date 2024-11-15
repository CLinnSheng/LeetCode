#include <vector>

/*
Goal: Remove a subarray such that the remaining elements in array is in
ascending order, return the length of the shortest subarray to remove.

Intuition: We can use 2 pointers approach. 1 pointer is the prefix while the
other pointer is the postfix. the prefix pointer will be starting from the first
index while the postfix index is point to the first index of the elements in
ascending order from the back. Then we will keep moving the prefix index and
postfix index by determining whether are they still in ascending order

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
  int findLengthOfShortestSubarray(std::vector<int> &arr) {
    int size(arr.size());
    if (size == 1)
      return 0;

    int postfix_ptr{size - 1};

    while (postfix_ptr > 0 && arr[postfix_ptr] >= arr[postfix_ptr - 1])
      postfix_ptr--;

    int prefix_ptr{};
    int ans{postfix_ptr};

    while (prefix_ptr < postfix_ptr &&
           (prefix_ptr == 0 || arr[prefix_ptr - 1] <= arr[prefix_ptr])) {
      while (postfix_ptr < size && arr[prefix_ptr] > arr[postfix_ptr])
        postfix_ptr++;

      ans = std::min(ans, postfix_ptr - prefix_ptr - 1);
      prefix_ptr++;
    }

    return ans;
  }
};
