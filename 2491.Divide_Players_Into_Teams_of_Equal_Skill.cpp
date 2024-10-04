/*
Goal: Divide the players into n/2 teams of size 2 such that the total skill of
each team is equal. And then return the chemistry of all the team where
chemistry of a team is the product of the skills of the players on the team.
Intuition: The easiest and most optimal way is addding the smallest and largest
element to form the team. Sort it and then compare with the prev team score Time
Complexity: O(nlgn)
*/
#include <algorithm>
#include <ios>
#include <iostream>
#include <vector>

class Solution {
public:
  long long dividePlayers(std::vector<int> &skill) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n = skill.size();
    if (n == 0)
      return 0;

    std::sort(skill.begin(), skill.end());

    long long ans = 0;
    int prevSum = 0;
    int left = 0, right = n - 1;

    while (left < right) {
      int sum = skill[left] + skill[right];
      if (prevSum != sum && prevSum != 0)
        return -1;

      prevSum = sum;
      ans += skill[left++] * skill[right--];
    }

    return ans;
  }
};
