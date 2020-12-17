/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"
*/

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string ret = "";
        int one_set_num = 2 * numRows - 2;
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; i + j < s.length(); j += one_set_num) {
                ret += s[i + j];
                if (i != 0 && i != numRows - 1 && one_set_num - i + j < s.length()) {
                    ret += s[(one_set_num - i) + j];
                }
            }
        }
        return ret;
    }
};

/*
Example 1:

Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:

Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I

Example 3:

Input: s = "A", numRows = 1
Output: "A"
*/
