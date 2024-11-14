#include <algorithm>
#include <cmath>
#include <functional>
#include <vector>

/*
 * Given an array quantities where quantities[i] is the nubmer of products of
 * the ith product type Need to distribute all products to the retail stores
 * following rules:
 *  - A store can only given at most one product type but any amount of it
 *  - After distribution each store will have been given some number of products
 * possibly 0. Let x represent the maximum number of products given to any
 * store. We want x as small as possible, minimize the maximum number of
 * products that are given to any store Goal: Return the minimum possible x
 *  Constraint: Need to distribute all products
 *
 *  Intuition: Since we want to distribute all products to all store & find out
 * the minimum of maximum number of products that are given to any store. We can
 * actually start by testing distributing the maximum number of products from
 * the quantities array. If not enough products then it can be a '0' If is
 * possible we can try a smaller value The time complexity of this will be
 * O(max(Q) * m) Theres a clever way of solving this instead of linearly trying
 * to find the minimum products given to all store. We can actually use binary
 * search this will greatly reduced it to O(QlgQ) To find out how many store it
 * can distributed just simply take the ceiling of number of items / number of
 * item distributed Space complexity: O(1)
 * */
class Solution {
public:
  int minimizedMaximum(int n, std::vector<int> &quantities) {
    if (n == 1)
      return quantities[0];

    std::function<bool(const int &)> canDistribute = [&](const int x) {
      int n_stores{};
      for (const int &quantity : quantities)
        n_stores += std::ceil(quantity / static_cast<float>(x));
      // Since we need to distribute all product in the quantities array
      // So the number of stores can be smaller or equal to n
      return n_stores <= n;
    };

    int ans{};
    // binary search on the possible range
    int left{1}, right{*std::max_element(quantities.begin(), quantities.end())};

    while (left <= right) {
      int middle{left + (right - left) / 2};

      if (canDistribute(middle)) {
        ans = middle;
        right = middle - 1;
      } else
        left = middle + 1;
    }
    return std::move(ans);
  }
};
