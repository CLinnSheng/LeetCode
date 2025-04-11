/*
 * x consists of 2 * n digits is symmetric if the sum of the first n equal to the sum of last n.
 * Number with odd number of digits are never symmetric.
 *
 * Intuition:
 * Key Observation is that odd digit number are never symmetric, so we dont have to process thos odd digit number.
 * And also the constraint given that the maximum number is 10^4 --> 10000.
 * Which means we only have to check [10,100) & [1000,10000)
 * for number from 10 to 100, the only possible way of symmetric is when they have the same digit like 11, 22, 33,
 * because after seperate each side only has 1 digit. And then for [1000,10000) we have to manually calculate for every
 * digit. Time Complexity: O(high - low)
 * */
class Solution
{
  public:
    int countSymmetricIntegers(int low, int high)
    {
        int cnt{};

        while (low <= high)
        {
            if (low < 100 && low % 11 == 0)
                cnt++;
            else if (low >= 1000 && low < 10000)
            {
                // Straight away compute is better ot change to string
                // if change to string will be O(n)
                int firstHalf{low / 1000 + (low % 1000) / 100};
                int secondHalf{(low % 100) / 10 + low % 10};

                if (firstHalf == secondHalf)
                    cnt++;
            }
            low++;
        }

        return cnt;
    }
};
