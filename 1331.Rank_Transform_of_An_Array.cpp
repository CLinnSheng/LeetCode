#include <algorithm>
#include <ios>
#include <iostream>
#include <unordered_map>
#include <vector>
/*
 * Goal: Replace each element in the array with its rank
 * The rank represent how large the element is
 *
 * Intuition: Have another array and then sorted it. then based on this sorted
 * array repalce the element with its rank
 * Time Complexity: O(nlgn + n) ---> O(nlgn) (nlgn is sorting while n is just
 * iterate through the array) Space Complexity: O(n)
 * */
class Solution {
public:
  std::vector<int> arrayRankTransform(std::vector<int> &arr) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> cp(arr.begin(), arr.end());
    std::sort(cp.begin(), cp.end());

    int rank = 1;
    std::unordered_map<int, int> mapping;
    for (int i = 0; i < arr.size(); i++) {
      if (i > 0 && cp[i] > cp[i - 1])
        rank++;
      mapping[cp[i]] = rank;
    }

    for (auto &num : arr)
      num = mapping[num];

    return std::move(arr);
  }
};
