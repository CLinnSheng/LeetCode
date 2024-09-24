#include <ios>
#include <iostream>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>
/*
Common prefix of 2 integers a & b is an integer c, such that c is a prefix of
both and b. Intuition: We have to a double loop no matter what  because we need
to each word in arr1 to each word in arr2 this will take O(m*n) While we need to
do inner word comparsion also this take O(lgX) X - is the longest values in the
arr1 Total time complexity: O(mn*lgX)

To reduce the time complexity, the only we can do is to optimize the part of
searching inner word what we can do is use a data strcuture to store all the
possibilites prefix and then check through the val in the array, check from the
longest possible prefix because we want to find the longest 1 if the longest 1
doesnt exists then follow the shorter 1
Time Complexity: O(mlgx + nlgx)
Space Complexity: O(mlgX)
*/
class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    if (arr1.size() > arr2.size())
      std::swap(arr1, arr2);

    std::unordered_set<int> possible_prefixes;

    for (const auto &num : arr1) {
      auto temp = num;

      while (temp && !possible_prefixes.count(temp)) {
        possible_prefixes.insert(temp);
        temp /= 10;
      }
    }

    int max_len = 0;
    for (const auto &num : arr2) {
      auto temp = num;

      while (!possible_prefixes.count(temp) && temp)
        temp /= 10;
      if (temp)
        max_len =
            std::max(max_len, static_cast<int>(std::to_string(temp).length()));
    }
    return max_len;
  }
};
