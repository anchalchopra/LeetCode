/* You are given two non-empty linked lists representing two non-negative integers.
The digits are stored in reverse order, and each of their nodes contains a single digit.
Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:    
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode * res = new ListNode(0);
        int sum = 0, carry = 0;
        ListNode *temp = res;
        
        while(l1 != NULL || l2 != NULL)
        {
            sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum/10;
            
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
            
            if(l1)
                l1 = l1->next;
            
            if(l2)
                l2 = l2->next;
        
            if(carry)
            {
                temp->next = new ListNode(carry);
            }
        }
        return res->next;
    }
};
