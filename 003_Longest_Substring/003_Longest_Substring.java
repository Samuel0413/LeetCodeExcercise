/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
    public int lengthOfLongestSubstring(String s) {
        HashMap<Character, Integer> set = new HashMap<Character, Integer>();
        int length = s.length();
        int start = 0;
        int max_ans = 0;
        for (int j = 0; j < length; j++) {
            if (set.containsKey(s.charAt(j))) {
                start = Math.max(start, set.get(s.charAt(j))+1);
            }
            max_ans = Math.max(max_ans, j - start + 1);
            set.put(s.charAt(j), j);
        }
        return max_ans;
    }
}

/* Test
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
*/
