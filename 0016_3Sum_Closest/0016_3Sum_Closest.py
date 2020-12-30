"""
Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
"""

class Solution(object):
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums = sorted(nums)
        closest_so_far = nums[0] + nums[1] + nums[2]
        for i in range(len(nums)):

            # do not want to count all the duplicates except the first appearance of such number, save run time!
            if i > 0 and nums[i] == nums[i-1]:
                continue

            left = i+1
            right = len(nums) - 1

            while left < right:
                total = nums[i] + nums[left] + nums[right]
                if total > target:
                    right -= 1
                elif total < target:
                    left += 1
                else:
                    return total
                
                # updates the value of closest_so_far if total is closer to target
                if abs(total - target) < abs(closest_so_far - target):
                    closest_so_far = total

        return closest_so_far

"""
Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Example 2:
Input: nums = [-1,0,0,0,0,1], target = 0
Output: 2

Time: O(n^2)
"""
