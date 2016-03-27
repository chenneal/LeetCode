/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        /* p1 and p2 are the current poiters to l1 and l2 */
        ListNode * p1, * p2;
        ListNode * p;
        ListNode * head = new ListNode(0);
        p = head;
        int sum;
        int carry = 0;
        int remainder = 0;
        p1 = l1;
        p2 = l2;
        while (p1 || p2 || carry) {
            sum = (p1 ? p1->val : 0) + (p2 ? p2->val : 0) + carry;
            remainder = sum % 10;
            carry = sum >= 10 ? 1 : 0;
            
            p->next = new ListNode(remainder);
            p1 = p1 ? p1->next : NULL;
            p2 = p2 ? p2->next : NULL;
            p = p->next;
        }
        return head->next;
    }
};
