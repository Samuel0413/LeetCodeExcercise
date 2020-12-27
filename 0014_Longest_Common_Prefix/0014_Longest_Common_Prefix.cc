/*
This is the vertical comparison version
Write a function to find the longest common prefix string amongst an array of strings.
*/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0) return "";
        for (int i = 0; i < strs.at(0).length(); i++) {
            char cur_char = strs.at(0)[i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs.at(j)[i] != cur_char || i > strs.at(j).length() - 1) {
                    return strs.at(0).substr(0, i);
                }
            }
        }
        return strs.at(0);
    }
};

/*
Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""

Time: O(n) (n is the sum of all chars in all strings)
*/
