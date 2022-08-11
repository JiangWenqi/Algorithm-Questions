import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=98 lang=java
 *
 * [98] Validate Binary Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    /*
     * public boolean isValidBST(TreeNode root) {
     * Stack<TreeNode> stack = new Stack<>();
     * TreeNode pre = null;
     * 
     * while (root != null || !stack.isEmpty()) {
     * while (root != null) {
     * stack.push(root);
     * root = root.left;
     * }
     * root = stack.pop();
     * if (pre != null && root.val <= pre.val) {
     * return false;
     * }
     * pre = root;
     * root = root.right;
     * }
     * return true;
     * }
     * 
     */

    private boolean isValidBST(long below, long up, TreeNode node) {
        if (node == null)
            return true;
        else if (node.val >= up || node.val <= below)
            return false;
        else
            return isValidBST(below, node.val, node.left) && isValidBST(node.val, up, node.right);
    }

    public boolean isValidBST(TreeNode root) {
        return isValidBST(Long.MIN_VALUE, Long.MAX_VALUE, root);
    }

}
// @lc code=end
