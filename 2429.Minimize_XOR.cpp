/*
 * Goal: Return an integer that fulfill the testcase such that it is uniquely determined.
 * TestCase:
 * i. x has the same number of set bits as nums2
 * ii. Value x XOR num1 is minimal
 *
 * Intuition:
 * The best x will be the same value as num1 because the result will be 0.
 * So we will work on the value as num1 first, then only change the x if doesnt have enough set bit or too much.
 * Always start from LSB because for setting bit up start from the LSB can produce result with lower value
 * & from unsetbit will also produce result with lower value
 *
 * Time Complexity: O(lgn) shifting bits because we keep dividing by 2
 * Space Complexity: O(1)
 * */
class Solution
{
  private:
    // O(lgn)
    int checkNumberOfBits(int target)
    {
        int count{};
        while (target)
        {
            if (target & 1)
                count++;
            target >>= 1;
        }
        return count;
    }

    bool isSet(const int &x, const int &bit)
    {
        return x & (1 << bit);
    }

  public:
    int minimizeXor(int num1, int num2)
    {
        // int is 4bytes -> 32 bits
        int result{num1};

        int targetBitCount{checkNumberOfBits(num2)};
        int currBitCount{checkNumberOfBits(result)};

        if (targetBitCount == currBitCount)
            return result;

        // we set & unset from the LSB becuase on the other way will not produce the minimum answer
        int currentBit{};
        // if less than the targeted number of bit

        // At max O(32) -> O(1)
        //  same goes for the 1 below
        while (currBitCount < targetBitCount)
        {
            // check whether the current bit is set or not
            if (!isSet(result, currentBit))
            {
                // if not set then we set it
                result |= (1 << currentBit);
                currBitCount++;
            }
            currentBit++;
        }

        // if more than the targeted nmber of bit
        while (currBitCount > targetBitCount)
        {
            // if the current bit is set then we unset it
            if (isSet(result, currentBit))
            {
                result &= ~(1 << currentBit);
                currBitCount--;
            }
            currentBit++;
        }
        return result;
    }
};
