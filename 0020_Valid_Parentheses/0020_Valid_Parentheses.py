"""
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
"""

class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        cache = []
        for ele in s:
            if ele in ["(", "[", "{"]:
                #print(ele)
                cache.append(ele)
            else:
                if len(cache) == 0:
                    return False
                if (ele == ")" and cache[-1] != "(") or (ele == "]" and cache[-1] != "[") or (ele == "}" and cache[-1] != "{"):
                    return False
                else:
                    cache.pop()
        return True if len(cache) == 0 else False

"""
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true

Example 6:
Input: s = "]"
Output: false

Time: O(n)
"""
