#include <iostream>
#include <ios>

/*
Goal: Return the minimum number of bits flip to turn start to goal

Intuition: Need to determine which bits need to flip
We can use XOR operation as different bits will produce a 1 this will indicate that bit need to flip
And then & with 000001 to check how many 1 bit is there

Time Complexity: 
Since the number get divide by half everytime we shift 1 bit to the right, N / 2^k = 1 where k is the number if time we divide
and therefore ended up k = lgN --> Time Complexity: O(lgN)
Space Complexity: O(1)
*/
class Solution 
{
public:
    int minBitFlips(int start, int goal) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        // Clear
        if (start == goal) return 0;
        
        int number_of_flip_bitform = start ^ goal;
        int checking = 1;
        int cnt = 0;
        
        while (number_of_flip_bitform)
        {
            if ((number_of_flip_bitform & checking) == 1) cnt++;
            
            number_of_flip_bitform >>= 1;
        }
        
        return cnt;
    }
};