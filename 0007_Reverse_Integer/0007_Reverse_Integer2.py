"""
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
"""

class Solution:
    def reverse(self, x: int) -> int:
        if x >= 0:
            ret_num = int(str(x)[::-1])
        else:
            ret_num = int("-" + str(x)[1:][::-1])
            
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
