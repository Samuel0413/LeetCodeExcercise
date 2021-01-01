"""
Given the head of a linked list, remove the nth node from the end of the list and return its head.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def removeNthFromEnd(self, head, n):
        """
        :type head: ListNode
        :type n: int
        :rtype: ListNode
        """
        cur_node = head
        cache = []
        while cur_node != None:
            cache.append(cur_node)
            cur_node = cur_node.next
        if len(cache) != n:
            cache[len(cache) - n - 1].next = cache[len(cache) - n].next
        else:
            return cache[0].next
        return cache[0]

"""
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
"""
