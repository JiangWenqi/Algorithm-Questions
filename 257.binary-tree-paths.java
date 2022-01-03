import java.util.LinkedList;
import java.util.List;
import java.util.Stack;

/*
 * @lc app=leetcode id=257 lang=java
 *
 * [257] Binary Tree Paths
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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> ans = new LinkedList<>();
        if (root != null) {
            buildString(root, "", ans);
        }
        return ans;
    }

    private void buildString(TreeNode node, String sb, List<String> ans) {
        if (node.left == null && node.right == null) {
            ans.add(sb + node.val);
        }
        if (node.left != null) {
            buildString(node.left, sb + node.val + "->", ans);
        }
        if (node.right != null) {
            buildString(node.right, sb + node.val + "->", ans);
        }
    }
}
// @lc code=end
