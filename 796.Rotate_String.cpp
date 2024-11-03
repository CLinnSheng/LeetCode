#include <cstddef>
#include <deque>
#include <string>

/*
 * Gaol: Check whether s can turn into goal by keep rotating the string (moving
 * character to the left)
 *
 * Intuition: Check whether are they 2 in the same length
 * And then store the 2 string in a deque data structure respectively.
 * And then keep rotate the first string n time which is the length of the goal
 * string. If within the n times, they are not equal then means they s couldn't
 * rotate into goal
 *
 * Tiem Complexity: O(n)
 * Space Complexity: O(n)
 *
 * */
class Solution {
public:
  bool rotateString(std::string s, std::string goal) {
    std::size_t len_s{s.length()};
    std::size_t len_goal{goal.length()};

    if (len_s != len_goal)
      return false;
    if (len_s == len_goal && len_goal == 0)
      return true;

    std::deque<char> d1(s.begin(), s.end());
    std::deque<char> d2(goal.begin(), goal.end());

    for (int i{}; i < len_s; i++)
      if (d1 == d2)
        return true;
      else {
        d1.emplace_back(d1.front());
        d1.pop_front();
      }

    return false;
  }
};
