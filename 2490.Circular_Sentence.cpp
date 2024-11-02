#include <string>
#include <vector>

/*
Given sentence consists a sequence of words seperated by ' '
Find whether is it circular or not by comparing the last character of first word
to the first character of the next word and the first character of the first
word will by comparing to the last character of the last word

Intuition: Find out the index where the spaces are and then by comparing i - 1 &
i + 1 and also dont forget to compare the first idnex and the last index Time
Complexity: O(n) Space Complexity: O(1)
*/
class Solution {
public:
  bool isCircularSentence(std::string sentence) {
    std::vector<int> index_space;
    int len = sentence.length();

    for (int i = 0; i < len; i++)
      if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
        return false;

    // handling 1 word only
    return sentence[0] != sentence[len - 1] ? false : true;
  }
};
