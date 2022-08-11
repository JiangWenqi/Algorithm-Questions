import java.util.Stack;

import javax.swing.tree.TreeNode;

/*
 * @lc app=leetcode id=897 lang=java
 *
 * [897] Increasing Order Search Tree
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 * int val;
 * TreeNode left;
 * TreeNode right;
 * TreeNode() {}
 * TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) {
 * this.val = val;
 * this.left = left;
 * this.right = right;
 * }
 * }
 */
class Solution {
    List<Integer> temp = new ArrayList<>();

    public TreeNode increasingBST(TreeNode root) {
        inorder(root);
        TreeNode dummy = new TreeNode(0);
        TreeNode curr = dummy;
        for (Integer x : temp) {
            curr.right = new TreeNode(x);
            curr = curr.right;
        }
        return dummy.right;
    }

    public void inorder(TreeNode root) {
        if (root != null) {
            inorder(root.left);
            temp.add(root.val);
            inorder(root.right);
        }
    }
}
// @lc code=end
