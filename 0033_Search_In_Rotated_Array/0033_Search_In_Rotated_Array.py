"""
You are given an integer array nums sorted in ascending order (with distinct values), and an integer target.

Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

If target is found in the array return its index, otherwise, return -1.
"""

class Solution(object):
    def search(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        # brute force
        """
        index = -1
        for i, num in enumerate(nums):
            if num == target:
                index = i
                break
        return index
        """
        
        # binary search
        length = len(nums)
        left = 0
        right = length - 1
        while left <= right:

            middle = (left+right) // 2
            
            if nums[middle] == target:
                return middle
            
            if nums[left] == target:
                return left
            
            if nums[right] == target:
                return right
            
            if nums[middle] > nums[left]:
                if target < nums[middle] and target > nums[left]:
                    right = middle - 1
                else:
                    left = middle + 1
                    
            else:
                if target > nums[middle] and target < nums[right]:
                    left = middle + 1
                else:
                    right = middle - 1
                    
        return -1

"""
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1

Time: O(log(n))
"""
