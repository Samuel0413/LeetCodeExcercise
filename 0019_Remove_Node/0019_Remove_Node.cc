/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *cur_node = head;
        vector<ListNode *> cache = {};
        while (cur_node != nullptr) {
            cache.push_back(cur_node);
            cur_node = cur_node->next;
        }
        if (cache.size() != n) {
            cache[cache.size() - n - 1]->next = cache[cache.size() - n]->next;
        } else {
            return cache[0]->next;
        }
        return cache[0];
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
