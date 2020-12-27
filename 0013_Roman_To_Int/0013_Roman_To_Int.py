"""
Convert Roman number to decimal number
"""

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret_num = 0
        my_chart = {"M":1000, "CM":900, "D":500, "CD":400, "C":100, "XC":90,
                  "L":50, "XL":40, "X":10, "IX":9, "V":5, "IV":4, "I":1}
        for i in range(len(s) - 1):
            if my_chart[s[i]] >= my_chart[s[i+1]]:
                ret_num += my_chart[s[i]]
            else:
                # if left < right, we can minus left and add right to get numbers such as
                # 4, 9, 40, 90 etc.
                ret_num -= my_chart[s[i]]
        ret_num += my_chart[s[len(s)-1]]
        return ret_num

"""
Example 1:
Input: s = "III"
Output: 3

Example 2:
Input: s = "IV"
Output: 4

Example 3:
Input: s = "IX"
Output: 9

Example 4:
Input: s = "LVIII"
Output: 58

Example 5:
Input: s = "MCMXCIV"
Output: 1994

Time: O(n)
"""
