/*
 * Goal: Return the maximum number you can get by changing at most one digit
 *
 * Intuition:
 * The num only consist of 6 & 9. So we just need to change the first 6 to 9 from the left
 * */
#include <string>
class Solution
{
  public:
    int maximum69Number(int num)
    {
        std::string str{std::to_string(num)};

        for (auto &ch : str)
            if (ch == '6')
            {
                ch = '9';
                break;
            }
        return std::stoi(str);
    }
};
