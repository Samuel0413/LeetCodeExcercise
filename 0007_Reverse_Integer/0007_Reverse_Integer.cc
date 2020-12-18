/*
Given a 32-bit signed integer, reverse digits of an integer.

Note:
Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/

class Solution {
public:
    int reverse(int x) {
        int ret = 0;
        while (x != 0) {
            int pop = x % 10;
            if (ret > INT_MAX / 10 || (ret == INT_MAX / 10 && pop > 7)) {
                return 0;
            }
            if (ret < INT_MIN / 10 || (ret == INT_MIN / 10 && pop < -8)) {
                return 0;
            }
            ret = 10 * ret + pop;
            x = x / 10;
        }
        return ret;
    }
};

/*
Time: O(log(n)) (n is the input number)
Space: O(1)
*/

/*
Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

Example 4:

Input: x = 0
Output: 0
*/
