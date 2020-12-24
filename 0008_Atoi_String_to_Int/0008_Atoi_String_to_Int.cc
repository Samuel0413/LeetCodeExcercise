/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered a whitespace character.
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. If the numerical value is out of the range of representable values, 231 − 1 or −231 is returned.
*/

class Solution {
public:
    int myAtoi(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int i = 0;
        int result = 0;
        bool is_positive = true;
        
        while (i < s.length() && s[i] == ' ') {
            // ignore the starting space
            i++;
        }
        
        if (i < s.length() && (s[i] == '-' || s[i] == '+')) {
            is_positive = (s[i++] == '-') ? false : true;
        }
        
        while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
            if (result > INT_MAX / 10 ||
               (result == INT_MAX / 10 && s[i] - '0' > INT_MAX % 10)) {
                return (is_positive) ? INT_MAX : INT_MIN;
            }
            result = 10 * result + (s[i++] - '0');
        }
        return (is_positive) ? result : -1 * result;
    }
};

/*
Example 1:

Input: str = "42"
Output: 42

Example 2:

Input: str = "   -42"
Output: -42

Example 3:

Input: str = "4193 with words"
Output: 4193

Example 4:

Input: str = "words and 987"
Output: 0

Example 5:

Input: str = "-91283472332"
Output: -2147483648

Time: O(n) (n is the length of the string)
*/
