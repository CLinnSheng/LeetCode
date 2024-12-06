#include <cstddef>
#include <string>

/*
 * Goal: Return true if it is possible to obtain the string 'target' by moving
 * pieces of string 'start' any number of times else false
 *
 * Rules on moving the pieces:
 * 'L' & 'R' represent pieces, where a piece 'L' can move to the left only if
 * there is a blank space directly to its left 'R' can move to the right only if
 * there is a blnak space
 * '_' represents a blank space that can be occupied by 'L' or 'R'
 *
 * Intuition:
 * 1. Brute force
 * First thought is brute force to produce all kind of combination of string and
 * then compare to the target Try to move every single pieces of 'L' & 'R' until
 * the furthest possible position Time Complexity: O(n^2)
 *
 * 2. We can further optimiz this, we observe that every single peices of start
 * is correspond to a pieces in the target string the order does matters. for
 * eg: the first pieces in start must be the same as the first pieces in target
 * in order for the string start to become the string target So what we can do
 * is move the pointer to the characters and skip the blank spaces and then
 * check it Time Complexity: O(n)
 * */
class Solution {
public:
  bool canChange(std::string start, std::string target) {
    if (start == target)
      return true;

    int start_ptr{}, target_ptr{};
    std::size_t len{start.length()};

    // use or instead of and to handle cases where they have inequal number of
    // pieces
    while (start_ptr < len || target_ptr < len) {

      // move the ptr in start to skip '_'
      while (start_ptr < len && start[start_ptr] == '_')
        start_ptr++;

      // same goes to target
      while (target_ptr < len && target[target_ptr] == '_')
        target_ptr++;

      // then check whether the one or both of ptr is out of bound or not
      // if one of the ptr is ahead of one another that means they dont have the
      // same number of pieces
      if (start_ptr == len || target_ptr == len)
        return start_ptr == target_ptr;

      // condition for the start not possible to change to target
      if (start[start_ptr] != target[target_ptr] ||
          (start[start_ptr] == 'L' && start_ptr < target_ptr) ||
          (start[start_ptr] == 'R' && start_ptr > target_ptr))
        return false;

      start_ptr++;
      target_ptr++;
    }
    return true;
  }
};
