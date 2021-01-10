"""
Given an array nums and a value val, remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed. It doesn't matter what you leave beyond the new length.
"""

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        ## imagine count is the index of a new array
        ## where you put all non target val element
        ## from nums
        ## increment count by 1 only if the current
        ## element int nums is not target val
        count = 0
        for i in range(len(nums)):
            if nums[i] != val:
                nums[count] = nums[i]
                count += 1
        return count

"""
Example 1:
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2]

Example 2:
Input: nums = [0,1,2,2,3,0,4,2], val = 2
Output: 5, nums = [0,1,4,0,3]

Time: O(n)
Space: O(1)
"""
