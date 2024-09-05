    #include <ios>
    #include <iostream>
    #include <numeric>
    #include <vector>
    
    /*
    Observations of m + n 6 sided dice rolls (1 to 6). n of the observations went missing & only have the observations of m rolls.
    We also have the average value of m + n rolls.
    Given array rolls of  length m where rolls[i] is the value of ith observation.
    Goal: Return an array of length n containing the missing observations such that average of m + n is exactly mean
    
    Intuition: Mean (A+B) = Sum(A, B) / m + n
    Find the total sum of array_n, then check whether is it possible to create an array of size n to get the total sum of array_n
    2 condition: n * 6 > sum_n && sum_n > n
    and then initialize the array with the mean of n
    then find the reamining of n by using sum_array_n % mean
    then add from 0 to mod 
    
    Time Complexity: O(m + n)
    */
    class Solution 
    {
    public:
        std::vector<int> missingRolls(std::vector<int>& rolls, int mean, int n) 
        {
            std::ios_base::sync_with_stdio(false);
            std::cin.tie(nullptr);
            std::cout.tie(nullptr);
            
            int sum_m = std::accumulate(rolls.begin(), rolls.end(), 0);
            
            int ttl_sum = mean * (rolls.size() + n);
            int sum_n = ttl_sum - sum_m;
            
            // check whether does the array size of n able to sum up to sum_n
            if (sum_n > n * 6 or n > sum_n)
                return { };
                
            std::vector<int> possible_roll;
            
            // Easier way is just straight fill up with the biggest number
            int mean_n = sum_n / n;
            int mod = sum_n % n;
            std::vector<int> array_n(n, mean_n);
            
            for (int i = 0; i < mod; i++)
                array_n[i]++;
                
            return array_n;
        }
    };