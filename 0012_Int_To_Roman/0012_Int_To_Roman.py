"""
Convert number into Roman number
"""

class Solution(object):
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        def addsOn(num, key):
            ret = ""
            for i in range(num):
                ret += key
            return ret
        
        ret = ""
        my_chart = {1000:"M", 900:"CM", 500:"D", 400:"CD", 100:"C", 90:"XC", 
                    50:"L", 40:"XL", 10:"X", 9:"IX", 5:"V", 4:"IV", 1:"I"}
        for k in sorted(my_chart.keys(), reverse=True):
            if num / k > 0:
                ret += addsOn(num / k, my_chart[k])
                num = num % k
        return ret

"""
Example 1:
Input: num = 3
Output: "III"

Example 2:
Input: num = 4
Output: "IV"

Example 3:
Input: num = 9
Output: "IX"

Example 4:
Input: num = 58
Output: "LVIII"

Example 5:
Input: num = 1994
Output: "MCMXCIV"

Time: O(n) (n is the number of all indices of the input number)
"""
