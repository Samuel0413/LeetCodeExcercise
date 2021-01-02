"""
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
"""

class Solution(object):
    def generateParenthesis(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        ret = []
        def generate(s = "", front = 0, back = 0):
            if len(s) == n*2:
                ret.append(s)
            else:
                if front < n:
                    generate(s+'(', front+1, back)
                if back < front:
                    generate(s+')', front, back+1)
        
        generate()
        return ret

"""
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]
"""
