"""
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
"""

class Solution(object):

    
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        
        merged_nums = []
        i, j = 0, 0
        l1, l2 = len(nums1), len(nums2)
        while i < l1 and j < l2:
            num1 = nums1[i]
            num2 = nums2[j]
            if num1 == num2:
                merged_nums.append(num1)
                i = i + 1
            elif num1 < num2:
                merged_nums.append(num1)
                i = i + 1
            else:
                merged_nums.append(num2)
                j = j + 1
        if i == l1 and j != l2:
            merged_nums = merged_nums + nums2[j:]
        if j == l2 and i != l1:
            merged_nums = merged_nums + nums1[i:]
        mid_point = len(merged_nums) // 2
        print(merged_nums)
        print(len(merged_nums) % 2 == 0)
        print(mid_point)
        if (len(merged_nums) % 2) == 0:
            #if it is even length need to sum the left one and divide by 2
            print
            median = (merged_nums[mid_point] + merged_nums[mid_point-1]) / 2.0
        else:
            median = merged_nums[mid_point]
            
        return median

"""
Example 1:

Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:

Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.

Example 3:

Input: nums1 = [0,0], nums2 = [0,0]
Output: 0.00000

Example 4:

Input: nums1 = [], nums2 = [1]
Output: 1.00000

Example 5:

Input: nums1 = [2], nums2 = []
Output: 2.00000
"""
