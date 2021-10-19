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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *low = head;
        ListNode *up = head;
        while (true) {
            up = low;
            for (int i = 0; i < n; i++) {
                up = up->next;
            }
            if (up == nullptr) {
                return low->next;
            }
            if (up->next == nullptr) {
                break;
            }
            low = low->next;
        }
        low->next  = low->next->next;
        return head;
    }
};

/*
Example 1:
Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]

Example 2:
Input: head = [1], n = 1
Output: []

Example 3:
Input: head = [1,2], n = 1
Output: [1]

O(L)
*/
