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
        std::string encode_str{};

        for (const auto &str : strs)
        {
            int len(str.length());
            encode_str += std::to_string(len) + "#" + str;
        }

        return encode_str;
    }

    std::vector<std::string> decode(std::string s)
    {
        // Decode the string by first extract the length which is until '#'
        // Then extract the string with the length
        std::vector<std::string> decode_strs;
        int ptr{};

        while (ptr < s.length())
        {
            // len
            int len_ptr = s.find("#", ptr);
            int len = std::stoi(s.substr(ptr, len_ptr - ptr));

            decode_strs.emplace_back(s.substr(len_ptr + 1, len));
            ptr = len_ptr + 1 + len;
        }

        return decode_strs;
    }
};
