#include <string>
#include <unordered_set>
/*
 * Alice & Bob will take turns playing but alice will start first:
 * Alice turn: remove any non-empty substring from s that contains an odd number of vowels
 * Bob turn: remove any non-empty substring from s that contains an even number of vowels
 *
 * First player who cannot make move on their turn loss the game.
 *
 * Goal: Return true if alice win the games
 *
 * Intuition:
 * Alice take the first turn
 * only lower case letter
 * Few case
 * if s contain odd number of vowel then alice win
 * if s contain 0 number of vowel then alice loss
 * if s contain even number of vowel alice will win also because
 * first turn is alice turn then s will become odd after that so no matter how long bob take (even) the string s will
 * also contain odd vowel
 * */
class Solution
{
  private:
    const std::unordered_set<char> VOWELS{'a', 'e', 'i', 'o', 'u'};

  public:
    bool doesAliceWin(std::string s)
    {
        int cnt{};

        for (const auto ch : s)
            if (VOWELS.count(ch))
                cnt++;
        return cnt % 2 ? true : (cnt == 0) ? false : true;
    }
};
