#include <string>

/*
 * Given a binary string where 1 and 0 represents black and white balls
 * respectively. In each step, choose 2 adjacent balls and swap them Goal:
 * Return the minimum number of steps to group all the black balls to the right
 * and white balls to the left
 *
 * Intuitoin: Move the black ball to the right and white ball to the left
 * CONSTRAINT: Can only swap 2 ADJACENT BALLS
 * Using 2 pointer, 1 pointer is pointing to the beginning of white group and
 * another pointer will iterate through the array to find white ball. When it
 * find the white ball it will swap with the pointer point to the entry of white
 * group. Time Complexity: O(n) Space Complexity: O(1)
 * */
class Solution {
public:
  long long minimumSteps(std::string s) {
    auto len{s.length()};

    int whiteBall_ptr = 0, curr_ptr = 0;
    long long stepTaken{};

    while (curr_ptr < len) {
      // if encounter the white ball then swap the white ball into the left part
      // which is the white ball groups
      if (s[curr_ptr] == '0') {
        stepTaken += curr_ptr - whiteBall_ptr;
        // update the entry of whiteBall groups
        whiteBall_ptr++;
      }
      curr_ptr++;
    }
    return std::move(stepTaken);
  }
};
