/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
#include <vector>
#include <iostream>
#include <ios>

/*
Given: A matrix of dimension m * n & a linked list of integers
Goal: Generate a m * n matrix that contain intgers in the linked list presented in spiral order(clock wise), starting from top-left.
Empty space is filled with -1

Intuition:
1. Initialize a 2d vector with value of -1
2. So we traverse the 2d matrix from the top left and keep checking whether is it within the boundary for every single move
3. If out of boundary we change direction (left -> right -> down -> up)

Time Complexity: O(m * n) --> iterate thorugh the 2d array
Space Complexity: O(m * n) --> Storage for the 2d matrix
*/
class Solution 
{
public:
    const std::vector<std::pair<int, int>> directions{{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    std::vector<std::vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);
        std::cout.tie(nullptr);

        std::vector<std::vector<int>> ans_matrix(m, std::vector<int>(n, -1));
        if (head == nullptr) return ans_matrix;

        int y = 0, x = 0;
        int direction = 0;

        while (head)
        {
            ans_matrix[y][x] = head->val;
            auto [_y, _x] = directions[direction];
            int newY = y + _y;
            int newX = x + _x;

            // Check boundary
            if (newX < 0 || newY < 0 || newX >= n || newY >= m || ans_matrix[newY][newX] != -1)
                direction = (direction + 1) % 4;

            
            x += directions[direction].second;
            y += directions[direction].first;
            head = head->next;
            
        }
        return ans_matrix;
    }
};