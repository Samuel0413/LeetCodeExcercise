/*
You are given two non-empty linked lists representing two 
non-negative integers. The digits are stored in reverse order, and 
each of their nodes contains a single digit. Add the two numbers and 
return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.
*/

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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode();
        ListNode* a = l1;
        ListNode* b = l2;
        ListNode* cur = ret;
        int carry = 0;
        while (a != NULL || b != NULL || carry > 0) {
            int num1 = (a != NULL) ? a->val : 0;
            int num2 = (b != NULL) ? b->val : 0;
            int sum = num1 + num2 + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (a != NULL) { a = a->next; }
            if (b != NULL) { b = b->next; }
        }
        if (carry != 0) {
            cur->next = new ListNode(carry);
        }
        return ret->next;
    }
};

/*
Example1:

Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:

Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:

Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]
*/
