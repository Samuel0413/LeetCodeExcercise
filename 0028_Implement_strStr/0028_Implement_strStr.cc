/*
Implement strStr().

Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

Clarification:

What should we return when needle is an empty string? This is a great question to ask during an interview.

For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().
*/

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int index = -1;
        for (int i = 0; i + needle.length() <= haystack.length(); i++) {
            if (haystack.substr(i, needle.length()) == needle) {
                index = i;
                break;
            }
        }
        return index;
    }
};

// if cannot use substr
/*
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.length() == 0) return 0;
        int index = -1;
        for (int i = 0; i + needle.length() - 1 < haystack.length(); i++) {
            int j=i, k=0;
            while (j < haystack.length() && k < needle.length() && haystack[j]==needle[k]) {
                j++;
                k++;
            }
            if (k == needle.length()) {
                return i;
            }
        }
        return index;
    }  
};
*/

/*
Example 1:
Input: haystack = "hello", needle = "ll"
Output: 2

Example 2:
Input: haystack = "aaaaa", needle = "bba"
Output: -1

Example 3:
Input: haystack = "", needle = ""
Output: 0

Time: O(n)
Space: O(1)
*/
