#include <string>
#include <strings.h>
#include <vector>

/*
 * Goal: Design an algorithm to encode a list of strings to a single string.
 * Encoded string is then decoded back to the original list of strings.
 * Constraints: strs[i] contians only UTF-8 characters
 *
 * Intuition:
 * We need to encode the list of string into 1 string. How can we do it to indicate which letter ends at where at the
 * entire string? We can track the length of each string and encoded it into it, but there is one problem strs[i]
 * contians all UTF-8 characters means that even number and special character as well. So maybe we can do is len then +
 * '#' as a sign of starting character after the '#'
 * Encoded format: len#strlen#str
 * Decoded format: extract the len, then we know how many character for each string after the #.
 *
 * */
class Solution
{
  public:
    std::string encode(std::vector<std::string> &strs)
    {
        std::string encode_str;

        for (int index{}; index < strs.size(); index++)
        {
            int len(strs[index].length());

            encode_str += std::to_string(len) + "#" + strs[index];
        }
        return encode_str;
    }

    std::vector<std::string> decode(std::string s)
    {
        std::vector<std::string> decode_str;

        for (int index{}; index < s.length(); index++)
        {
            int end_index{index};

            // extract the len
            while (s[end_index] != '#')
                end_index++;

            int len(std::stoi(s.substr(index, end_index - index)));

            index = end_index + 1;
            end_index += len;

            decode_str.emplace_back(s.substr(index, end_index - index + 1));
            index = end_index;
        }
        return decode_str;
    }
};
