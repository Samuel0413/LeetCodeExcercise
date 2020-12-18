"""
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""

class Solution(object):
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        i = 0
        cur_num = x if x > 0 else -x
        #ret_num_set = []
        ret_num = 0
        neg = False if x > 0 else True
        
        while cur_num != 0:
            ret_num = ret_num * 10 + cur_num % 10
            cur_num = cur_num / 10
        
            
        ret_num = -1 * ret_num if neg == True else ret_num
        
        if not (ret_num >= -1 * 2**31 and ret_num <= 2**31 - 1):
            return 0
        
        return ret_num
            
            
"""
Time: O(log(n)) (n is the input number)
Space: O(1)
"""

"""
Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0
"""
