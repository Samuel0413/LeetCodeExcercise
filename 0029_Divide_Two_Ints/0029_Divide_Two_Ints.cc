/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
*/

// use the idea of the magnitude of a/b = e^(ln(|dividend/divisor|)) = e^(ln(|dividend|) - ln(|divisor|))

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) return 0;
        long long ans = double(exp(log(fabs(dividend)) - log(fabs(divisor))));
        // bitwise xor
        if ((dividend < 0) ^ (divisor < 0)) {
            return -1*ans;
        }
        if (ans > INT_MAX) {
            return INT_MAX;
        }
        return ans;
    }
};

/*
Example 1:
Input: dividend = 10, divisor = 3
Output: 3
Explanation: 10/3 = truncate(3.33333..) = 3.

Example 2:
Input: dividend = 7, divisor = -3
Output: -2
Explanation: 7/-3 = truncate(-2.33333..) = -2.

Example 3:
Input: dividend = 0, divisor = 1
Output: 0

Example 4:
Input: dividend = 1, divisor = 1
Output: 1
*/
