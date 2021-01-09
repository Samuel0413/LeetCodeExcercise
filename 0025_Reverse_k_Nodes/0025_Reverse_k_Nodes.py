"""
Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

Follow up:

Could you solve the problem in O(1) extra memory space?
You may not alter the values in the list's nodes, only nodes itself may be changed.
"""

class Solution(object):
    def reverseKGroup(self, head, k):
        """
        :type head: ListNode
        :type k: int
        :rtype: ListNode
        """
        dummy = ListNode(0, head)
        prev_group = dummy
        
        while True:
            kth_node = self.find_kth(prev_group, k)
            if not kth_node:
                break
            
            next_group = kth_node.next
            cur_node = prev_group.next
            prev_node = next_group
            
            while cur_node != next_group:
                temp_node = cur_node.next
                cur_node.next = prev_node
                prev_node = cur_node
                cur_node = temp_node
                
            temp_node = prev_group.next
            prev_group.next = kth_node
            prev_group = temp_node
        
        return dummy.next

    
    def find_kth(self, cur, k):
        while k > 0 and cur:
            cur = cur.next
            k -= 1
        return cur

"""
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
"""
