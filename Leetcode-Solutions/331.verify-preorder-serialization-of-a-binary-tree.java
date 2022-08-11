import java.util.Stack;

/*
 * @lc app=leetcode id=331 lang=java
 *
 * [331] Verify Preorder Serialization of a Binary Tree
 */

// @lc code=start
class Solution {
    public boolean isValidSerialization(String preorder) {
        if (preorder == null) {
            return false;
        }

        Stack<String> stack = new Stack<>();
        String[] nodes = preorder.split(",");

        for (int i = 0; i < nodes.length; i++) {

            String curr = nodes[i];
            while (curr.equals("#") && !stack.isEmpty() && stack.peek().equals(curr)) {
                stack.pop();
                if (stack.isEmpty()) {
                    return false;
                }
                stack.pop();
            }
            stack.push(curr);
            System.out.println(stack.toString());
        }

        return stack.size() == 1 && stack.peek().equals("#");
    }
}
// @lc code=end
