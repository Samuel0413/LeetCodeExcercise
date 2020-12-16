"""
Given a string s, return the longest palindromic substring in s.
"""

class Solution(object):

     
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        def expandFromCenter(s,l,r):
            while (l >= 0 and r < len(s) and s[l] == s[r]):
                l -= 1
                r += 1
            return r - l - 1
        
        if (s == None or len(s) < 1):
            return ""
        start, end = 0, 0
        i = 0
        while (i < len(s)):
            len1 = expandFromCenter(s, i, i)
            len2 = expandFromCenter(s, i, i+1)
            len_f = max(len1, len2)
            if (len_f > end - start):
                start = i - (len_f - 1) / 2
                end = i + len_f / 2
            i += 1
        return s[start:end+1]

"""
Example 1:

Input: s = "babad"
Output: "bab"
Note: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
Example 3:

Input: s = "a"
Output: "a"
Example 4:

Input: s = "ac"
Output: "a"

Some testcases:
"ccc"
"cccc"
"""
