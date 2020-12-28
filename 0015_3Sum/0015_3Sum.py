"""
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Notice that the solution set must not contain duplicate triplets.
"""

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        if len(nums) < 3:
            return []
        else:
            nums = sorted(nums)
            ret = []
            for i in range(len(nums) - 1):
                if nums[i] > 0:
                    break
                if i > 0 and nums[i] == nums[i-1]:
                    continue
                    
                j = i + 1
                k = len(nums) - 1
                while j < k:
                    total_sum = nums[i] + nums[j] + nums[k]
                    if total_sum > 0:
                        k -= 1
                    elif total_sum < 0:
                        j += 1
                    else:
                        ret.append([nums[i], nums[j], nums[k]])
                        j += 1
                        while nums[j] == nums[j-1] and j < k:
                            j +=1
            return ret

"""
Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]

Example 2:
Input: nums = []
Output: []

Example 3:
Input: nums = [0]
Output: []

Time: O(N^2)
"""
