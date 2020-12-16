/*
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    struct ListNode* ret = malloc(sizeof (struct ListNode));
    ret->val = 0;
    ret->next = NULL;
    struct ListNode* cur = ret;
    struct ListNode* a = l1;
    struct ListNode* b = l2;
    int carry = 0;
    while (a != NULL || b != NULL) {
        int num1 = (a != NULL) ? a->val : 0;
        int num2 = (b != NULL) ? b->val : 0;
        int sum = num1 + num2 + carry;
        carry = sum / 10;
        cur->next = malloc(sizeof (struct ListNode));
        cur = cur->next;
        cur->val = sum % 10;
        cur->next = NULL;
        if (a != NULL) {
            a = a->next;
        }
        if (b != NULL) {
            b = b->next;
        }
    }
    if (carry > 0) {
        cur->next = malloc(sizeof (struct ListNode));
        cur = cur->next;
        cur->val = carry;
        cur->next = NULL;
    }
    return ret->next;
}

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
