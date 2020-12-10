/*
Given a string s, find the length of the longest substring without repeating characters.
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0;
        string cur_string = "";
        //set<char> set;
        int i = 0;
        int j = 0;
        int length = s.length();
        while (i < length && j < length) {
            int index = cur_string.find(s[j]);
            if (!(index < cur_string.length())) {
                cur_string += s[j++];
                ret = max(ret, j-i);
            } else {
                cur_string = cur_string.substr(index+1);
                i = i + index + 1;
            }
            //cout<<cur_string<<endl;
        }
        return ret;
        /*while (i < s.length()) {
            if (cur_string.find(s[i]) < s.length()) {
                if (cur_string.length() > max) {
                    max = cur_string.length();
                }
                cur_string = cur_string.substr(cur_string.find(s[i])+1) + s[i];
            } else {
                cur_string += s[i];
            }
            cout << cur_string << endl;
            i++;
        }
        if (cur_string.length() > max) { return cur_string.length(); }
        return max;*/
    }
};

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
