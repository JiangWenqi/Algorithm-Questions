import java.util.Stack;

/*
 * @lc app=leetcode id=682 lang=java
 *
 * [682] Baseball Game
 */

// @lc code=start
class Solution {
    public int calPoints(String[] ops) {
        Stack<Integer> stack = new Stack<>();
        for (String op : ops) {
            switch (op) {
                case "+":
                    int x = stack.peek();
                    int y = stack.get(stack.size() - 2);
                    stack.push(x + y);
                    break;
                case "D":
                    stack.push(2 * stack.peek());
                    break;
                case "C":
                    stack.pop();
                    break;
                default:
                    stack.push(Integer.parseInt(op));
            }
        }

        int sum = 0;
        for (Integer number : stack) {
            sum += number;
        }
        return sum;
    }
}
// @lc code=end
