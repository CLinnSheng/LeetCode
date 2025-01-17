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
 * Goal: Return the head of the modified list
 * Modified list do not contain nodes with zero values.
 * For every consecutive 0's, merge the nodes lying in between into a single node value is the sum of all the merged
 * nodes.
 *
 * Intuition:
 * Just iterate through the LL & every time encounter a 0 node just make a new node from the new LL
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    ListNode *mergeNodes(ListNode *head)
    {
        ListNode *temp{head->next};
        int currSum{};
        ListNode *ans = new ListNode();
        ListNode *temp_ans{ans};

        while (temp)
        {
            if (temp->val == 0)
            {
                temp_ans->next = new ListNode(currSum);
                currSum = 0;
                temp_ans = temp_ans->next;
            }

            currSum += temp->val;
            temp = temp->next;
        }
        return ans->next;
    }
};
