// Given a string containing just the characters '(' and ')', find the // length of the longest valid (well-formed) parentheses substring.

// Idea: Keep track of a stack to check if valid and use it for // calculation. When  encounter (, we push its position to the stack
// When encounter ), we pop from stack, if stack is not empty, we // calculate the current length and compare with the max. Otherwise if 
// stack is empty, we push position of ) in it, indicate that valid
// continguous parentheses have been stopped and we need to start
// our calculation again.
// In order to calculate the length properly, initially, we push -1
// into the stack. This can be treated as dummy value.

int longestValidParentheses(char * s){
    
    // dp[i][j] = # number of valid parentheses in s[i...j]
    if (sizeof(s) <= 1) return 0;
    
    int n = strlen(s);
    
    // stack[] stores position of (
    int *stack = (int *) malloc((n + 1) * sizeof(int));
    for (int i = 0; i < n; i++) stack[i] = -1;
   
    int top = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stack[++top] = i;
        } else {
            top--;
            if (top < 0) {
                stack[0] = i;
                top = 0;
            } else {
                ans = (i - stack[top] > ans ? i - stack[top] : ans);
            }
        }
    }
    
    free(stack);
    return ans;
    
}