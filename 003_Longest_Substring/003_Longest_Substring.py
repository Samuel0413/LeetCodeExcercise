"""
Given a string s, find the length of the longest substring without repeating characters.
"""

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        ret = 0
        # myset is a disctionary that stores index of a char
        myset = {}
        length = len(s)
        i = 0
        for j in range(length):
            if s[j] in myset:
                # use max here so that i won't go back to a small place
                # Example: "abba"
                i = max(myset[s[j]]+1, i)
                
            ret = max(ret, j - i + 1)
            myset[s[j]] = j
            
        return ret

"""
Test
Example 1:

Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
Example 4:

Input: s = ""
Output: 0
"""
