"""

"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        if head == None:
            return None
        if head.next == None:
            return head
        
        dummy = ListNode(0, head)
        prev_node = dummy
        cur_node = dummy.next
        next_node = cur_node.next
        while cur_node and next_node:
            # swap the pair
            next_pair = next_node.next
            cur_node.next = next_pair
            next_node.next = cur_node
            
            # change what prev points to assure the order,
            # since next_node is ahead of cur_node
            # prev next should be next_node istead of cur_node
            prev_node.next = next_node
            
            # update nodes
            prev_node = cur_node
            cur_node = next_pair
            next_node = cur_node.next if cur_node else None
            
        return dummy.next

"""
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
"""
