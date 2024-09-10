#include <vector>
#include <iostream>
#include <ios>

/*
Given an array contanining n + 1 integers where each integer is in the range [1, n]
There is only one repeated number in nums, return the repeated number
Constraint: Solve it without modifying the array and use only constant extra space O(1)

Intuition: Floyd's Cycle Detection Algorithm (Because existence of a cycle due to the duplicate number)
Treat the array as a linked list
If there are repeated number then theres definitely a cycle in the linked list
n+1 number but only [1, n] --> Therefore at least 2 number share the same value

Moving one pointer(tort) one step at a time and another pointer(rabbit) two steps at a time. If there is a cycle, they will meet at some point
THen, we reset the tort to the beginning of the array and move pointers one step at a tinme until theey meet again.
The point where they meet is at the entrance of the cycle which is the repeated number

Time Complexity: O(n)
Space Complexity: O(1)
*/

class Solution 
{
public:
    int findDuplicate(std::vector<int>& nums) 
    {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);
    
        // Represent the element in a linked list
        int tortoise = nums[0];
        int rabbit = nums[0];
        
        while (true)
        {
            tortoise = nums[tortoise]; // Move by 1
            rabbit = nums[nums[rabbit]]; // Move by 2
            
            // Find the point where they meet
            if (tortoise == rabbit) break;
        }
        
        // Find the entrace of cycle linked list
        // Set tortoise back to start and then move both at the same speed will definitely meet at the entrance
        tortoise = nums[0];
        while (tortoise != rabbit)
        {
            tortoise = nums[tortoise];
            rabbit = nums[rabbit];
        }
        
        return tortoise;
    }
};