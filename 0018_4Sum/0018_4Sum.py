"""
Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.

Notice that the solution set must not contain duplicate quadruplets.
"""

class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        
        def two_sum(start, two_sum_target):
            ret = []
            i = start
            j = len(nums) - 1
            while i < j:
                total = nums[i] + nums[j]
                if total > two_sum_target or (j < len(nums) - 1 and nums[j] == nums[j+1]):
                    j -= 1
                elif total < two_sum_target or (i > start and nums[i] == nums[i-1]):
                    i += 1
                else:
                    ret.append([nums[i], nums[j]])
                    i += 1
                    j -= 1
            return ret

            
        def ksum(start, k, k_sum_target):
            ret = []
            if len(nums[start:]) == 0 or nums[start] * k > k_sum_target or nums[-1] * k < k_sum_target:
                return ret
            if k == 2:
                return two_sum(start, k_sum_target)
            else:
                for i in range(start, len(nums)):
                    if i > start and nums[i] == nums[i-1]:
                        continue
                    for my_set in ksum(i+1, k-1, k_sum_target-nums[i]):
                        ret.append([nums[i]] + my_set)
                
            return ret
        
        nums = sorted(nums)
        return ksum(0, 4, target)

"""
Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
Input: nums = [], target = 0
Output: []

Time: O(n^k-1)
"""
