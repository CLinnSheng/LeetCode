#include <ios>
#include <numeric>
#include <vector>
#include <iostream>

/*
N students in the class numbered from 0 - n - 1. Teacher give each student from student with index 0 to n - 1
Teacher will restart the process, starting with student with index 0.
Given an integer array of chalk indicates the number of chalk required for that question or index in more precise
K is the number of pieces of chalk given
Goal: Return the index of the student that will replace the chalk pieces. In simple terms, find the student that dont have enough chalk

Intuition: By brute force, u will have to scan the array multiple times until it run out
A more clever way is to first we compute the number of chalk required for 1 round. And then we will subtract it with k to find out the particular round that chalk is not enough
After that we only scan through the array to find out the student dont have enough chalk
*/
class Solution
{
public:
    int chalkReplacer(std::vector<int>& chalk, int k)
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
        
        auto ChalkRequired_In_1Round = std::accumulate(chalk.begin(), chalk.end(), static_cast<long long>(0));
        
        // Find the round where is not enough to supply to the entire round
        k %= ChalkRequired_In_1Round;
        
        // If no remainder thats mean it can fully supply to a certain round, so definitely the first student from the next round have to replace it
        if (k == 0) return 0;

        // Now we will scan through the array to find out the student that need to replace the chalk
        for (int i = 0; i < chalk.size(); i++)
        {
            k -= chalk[i];
            if (k < 0)   return i;
        }
        
        return -1;
    }
};