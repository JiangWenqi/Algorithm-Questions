import java.util.Stack;

/*
 * @lc app=leetcode id=227 lang=java
 *
 * [227] Basic Calculator II
 */

// @lc code=start
class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();

        int current = 0;
        char lastOperation = '+';
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (Character.isDigit(c)) {
                current = current * 10 + c - '0';
            }
            if (!Character.isDigit(c) && !Character.isWhitespace(c) || i == s.length() - 1) {
                switch (lastOperation) {
                    case '+':
                        stack.push(current);
                        break;
                    case '-':
                        stack.push(-current);
                        break;
                    case '*':
                        stack.push(stack.pop() * current);
                        break;
                    case '/':
                        stack.push(stack.pop() / current);
                        break;
                }
                lastOperation = c;
                current = 0;
            }

        }

        int sum = 0;
        for (Integer integer : stack) {
            sum += integer;
        }
        return sum;
    }
}
// @lc code=end
