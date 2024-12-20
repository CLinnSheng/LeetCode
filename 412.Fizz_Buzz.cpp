#include <string>
#include <string_view>
#include <vector>

/*
 * Given an integer n return a string array answer (1-indexed) where:
 * answer[i] = "FizzBuzz" if i is divisible by 3 & 5
 * answer[i] = "Fizz" if i is divisible by 3
 * answer[i] = "Buzz" if i is divisible by 5
 * answer[i] = i if none of the above conditions are true
 * */
class Solution
{
  public:
    static constexpr std::string_view FIZZ{"Fizz"};
    static constexpr std::string_view FIZZBUZZ{"FizzBuzz"};
    static constexpr std::string_view BUZZ{"Buzz"};
    std::vector<std::string> fizzBuzz(int n)
    {
        std::vector<std::string> answer(n);
        for (int i{1}; i <= n; i++)
        {
            if (i % 15 == 0)
                answer[i - 1] = FIZZBUZZ;
            else if (i % 3 == 0)
                answer[i - 1] = FIZZ;
            else if (i % 5 == 0)
                answer[i - 1] = BUZZ;
            else
                answer[i - 1] = std::to_string(i);
        }
        return answer;
    }
};
