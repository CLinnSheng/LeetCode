#include <string>

/*
 * Goal: Return true if it is possible to make s2 a subsequence of str1 by
 * performing the operation at most once and false otherwise
 *
 * Operation: Select a set of indicies in str1, and for each index i in the set,
 * increment str1[i] to the next character cyclically. THat is 'a' becomes b &
 * 'z' becomes 'a'
 *
 * Constraint: Need to handle character 'z' because if we add 1 to 'z' it will
 * go out of bound for characters in ascii
 *
 * Time Complexity: O(n) where n is the length of str1
 * Space Complexity: O(1)
 * */
class Solution {
public:
  bool canMakeSubsequence(std::string str1, std::string str2) {
    int len1(str1.length()), len2(str2.length());
    int ptr1{}, ptr2{};

    while (ptr1 < len1 && ptr2 < len2) {
      if (str1[ptr1] == str2[ptr2] || str1[ptr1] + 1 == str2[ptr2] ||
          str1[ptr1] - 25 == str2[ptr2])
        ptr2++;
      ptr1++;
    }

    return ptr2 == len2 ? true : false;
  }
};
