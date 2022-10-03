import java.util.HashMap;

/*
 * @lc app=leetcode id=437 lang=java
 *
 * [437] Path Sum III
 *
 * https://leetcode.com/problems/path-sum-iii/description/
 *
 * algorithms
 * Medium (48.94%)
 * Likes:    8672
 * Dislikes: 413
 * Total Accepted:    410.8K
 * Total Submissions: 839.4K
 * Testcase Example:  '[10,5,-3,3,2,null,11,3,-2,null,1]\n8'
 *
 * Given the root of a binary tree and an integer targetSum, return the number
 * of paths where the sum of the values along the path equals targetSum.
 * 
 * The path does not need to start or end at the root or a leaf, but it must go
 * downwards (i.e., traveling only from parent nodes to child nodes).
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: root = [10,5,-3,3,2,null,11,3,-2,null,1], targetSum = 8
 * Output: 3
 * Explanation: The paths that sum to 8 are shown.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
 * Output: 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * The number of nodes in the tree is in the range [0, 1000].
 * -10^9 <= Node.val <= 10^9
 * -1000 <= targetSum <= 1000
 * 
 * 
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
    int res = 0;
    HashMap<Long, Integer> counter = new HashMap<>();

    private void dfs(TreeNode node, int targetSum, long currentSum) {
        if (node == null)
            return;
        currentSum += node.val;
        if (counter.containsKey(currentSum - targetSum)) {
            res += counter.get(currentSum - targetSum);
        }
        counter.put(currentSum, counter.getOrDefault(currentSum, 0) + 1);
        dfs(node.left, targetSum, currentSum);
        dfs(node.right, targetSum, currentSum);
        counter.put(currentSum, counter.get(currentSum) - 1);
    }

    public int pathSum(TreeNode root, int targetSum) {
        counter.put(0l, 1);
        dfs(root, targetSum, 0);
        return res;
    }
}
// @lc code=end
