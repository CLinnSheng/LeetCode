#include <string>

/*
 * An integer is good if:
 * - substring of num with length of 3
 * - consits of only one unique digit only
 *
 * Goal: Return the maximum good integer
 *
 * Intuition:
 * Jus simply use a window of 3, slide it all the way
 * */
class Solution
{
  public:
    std::string largestGoodInteger(std::string num)
    {
        std::string answer{};

        for (int i{}; i < num.length() - 2; i++)
            if (num[i] == num[i + 1] && num[i + 1] == num[i + 2])
            {
                answer = (answer.empty()) ? num.substr(i, 3) : ((answer[i] > num[i]) ? answer : num.substr(i, 3));
            }
        return answer;
    }
};
