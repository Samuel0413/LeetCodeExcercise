/*
Given a linked list, swap every two adjacent nodes and return its head.
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
    // different way with python method, use every two nodes, only change value
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode *first=head, *second = head->next,*temp = head->next->next;
        second->next = first;
        first->next = swapPairs(temp);
        return second;
    }
    /*ListNode* swapPairs(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }
        ListNode dummy  = ListNode(0, head);
        ListNode* prev = &dummy;
        ListNode* cur = head;
        while (cur && cur->next) {
            ListNode* next = cur->next;
            ListNode* nextPair = next->next;
            next->next = cur;
            cur->next = nextPair;
            
            prev->next = next;
            prev = cur;
            cur = nextPair;
        }
        return dummy.next;
    }*/
};

/*
Example 1:
Input: head = [1,2,3,4]
Output: [2,1,4,3]

Example 2:
Input: head = []
Output: []

Example 3:
Input: head = [1]
Output: [1]

Time: O(N)
*/
