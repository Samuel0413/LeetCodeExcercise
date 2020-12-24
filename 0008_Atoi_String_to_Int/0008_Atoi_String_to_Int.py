"""
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
"""

class Solution(object):
    def myAtoi(self, s):
        """
        :type s: str
        :rtype: int
        """
        num_start = False
        ret_num = ""
        is_positive = True
        for i in range(len(s)):
            cur_char = s[i]
            if num_start == False:
                if cur_char == ' ':
                    continue
                elif cur_char == '-':
                    num_start = True
                    is_positive = False
                elif cur_char == '+':
                    num_start = True
                elif cur_char.isdigit():
                    num_start = True
                    ret_num += cur_char
                elif not cur_char.isdigit():
                    return 0
            else:
                if cur_char.isdigit():
                    ret_num += cur_char
                else:
                    break
                    
        if ret_num == "":
            return 0
        
        if is_positive:
            ret_num = int(ret_num)
        else:
            ret_num = -1 * int(ret_num)
        
        if ret_num >= 2**31 - 1:
            return 2**31 - 1
        elif ret_num <= -2**31:
            return -2**31
        else:
            return ret_num

"""
Example 1:

Input: str = "42"
Output: 42

Example 2:

Input: str = "   -42"
Output: -42

Example 3:

Input: str = "4193 with words"
Output: 4193

Example 4:

Input: str = "words and 987"
Output: 0

Example 5:

Input: str = "-91283472332"
Output: -2147483648

Time: O(n) (n is the length of the string)
"""
