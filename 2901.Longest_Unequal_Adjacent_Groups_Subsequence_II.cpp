#include <string>
#include <vector>

/*
 * Both groups & words have the same length n.
 * Hamming Distance between 2 strings at which the corresponding characters are different but both of them must be
 * sharing the same length.
 *
 * Select the longest subsequence such that the subsequence following these rules:
 * i. Adjacent indices in the subsequence, their corresponding groups must be different
 * ii. Hamming distance must be 1
 *
 * NOTE:
 * i. string in words may be unequal in length.
 * ii. groups arent binary array can have any arbitary value.
 *
 * Intuition:
 *
 * */
class Solution
{
  public:
    std::vector<std::string> getWordsInLongestSubsequence(std::vector<std::string> &words, std::vector<int> &groups)
    {
        std::vector<std::string> ans;

        return ans;
    }
};
