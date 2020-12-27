/*
Convert decimal number to roman number
*/

class Solution {
private:
    string addsOn(int num, string target) {
        string ret = "";
        for (int i = 0; i < num; i++) {
            ret += target;
        }
        return ret;
    }
    
public:
    string intToRoman(int num) {
        string ret_num = "";
        if (num / 1000 != 0) {
            ret_num += addsOn(num / 1000, "M");
            num %= 1000;
        }
        if (num / 900 != 0) {
            ret_num += "CM";
            num %= 900;
        }
        if (num / 500 != 0) {
            ret_num += "D";
            num %= 500;
        }
        if (num / 400 != 0) {
            ret_num += "CD";
            num %= 400;
        }
        if (num / 100 != 0) {
            ret_num += addsOn(num / 100, "C");
            num %= 100;
        }
        if (num / 90 != 0) {
            ret_num += "XC";
            num %= 90;
        }
        if (num / 50 != 0) {
            ret_num += "L";
            num %= 50;
        }
        if (num / 40 != 0) {
            ret_num += "XL";
            num %= 40;
        }
        if (num / 10 != 0) {
            ret_num += addsOn(num / 10, "X");
            num %= 10;
        }
        if (num / 9 != 0) {
            ret_num += "IX";
            num %= 9;
        }
        if (num / 5 != 0) {
            ret_num += "V";
            num %= 5;
        }
        if (num / 4 != 0) {
            ret_num += "IV";
            num %= 4;
        }
        ret_num += addsOn(num, "I");
        return ret_num;
    }
};

/*
Example 1:
Input: num = 3
Output: "III"

Example 2:
Input: num = 4
Output: "IV"

Example 3:
Input: num = 9
Output: "IX"

Example 4:
Input: num = 58
Output: "LVIII"

Example 5:
Input: num = 1994
Output: "MCMXCIV"

Time: O(1) (n is the number of all indices of the input number)
*/
