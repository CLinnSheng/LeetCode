#include <numeric>
#include <vector>

/*
 *  Circular Route.
 *  Car with unlimited gas tanks and it costs costs[i] of gas to travel from ith station to the next i + 1 station.
 *  Begin with an empty tank
 *
 *  Goal: Return the starting gas station's index if can travel around the circuit once in clockwise direction otherwise -1
 *
 *  Intuition:
 *  1. Brute force approach will just stimulate the process and try every single possible starting point and single move O(n^2)
 *  2. Actually we can think of a greedy way as we trying to start a postion with the most gas and also every time we take the steps that cost
 *  the least gas
 *  The Base Case will simply be total gas must exceed the total cost as we need to travel around the circle once
 *  Time Complexity: O(n)
 * */
class Solution {
public:
    int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost)
    {
        // int n(gas.size());
        // // Brute Force
        // for (int i{}; i < n; i++)
        // {
        //     int tank = gas[i] - cost[i];
        //     if (tank < 0)
        //     {
        //         continue;
        //     }
        //
        //     int nextDestination = (i + 1) % n;
        //     // Keep looping until finish a circle
        //     while (i != nextDestination)
        //     {
        //         tank += (gas[nextDestination] - cost[nextDestination]);
        //         nextDestination += (nextDestination + 1) % n;
        //     }
        //
        //     if (i == nextDestination)
        //     {
        //         return i;
        //     }
        // }
        //
        // return -1;
        int ttlGas = std::accumulate(gas.begin(), gas.end(), 0);
        int ttlCost = std::accumulate(cost.begin(), cost.end(), 0);

        if (ttlGas < ttlCost)
        {
            return -1;
        }

        // Since total_net > 0
        // total_net = partA_net + partB_net where partB_net is > 0.
        // total_net - partB_net = partA_net since total_net is greater than partB_net therefor partA_net is greater than 0
        // partB_net is where the starting gas station to the last gas station --> Greedy Verified
        int currTank{};
        int startingPos{};
        for (int i{}; i < gas.size(); i++)
        {
            currTank += gas[i] - cost[i];

            // If cannot make it to ith, then startingPost is invalid
            if (currTank < 0)
            {
                currTank = 0;
                startingPos = i + 1;
            }
        }
        return startingPos; // Guarantee to be able to start since got net_gas
    }
};
