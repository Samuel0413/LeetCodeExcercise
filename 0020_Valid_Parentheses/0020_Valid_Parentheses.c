/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
*/

bool isValid(char * s) {
    const size = strlen(s);
    char *stack = malloc(sizeof(*stack) * size);
    int counter = 0;
    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[counter] = s[i];
            counter++;
        } else {
            if (counter == 0) {
                return false;
            }
            if ((s[i] == ')' && stack[counter-1] == '(') ||
                (s[i] == ']' && stack[counter-1] == '[') ||
                (s[i] == '}' && stack[counter-1] == '{')) {
                counter--;
            } else {
                return false;
            }
        } 
    }
    free(stack);
    return counter == 0;
}

/*
Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false

Example 4:
Input: s = "([)]"
Output: false

Example 5:
Input: s = "{[]}"
Output: true

Example 6:
Input: s = "]"
Output: false

Time: O(n)
*/
