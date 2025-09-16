#include <deque>
#include <vector>

/*
 * Steps:
 * 1. Find any 2 adjacent that are non-coprime
 * 2. If no such numbers, stop the process
 * 3. Otherwise, delete the 2 numbers and replace them with their LCm
 * 4. Repeat as long as you kep finding 2 adjacent non-coprime numbers
 *
 * Goal: Return the final modified array
 * non-coprime if GCD(x, y) > 1
 *
 * Intuition:
 * Just run through the stimulation
 * We need to check whether the new element and last element in the array is non-coprime or not, therefor we need a data
 * structure that holds the information of the elements we included. We can use stack
 * Time Complexity: O(nlgm)
 * */
class Solution
{
  private:
    // O(lgM) where M is the maximum element in the array
    int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

  public:
    std::vector<int> replaceNonCoprimes(std::vector<int> &nums)
    {
        std::deque<int> stack;
        for (int num : nums)
        {
            while (!stack.empty())
            {
                auto top{stack.back()};
                int g{gcd(top, num)};

                // if non-coprime then continue adding element
                if (g == 1)
                    break;

                stack.pop_back();

                // LCM
                long long merged = (long long)top / g * num;
                num = (int)merged;
            }
            stack.emplace_back(num);
        }
        return std::vector<int>(stack.begin(), stack.end());
    }
};
