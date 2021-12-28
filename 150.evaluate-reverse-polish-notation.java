import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;
import java.util.Stack;

/*
 * @lc app=leetcode id=150 lang=java
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
    public int evalRPN(String[] tokens) {
        Stack<Integer> stack = new Stack<>();
        for (String token : tokens) {
            switch (token) {
                case "+":
                    int sum = stack.pop() + stack.pop();
                    stack.push(sum);
                    break;
                case "-":
                    int diff = stack.pop() - stack.pop();
                    stack.push(-diff);
                    break;
                case "*":
                    int product = stack.pop() * stack.pop();
                    stack.push(product);
                    break;
                case "/":
                    int divisor = stack.pop();
                    int dividend = stack.pop();
                    stack.push(dividend / divisor);
                    break;
                default:
                    stack.push(Integer.parseInt(token));
            }
        }
        return stack.peek();
    }
}
// @lc code=end
