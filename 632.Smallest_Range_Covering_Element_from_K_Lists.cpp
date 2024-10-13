#include <algorithm>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

/*
 * Given k listed of sorted integers in ascending oreder. Find the smallest
 * range that includes at least one number from each of the k lists. Intuition:
 * Lets Break into smaller problem where we only have 2 lists We could solve it
 * by using 2 pointer where each pointer point to 1 list THen compute the min
 * every time we move the pointer (we move the pointer with the lower value)
 * when one of the pointer is out of range then we know we are done.
 * Time Complexity for this is O(n + m)
 *
 * So for k list is work the same.
 * TAKE NOTE: The reason why we dont want to continue when one of the pointer
 * goes out of range is beacuse you are no longer updating the pointer with
 * lower value So the newest value diff will definitely is bigger so no point to
 * continue Time Comeplxity: O(n * k) where n is the total number of elements
 * from 3 lists and k is the number of comparison to find the min each time We
 * can optimize it by using minHeap to find the mein This will greatly reduced
 * it to O(nlgk)
 * */

struct compartor {
  bool operator()(const std::vector<int> &a, const std::vector<int> &b) {
    return a[0] > b[0];
  }
};
class Solution {
public:
  std::vector<int> smallestRange(std::vector<std::vector<int>> &nums) {

    int n_ptr = nums.size();
    // minHeap storing the val, index of the list, index of the val of the list
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>,
                        compartor>
        minHeap;
    // Initialize the heap with the first value first
    int left{}, right{};
    left = right = nums[0][0];

    for (int i = 0; i < n_ptr; i++) {
      left = std::min(left, nums[i][0]);
      right = std::max(right, nums[i][0]);
      minHeap.push({nums[i][0], i, 0});
    }

    std::vector<int> ans{left, right};

    while (true) {
      auto info = minHeap.top();
      int val{info[0]}, index_list{info[1]}, index_val{info[2]};
      minHeap.pop();

      index_val++;
      if (index_val == nums[index_list].size())
        break;

      int next_val = nums[index_list][index_val];
      minHeap.push({next_val, index_list, index_val});

      right = std::max(right, next_val);
      left = minHeap.top()[0];

      if (ans[1] - ans[0] > right - left)
        ans = {left, right};
    }
    return std::move(ans);
  }
};
