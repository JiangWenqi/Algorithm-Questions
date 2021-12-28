import java.util.Stack;

/*
 * @lc app=leetcode id=71 lang=java
 *
 * [71] Simplify Path
 */

// @lc code=start
class Solution {
    public String simplifyPath(String path) {
        Stack<String> stack = new Stack<>();
        for (String str : path.split("/")) {
            if (str.equals("..") && !stack.isEmpty()) {
                stack.pop();
            } else if (!str.equals("..") && !str.equals(".") && !str.equals("")) {
                stack.push(str);
            }
        }

        return "/"+String.join("/", stack);
    }
}
// @lc code=end
