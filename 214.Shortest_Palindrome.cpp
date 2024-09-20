#include <ios>
#include <iostream>
#include <string>

/*
Given a string.
Goal: Convert the s to a palindrom by adding characters in front of it
Constraint: Can only add characters infront of it & return the shortest
palindrome

Intuition: Having two pointer, one point at the front & another 1 point to the
right Check the maximum length of palindrome we can find and then we just append
to non palindrome text to the front Time Complexity; O(n*n) becasue we checking
every single index and then check whether is it a palindrome

Another way of doing is that instead of keep checking every index is a
palindrome or which is very exhaustive REMEBEMBER A string is a palindrome if it
equals to its reverse So we can find the longest palindrome in the string by
comparing to its reverse, use hash map to store the sequence. eg: a a b c b a d
-> 1 1 2 3 2 1 4 d a b c b a a -> 4 1 2 3 2 1 1 from here we can tell taht the
longest palindrom is a a we will using base 29 here to prevent collision even
though we only have 26 characters and then find the ending index of the longest
palindrome and then reverse the rest and append it in the front

Time Complexity: O(n)
Space Complexity: O(n)

Basically in simple word, the intuition behind is to find the longst palindrome
first and then append the rest at the front by reversing its the way to find the
longest palindrome is to by comparing with its reverse order, at here we using
suffix and prefix is much more easier and not so expensive
*/
class Solution {
public:
  std::string shortestPalindrome(std::string s) {

    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int prefix = 0, suffix = 0;
    int base = 29, powerVal = 1, mod = 1e9 + 7;
    int last_index = -1;

    for (int i = 0; i < s.size(); i++) {

      auto temp = s[i];

      prefix = prefix * base +
               (temp - 'a' + 1); // here we +1 because we start from 1 for a
                                 // beacuse if we use 0 we will be confuse
      suffix = suffix + (temp - 'a' + 1) * powerVal;

      powerVal = (powerVal * base) % mod;

      if (prefix == suffix)
        last_index = i;
    }
    std::string append_string = s.substr(last_index + 1);
    std::string reverse_append_string(append_string.rbegin(),
                                      append_string.rend());

    return reverse_append_string + s;
  }
};
