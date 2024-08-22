#include <bits/stdc++.h>
using namespace std;

/*
Complement of an integer is just by flipping 0 -> 1 & 1 -> 0
Count the number of bits for num and then XOR it with mask which contains all 1111
eg : 5(101) -> 101 XOR 111 => 2(010)
*/
class Solution {
    
    public:
        int findComplement(int num) {
            
            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);
            
            if (num == 0)   return 1;
            int temp = num;
            int n_bits = 0;
            
            while (num) {
                num >>= 1;
                n_bits++;
            }
            
            return temp ^ (static_cast<int>(pow(2, n_bits) - 1));
        }
};