#include <bits/stdc++.h>
#include <ios>
using namespace std;

/*
Each lemonade costs $5, Customer in a queue and order one at a time
Customer pays either $5, $10 or $20
Goal: Provide the correct change, Constraint: Dont have any change in hand at first
Intuition: We need to keep track of the number of notes for $5 and $10
we can igonre the $20 notes because we didnt need it to make changes as the maximum they can give is $20
We prioritize to return the bigger notes
*/
class Solution{
    public:
        bool lemonadeChange(vector<int> &bills) {

            ios_base :: sync_with_stdio(false);
            cin.tie(nullptr);
            cout.tie(nullptr);

            int n_5 = 0, n_10 = 0;


            for (const auto &bill : bills)
                if (bill == 5)  n_5++;
                else if (bill == 10) {
                    if (n_5 > 0) {
                        n_10++;
                        n_5--;
                    }
                    else    return false;
                }
                else {
                    if (n_5 < 3 && (n_5 < 1 || n_10 < 1))
                        return false;
                    if (n_10)   n_10--;
                    else    n_5 -= 2;

                    n_5--;
                }

            return true;
        }
};
