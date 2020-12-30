/*
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

my_chart = {'2': ['a', 'b', 'c'],
            '3': ['d', 'e', 'f'],
            '4': ['g', 'h', 'i'],
            '5': ['j', 'k', 'l'],
            '6': ['m', 'n', 'o'],
            '7': ['p', 'q', 'r', 's'],
            '8': ['t', 'u', 'v'],
            '9': ['w', 'x', 'y', 'z']}
*/

class Solution {
public:
    
    map<char, string> my_chart {{'2', "abc"}, {'3',"def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
    
    vector<string> output;
    
    void combine(string combination, string next_digits) {
        // if there is no more digits
        if (next_digits.length() == 0) {
            output.push_back(combination);
        } else {
            char cur_digit = next_digits[0];
            string letters = my_chart[cur_digit];
            for (int i = 0; i < letters.length(); i++) {
                string cur_letter = letters.substr(i, 1);
                combine(combination + cur_letter, next_digits.substr(1));
            }
        }
    }
    
    vector<string> letterCombinations(string digits) {
        if (digits.length() != 0) {
            combine("", digits);
        }
        return output;
    }
};

/*
Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]
*/
