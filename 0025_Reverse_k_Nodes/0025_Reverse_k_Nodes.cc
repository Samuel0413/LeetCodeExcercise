/*
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dummy = ListNode(0, head);
        ListNode* prev_group = &dummy;
        
        while (true) {
            ListNode* kth_node = findKth(prev_group, k);
            if (kth_node == nullptr) break;
            // when k = 3
            // cur_node here is the node after one time reverse
            // for example 1->2->3 becomes 3->1->2 after one time
            // reverse, 1 is the cur_node, and 3 is the prev_node
            // after all reverses are done, we want prev_group to
            // points to the first element after reversing, which is
            // the kth node, before doing so, we need to mutate
            // prev_group so that it is the last node in the current
            // k nodes. In this case, new prev-group will be node 1
            // Besides, we also want the first node (last node after                     // reverse) to point to the
            // first node in the next k nodes, which is next_group
            // since every time we change what cur_node points to 
            // i.e cur_node->next, we need to store the original next
            // in a variable to make sure the loop works as expected
            ListNode* cur_node = prev_group->next;
            ListNode* prev_node = kth_node->next;
            ListNode* next_group = kth_node->next;
            
            while (cur_node != next_group) {
                ListNode* temp = cur_node->next;
                cur_node->next = prev_node;
                prev_node = cur_node;
                cur_node = temp;
            }
            
            ListNode* temp = prev_group->next; // this becomes prev_group later
            prev_group->next = kth_node;
            prev_group = temp;
        }
        return dummy.next;
    }
    ListNode* findKth(ListNode* cur_node, int k) {
        while (cur_node && k > 0) {
            cur_node = cur_node->next;
            k--;
        }
        return cur_node;
    }
};

/*
Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Example 3:
Input: head = [1,2,3,4,5], k = 1
Output: [1,2,3,4,5]

Example 4:
Input: head = [1], k = 1
Output: [1]

Time: O(N)
*/
