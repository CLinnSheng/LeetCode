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
/*
 * Goal: Return the head of the modified linked list after removing all nodes from the linked list that have a value
 * that exists in nums.
 *
 * Intuition:
 * We jut neeed to iterate through the linked list then check whether the current element is inside the nums or not. If
 * yes then remove it and link the linklist
 * While checking the current val we need to iterate through the nums array which takes O(n), we can optimize it by
 * using a set such that it only takes O(1)
 * Time Complexity: O(n)
 *
 * */
#include <unordered_set>
#include <vector>
class Solution
{
  public:
    ListNode *modifiedList(std::vector<int> &nums, ListNode *head)
    {
        if (!head)
        {
            return nullptr;
        }

        if (nums.size() == 0)
        {
            return head;
        }

        std::unordered_set<int> numsSet(nums.begin(), nums.end());
        ListNode *temp = head;
        ListNode *prev = nullptr;

        while (temp)
        {
            if (numsSet.find(temp->val) != numsSet.end())
            {
                // If not the first node
                if (prev)
                {
                    prev->next = temp->next;
                    temp = prev->next;
                }
                else
                {
                    // First node
                    // Need to update head
                    head = head->next;
                    temp = head;
                }
            }
            else
            {
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
    }
};
