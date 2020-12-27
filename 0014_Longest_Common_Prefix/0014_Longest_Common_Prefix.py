"""
This is the horizontal comparison version
Write a function to find the longest common prefix string amongst an array of strings.
"""

class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        if len(strs) == 0:
            return ""
        prefix = strs[0]
        for string in strs[1:]:
            while string[:len(prefix)] != prefix and prefix:
                prefix = prefix[:len(prefix) - 1]
                if not prefix:
                    return ""
        return prefix

"""
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""

Time: O(n) (n is the sum of all chars in all strings)
"""
