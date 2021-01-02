"""
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.
"""

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeKLists(self, lists):
        """
        :type lists: List[ListNode]
        :rtype: ListNode
        """
        if len(lists) == 0:
            return None
        if len(lists) == 1:
            return lists[0]
        
        def merge2Lists(list1, list2):
            head = ListNode(0)
            cur_node = head
            while list1 and list2:
                if list1.val <= list2.val:
                    cur_node.next = list1
                    list1 = list1.next
                else:
                    cur_node.next = list2
                    list2 = list2.next
                cur_node = cur_node.next
            if list1:
                cur_node.next = list1
            if list2:
                cur_node.next = list2
            return head.next
        
        if len(lists) == 2:
            return merge2Lists(lists[0], lists[1])
        else:
            total = len(lists)
            interval = 1
            while interval < total:
                for i in range(0, total-interval, interval*2):
                    lists[i] = merge2Lists(lists[i], lists[i+interval])
                interval *= 2
            return lists[0]

"""
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

Time: O(N*logk) 
(N is the total length of two lists that are passed to merge2Lists function, k is the length of the input lists)
Note that log is based 2 since interval is updated by multiplying 2 every time
"""
