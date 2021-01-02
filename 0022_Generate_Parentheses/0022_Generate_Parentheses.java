/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
*/

class Solution {
    private void generate(int left, int right, String s, List<String> ret, int n) {
        if (s.length() == n * 2) {
            ret.add(s);
            return;
        }
        if (left < n) generate(left+1, right, s+'(', ret, n);
        if (right < left) generate(left, right+1, s+')', ret, n);
    }
    
    public List<String> generateParenthesis(int n) {
        List<String> ret = new ArrayList();
        generate(0, 0, "", ret, n);
        return ret;
    }
}

/*
Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Example 2:
Input: n = 1
Output: ["()"]

Space: O(n)
*/
