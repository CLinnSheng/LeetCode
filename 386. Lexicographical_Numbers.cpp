#include <ios>
#include <iostream>
#include <vector>

/*
 * Given an integer n, return all the numbers in the range [1, n] sorted in
 * lexigoraphical Constraint: Time complexity must be O(n) & Space complexity of
 * O(1) lexigoraphical order: Number is sorted according to digit eg: 1 11 3 34
 * 4 1 11 3 34 4 Intuition: Since O(n) we cannot use any sorting algorithm & the
 * only option Since is in lexigoraphical order, we iamgine a tree fork out from
 * 0 to 9 and its child also fork out from 0 to 9, so we can skip the proecss of
 * sorting. If the current number is greater than n we just skip it
 * */
class Solution {
public:
  std::vector<int> lexicalOrder(int n) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<int> ans;
    int curr_num = 1;

    for (int i = 0; i < n; i++) {

      ans.emplace_back(curr_num);

      if (curr_num * 10 <= n)
        curr_num *= 10;
      else {
        // handling case where 19 or 29 want go to the next digit
        while (curr_num % 10 == 9 || curr_num >= n)
          curr_num /= 10;
        curr_num += 1;
      }
    }

    return ans;
  }
};
