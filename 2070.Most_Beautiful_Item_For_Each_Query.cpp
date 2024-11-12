#include <algorithm>
#include <map>
#include <vector>
/*
 * Given a 2d array, items where items[i] = [price_i, beauty_i]
 * & another 1d array where each queries[i], need to determine the maximum
 * beauty of an item whose price is less than or equal to queries[i] if no such
 * item exists then 0
 *
 * Goal: Return an array answer of the same length as queries where answer[j] is
 * the answer to the jth query.
 *
 * Intuition:
 * We can use naive approach by iterating through the queries and then iterate
 * through the items to find the maximum beauty it can hold with price less than
 * or equal to queries[i] Time Complexity: O(m * n) Actually we can see
 * overlapping subproblem. we can actually skip iterate through the price which
 * is lower than the queries[i - 1] because since queries[i] can hold until a
 * certain weight This can greatly reduce the time complexity to O(Nlgn + mlgm)
 * Space Complexity: O(n)
 * */
class Solution {
public:
  std::vector<int> maximumBeauty(std::vector<std::vector<int>> &items,
                                 std::vector<int> &queries) {
    std::vector<int> ans(queries.size());

    // use a 2d array because we want to store the index for the ith_query
    // cannot use map because faces collision
    std::vector<std::vector<int>> mapIndex(queries.size(), std::vector<int>(2));

    for (int i{}; i < queries.size(); i++) {
      mapIndex[i][0] = queries[i];
      mapIndex[i][1] = i;
    }

    // sort the items
    std::sort(items.begin(), items.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
              });
    std::sort(mapIndex.begin(), mapIndex.end(),
              [](const std::vector<int> &a, const std::vector<int> &b) {
                return a[0] < b[0];
              });

    int j{};
    int prevMax{};

    for (const auto &map : mapIndex) {
      int query{map[0]};
      int index{map[1]};

      while (j < items.size() && items[j][0] <= query) {
        prevMax = std::max(prevMax, items[j][1]);
        j++;
      }

      ans[index] = prevMax;
    }

    return std::move(ans);
  }
};
