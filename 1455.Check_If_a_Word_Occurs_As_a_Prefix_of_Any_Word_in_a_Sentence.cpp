#include <sstream>
#include <string>

/*
 * Given a sentence and a searchword
 * Goal: Return the index of the prefix of searchWord from the sentence else -1
 *
 * Intuition: Use 2 pointer
 * 1 pointer for the sentence and another pointer for the searchWord
 * Check every single word in the sentence and then compare it
 *
 * Time Complexity: O(n + m*k)
 * O(N) is because of the builtin function that split the word with delimiter '
 * ' m is the number of word in the sentence and k is the maximum lnegth of the
 * word
 * */
class Solution {
public:
  int isPrefixOfWord(std::string sentence, std::string searchWord) {
    std::stringstream sentence_(sentence);
    std::string currentWord;

    int pos{1};

    while (sentence_ >> currentWord) {
      if (currentWord.length() >= searchWord.length() &&
          currentWord.compare(0, searchWord.length(), searchWord) == 0)
        return pos;

      pos++;
    }
    return -1;
  }
};
