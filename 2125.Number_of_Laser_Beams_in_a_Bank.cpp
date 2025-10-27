#include <string>
#include <string_view>
#include <vector>
/*
 * bank[i] represent the ith row consists of 0 and 1.
 * '0' means the cell is empty while '1' means the cell has a security device.
 * One laser beam between any 2security device if both conditions are met:
 * 1. 2 device are located on 2 different rows.
 * 2. Each row i where r1 < i < r2 there are no security device on the ith row.
 *
 * Goal: Return the total nubmer of laser beams in the bank
 *
 * Intuition:
 * Laser beams can only be formed with the previous row. So we need to keep track of the information of the previous row
 * So just simply enumerate it
 * */
class Solution
{
  private:
    bool checkRow(const std::string_view &str)
    {
        for (const auto &c : str)
        {
            if (c == '1')
            {
                return true;
            }
        }
        return false;
    }

    int numberOfDevice(const std::string_view &str)
    {
        int cnt{};
        for (const auto &c : str)
        {
            if (c == '1')
            {
                ++cnt;
            }
        }
        return cnt;
    }

  public:
    int numberOfBeans(std::vector<std::string> &bank)
    {
        // Edge Case
        if (bank.size() == 1)
        {
            return 0;
        }

        int answer{};
        std::string prevRow{bank[0]};

        for (int i{1}; i < bank.size(); ++i)
        {
            if (!checkRow(bank[i]))
            {
                continue;
            }
            answer += numberOfDevice(prevRow) * numberOfDevice(bank[i]);
            prevRow = bank[i];
        }

        return answer;
    }
};
