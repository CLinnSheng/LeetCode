#include <cstddef>
#include <string>
#include <vector>

/*
 * Given an integer num, swap 2 digit at most once to get teh maximum valued
 * number
 *
 * Intuition:
 * 1. Naive approach
 *  -  have a double loop checking is theere any number on the right is bigger
 * than itsels if got then swap it, we stgart from index 0
 *  - O(n2)
 *
 * 2. Optimized from naive approach. Key things we noticed from naive approach
 * we only swap from the number from the right So we can make use of an array
 * data structure to store the maximum element from the right for every index.
 * This will greatly reduce the time complexity to O(n)
 * Space complexity: O(n)
 */
class Solution {
public:
  int maximumSwap(int num) {
    std::string num_string = std::to_string(num);
    std::size_t const len = (std::size_t)num_string.length();
    std::vector<std::pair<char, int>> maxRight(len, {'0', 0});

    for (int i = len - 1; i >= 0; i--) {
      if (i == (int)len - 1)
        maxRight[i] = std::make_pair(num_string[i], i);
      else
        maxRight[i] =
            num_string[i] > maxRight[i + 1].first
                ? std::make_pair(num_string[i], i)
                : std::make_pair(maxRight[i + 1].first, maxRight[i + 1].second);
    }

    for (int i = 0; i < len; i++)
      if (num_string[i] < maxRight[i].first) {
        char temp = num_string[i];
        num_string[i] = maxRight[i].first;
        num_string[maxRight[i].second] = temp;
        break;
      }

    return std::stoi(num_string);
  }
};
